#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QGridLayout>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMenuBar>

#include <QTableWidgetItem>
#include "datadef.h"
#include "utils.h"
#include "imagewidget.h"

void fileClear(QFile& file){
    file.open(QFile::WriteOnly | QFile::Truncate);
    file.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // central widget
    test_widget = new DrawWidget;
    temp_widget = new ImageWidget;
    btn_save = new  QPushButton(tr("save"));
    btn_prev = new QPushButton(tr("previous"));
    btn_next = new QPushButton(tr("next"));
    btn_open_filelist = new QPushButton(tr("open"));
    btn_return = new QPushButton(tr("return"));
    btn_save->setShortcut(QKeySequence::Save);

    lbl_current_name = new QLabel(tr("current file:"));
    lbl_filelist_path = new QLabel(tr("filelist:"));

    QLabel* lbl_temp_info = new QLabel(tr("template image"));
    QLabel* lbl_test_info = new QLabel(tr("tested image"));
    tb_info = new QTableWidget();
    tb_info->setMaximumSize(240, 640);
    tb_info->setMinimumSize(240, 640);
    QGridLayout* grid = new QGridLayout;
    grid->addWidget(lbl_filelist_path, 0 ,0, 1, 4);
    grid->addWidget(btn_open_filelist, 0 ,5);

    grid->addWidget(btn_prev, 0 ,6, 1, 1);
    grid->addWidget(btn_next, 0 ,7, 1, 1);
    grid->addWidget(btn_save, 0 ,8, 1, 1);
    grid->addWidget(btn_return, 0 ,9, 1, 1);
    grid->addWidget(lbl_current_name, 0 ,10, 1, 4);

    grid->addWidget(tb_info, 1, 0);
    grid->addWidget(test_widget, 1,1, 1, 8);
    grid->addWidget(temp_widget, 1,9,1,8);

    grid->addWidget(lbl_test_info, 2, 5);
    grid->addWidget(lbl_temp_info, 2, 13);
    QWidget* central_widget = new QWidget(this);
    central_widget->setLayout(grid);

    this->setCentralWidget(central_widget);
    tb_info->setSelectionBehavior(QAbstractItemView::SelectRows);
    tb_info->setSelectionMode (QAbstractItemView::SingleSelection);
    tb_info->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // tool bar action
    ui->mainToolBar->addAction(ui->action_broken);
    ui->mainToolBar->addAction(ui->action_short);
    ui->mainToolBar->addAction(ui->action_gap);
    ui->mainToolBar->addAction(ui->action_burr);
    ui->mainToolBar->addAction(ui->action_cropper);
    ui->mainToolBar->addAction(ui->action_hole);
    //init private variables
    m_nCurrentRow = -1;
    m_bEditing = false;
    // signal
    connect(this->btn_open_filelist, SIGNAL(clicked()), this, SLOT(openTrainpairFile()));
    connect(this->tb_info, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(selectImage(int, int)));
    connect(this->btn_save, SIGNAL(clicked()), this, SLOT(saveAnnotation()));
    connect(this->btn_next, SIGNAL(clicked()), this, SLOT(nextImage()));
    connect(this->btn_prev, SIGNAL(clicked()), this, SLOT(prevImage()));
    connect(this->btn_return,SIGNAL(clicked()), this, SLOT(returnMain()));

    connect(ui->action_pen, SIGNAL(triggered()), this, SLOT(setTool()));
    connect(ui->action_eraser, SIGNAL(triggered()), this, SLOT(setTool()));
    connect(ui->action_zoomin, SIGNAL(triggered()), this, SLOT(changeToolSize()));
    connect(ui->action_zoomout, SIGNAL(triggered()), this, SLOT(changeToolSize()));

    connect(ui->action_broken, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_short, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_burr, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_gap, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_cropper, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_hole, SIGNAL(triggered()), this, SLOT(addDrawback()));
    connect(ui->action_delete, SIGNAL(triggered()), this, SLOT(removeDrawback()));
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTrainpairFile()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open filelist"), "./", "*.txt");
    QFile trainpair_file(filename);
    if(!trainpair_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "error", "cannot find file");
        return;
    }

    QTextStream in(&trainpair_file);
    QString line = in.readLine();
    m_trainpair_list.clear();
    while(!line.isNull()){
        QStringList trainpair = line.split(" ");
        if (trainpair.length() != 2){
            QMessageBox::warning(this, "error", "the wrong format in filelist");
            trainpair_file.close();
            return;
        }
        QPair<QString, QString> pair;
        pair.first = trainpair.first();
        pair.second = trainpair.last();

        m_trainpair_list.push_back(pair);

        line = in.readLine();
    }
    trainpair_file.close();
    updateMainTable();
    updateUI();

}

