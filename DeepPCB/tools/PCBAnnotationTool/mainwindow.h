#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "imagewidget.h"
#include "drawwidget.h"
#include "datadef.h"

#include <QPair>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void openTrainpairFile();
    void selectImage(int row, int col);
    void saveAnnotation();
    void nextImage();
    void prevImage();

    void setTool();
    void changeToolSize();
    void addDrawback();
    void removeDrawback();
    void returnMain();
private:
    void updateMainTable();
    void updateDetailTable();
    void updateUI();
private:
    Ui::MainWindow *ui;
    QPushButton* btn_save;
    QPushButton* btn_next;
    QPushButton* btn_prev;
    QPushButton* btn_open_filelist;
    QPushButton* btn_return;
    QLabel* lbl_current_name;
    QLabel* lbl_filelist_path;

    QTableWidget* tb_info;

    ImageWidget* temp_widget;   // template image widget
    DrawWidget* test_widget;   // test image widget

    // private variables
    QVector<QPair<QString, QString> > m_trainpair_list;
    int m_nCurrentRow;
    bool m_bEditing;

    QVector<DrawbackInfo> m_currentDrawbacks;
};

#endif // MAINWINDOW_H