void MainWindow::selectImage(int row, int col)
{
    if(!m_bEditing){
        if(row<0 && row >= m_trainpair_list.length()){
            QMessageBox::warning(this, "error", "the selected index is out of range");
            return;
        }
        QString img_path, not_path;
        img_path = m_trainpair_list.at(row).first;
        not_path = m_trainpair_list.at(row).second;

        QString img_test_path, img_template_path;
        img_test_path = img_path.mid(0, img_path.lastIndexOf(".")) + QString("_test.jpg");
        img_template_path = img_path.mid(0, img_path.lastIndexOf(".")) + QString("_temp.jpg");

        QFile test_file(img_test_path);
        QFile temp_file(img_template_path);

        if(!test_file.exists() || !temp_file.exists()){
            qDebug()<<img_test_path<<endl<<img_template_path<<endl;
            QMessageBox::warning(this, "error", "the selected image doesn't exsit");
            return;
        }

        m_nCurrentRow = row;
        m_bEditing = true;
        updateDetailTable();

        test_widget->showTestImage(img_test_path);
        temp_widget->showTemplateImage(img_template_path);
        lbl_current_name->setText(img_path);

    }
    else{  // show the specific bounding box of a drawback
        test_widget->clearTestDrawback();
        test_widget->showTestDrawback(m_currentDrawbacks.at(row));
    }
    updateUI();

}

void MainWindow::saveAnnotation()
{
    if(test_widget->getDrawback()){
        DrawbackInfo new_drawback(*test_widget->getDrawback());
        m_currentDrawbacks.push_back(new_drawback);

    }
    test_widget->clearTestDrawback();

    //TODO: save images
    QString img_path, img_test_path;
    img_path = m_trainpair_list.at(m_nCurrentRow).first;
    img_test_path = img_path.mid(0, img_path.lastIndexOf(".")) + QString("_test.jpg");
    test_widget->saveImage(img_test_path);
    //TOTO: save drawbacks
    QString annote_test_path;
    annote_test_path = m_trainpair_list.at(m_nCurrentRow).second;
    QFile annote_file(annote_test_path);
    if(! annote_file.exists()){
        QMessageBox::warning(this, "error", QString("the annotation file doesn't exsit: %1").arg(annote_test_path));
        return;
    }

    // clear the annotation file
    fileClear(annote_file);
    if(! annote_file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QMessageBox::warning(this, "error", QString("cannot open the annotation file: %1").arg(annote_test_path));
        return;
    }
    QTextStream in(&annote_file);
    for(int i=0; i<m_currentDrawbacks.length(); i++){
        DrawbackInfo info = m_currentDrawbacks.at(i);
        in<<QString::number(info.x1_) + QString(" ");
        in<<QString::number(info.y1_) + QString(" ");
        in<<QString::number(info.x2_) + QString(" ");
        in<<QString::number(info.y2_) + QString(" ");
        in<<QString::number(info.type_) + QString("\n");
    }
    annote_file.close();

    // m_bEditing = false;
    updateDetailTable();
    updateUI();
}

void MainWindow::updateMainTable()
{
    tb_info->setRowCount(m_trainpair_list.length());
    tb_info->setColumnCount(2);

    QStringList header;
    header << "filename" << "number of defect";
    tb_info->setHorizontalHeaderLabels(header);
    tb_info->setColumnWidth(0, 100);
    tb_info->setColumnWidth(1, 85);
    QString img_name, annote_name;
    int annot_cnt;
    for(int i=0;i<m_trainpair_list.length();i++){
        annot_cnt = 0;
        img_name = m_trainpair_list.at(i).first;
        annote_name = m_trainpair_list.at(i).second;

        QFile annote_file(annote_name);
        if(annote_file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&annote_file);
            while(!in.readLine().isNull())
                annot_cnt ++;
            annote_file.close();
        }

        img_name = img_name.mid(img_name.lastIndexOf("\\")+1);
        tb_info->setItem(i, 0, new QTableWidgetItem(img_name));
        tb_info->setItem(i, 1, new QTableWidgetItem(QString::number(annot_cnt)));
    }
    if(m_nCurrentRow >= 0 && m_nCurrentRow < tb_info->rowCount())
        tb_info->selectRow(m_nCurrentRow);
}

void MainWindow::updateDetailTable()
{
    QString not_path = m_trainpair_list.at(m_nCurrentRow).second;
    QFile not_file(not_path);

    if(!not_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "warning", QString("cannot find the existing annotation file, a new annotation file will be created:")+not_path);
        //return;
    }
    m_currentDrawbacks.clear();
    tb_info->clear();
    tb_info->setColumnCount(5);
    tb_info->setRowCount(0);
    QStringList header;
    header << "x1" << "y1" << "x2" << "y2" << "type";
    tb_info->setHorizontalHeaderLabels(header);
    tb_info->setColumnWidth(0, 40);
    tb_info->setColumnWidth(1, 40);
    tb_info->setColumnWidth(2, 40);
    tb_info->setColumnWidth(3, 40);
    tb_info->setColumnWidth(4, 50);
    QString line;
    if(!not_file.isOpen()){
        if(!not_file.open(QIODevice::ReadWrite | QIODevice::Text)){
            QMessageBox::warning(this, "error", QString("fail to create annotation file:") + not_path);
            return;
        }
    }
    QTextStream in(&not_file);
    line = not_file.readLine();
    int i = 0;
    while(!line.isEmpty()){
        QStringList strlist = line.split(" ");
        if (strlist.length()!=5){
            QMessageBox::warning(this, "error", QString("the wrong format in annotation file:")+not_path);
            m_currentDrawbacks.clear();
            m_bEditing = false;
            updateMainTable();
            return;
        }

        DrawbackInfo info;
        info.x1_ = strlist.at(0).toInt();
        info.y1_ = strlist.at(1).toInt();
        info.x2_ = strlist.at(2).toInt();
        info.y2_ = strlist.at(3).toInt();
        info.type_ = strlist.at(4).toInt();
        tb_info->insertRow(i);
        tb_info->setItem(i, 0, new QTableWidgetItem(QString::number(info.x1_)));
        tb_info->setItem(i, 1, new QTableWidgetItem(QString::number(info.y1_)));
        tb_info->setItem(i, 2, new QTableWidgetItem(QString::number(info.x2_)));
        tb_info->setItem(i, 3, new QTableWidgetItem(QString::number(info.y2_)));
        tb_info->setItem(i, 4, new QTableWidgetItem(strDrawbackType(info.type_)));
        m_currentDrawbacks.push_back(info);
        i++;
        line = not_file.readLine();
    }

    m_bEditing = true;
}

void MainWindow::updateUI()
{
    btn_next->setEnabled(!m_bEditing);
    btn_prev->setEnabled(!m_bEditing);
    btn_open_filelist->setEnabled(!m_bEditing);
    btn_save->setEnabled(m_bEditing);
    btn_return->setEnabled(m_bEditing);
    ui->action_broken->setEnabled(m_bEditing);
    ui->action_burr->setEnabled(m_bEditing);
    ui->action_cropper->setEnabled(m_bEditing);
    ui->action_delete->setEnabled(m_bEditing);
    ui->action_eraser->setEnabled(m_bEditing);
    ui->action_gap->setEnabled(m_bEditing);
    ui->action_hole->setEnabled(m_bEditing);
    ui->action_pen->setEnabled(m_bEditing);
    ui->action_short->setEnabled(m_bEditing);
}

void MainWindow::nextImage()
{
    m_bEditing = false;
    int row = m_nCurrentRow + 1;
    if(row>=tb_info->rowCount())
        row = 0;
    selectImage(row, 0);
}

void MainWindow::prevImage()
{
    m_bEditing = false;
    int row = m_nCurrentRow - 1;
    if(row<0)
        row = tb_info->rowCount()-1;
    selectImage(row, 0);
}

void MainWindow::setTool()
{
    QAction* action = (QAction*)sender();
    if(action == ui->action_pen)
        test_widget->setTool("pen");
    else if(action == ui->action_eraser)
        test_widget->setTool("eraser");
    else{
        QMessageBox::warning(this, "error", "unrecognized signal source");
    }
}

void MainWindow::changeToolSize()
{
    QAction* action = (QAction*) sender();
    if(action == ui->action_zoomin)
        test_widget->increaseToolSize(1);
    else
        test_widget->increaseToolSize(-1);
}

void MainWindow::addDrawback()
{
    QAction* action = (QAction*)sender();
    if(action == ui->action_broken){
        test_widget->newDrawback(DRAWBACK_BROKEN);
    }else if(action == ui->action_short){
        test_widget->newDrawback(DRAWBACK_SHORT);

    }else if(action == ui->action_gap){
        test_widget->newDrawback(DRAWBACK_GAP);

    }else if(action == ui->action_burr){
        test_widget->newDrawback(DRAWBACK_BURR);

    }else if(action == ui->action_cropper){
        test_widget->newDrawback(DRAWBACK_CROPPER);

    }else if(action == ui->action_hole){
        test_widget->newDrawback(DRAWBACK_HOLE);

    }else{
        QMessageBox::warning(this, "error", "undefined defect type");
        return;
    }

}

void MainWindow::removeDrawback()
{
    int index = tb_info->currentRow();
    qDebug()<<index;
    if(index<0){
        QMessageBox::information(this, "error", "please first select the line you want to detet");
        return;
    }
    m_currentDrawbacks.remove(index);
    test_widget->clearTestDrawback();
}

void MainWindow::returnMain()
{
    m_bEditing = false;
    test_widget->clearTestDrawback();
    updateMainTable();
    updateUI();
}

