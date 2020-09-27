#include "drawwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QCursor>
#include <QImage>

#define MARGIN 10
#define THRESHOLD 125
int min(int x, int y){
    return x > y? y : x;
}

int max(int x, int y){
    return x > y? x: y;
}

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    this->setMaximumSize(640,640);
    this->setMinimumSize(640,640);
    this->setAutoFillBackground(true);
    this->setPalette(Qt::white);
    m_nCurrentToolSize = 1;
    m_bDrawing = false;
    m_pDrawbackInfo = NULL;
    m_pixmap = QPixmap(640,640);
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // draw pixmap
    painter.drawPixmap(0,0,m_pixmap);

    // draw drawback bounding box
    if(m_pDrawbackInfo){
        painter.setPen(QPen(Qt::green, 3));
        painter.drawRect(QRect(QPoint(m_pDrawbackInfo->x1_, m_pDrawbackInfo->y1_), QPoint(m_pDrawbackInfo->x2_, m_pDrawbackInfo->y2_)));
    }
}

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if(!m_bDrawing)
        return;
    m_pressing = true;
    updateImage(event->pos());
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(!m_bDrawing || !m_pressing)
        return;
    updateImage(event->pos());
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(!m_bDrawing || !m_pressing)
        return;
    m_pressing = false;
    updateImage(event->pos());
}

void DrawWidget::enterEvent(QEvent *event)
{
    QCursor cursor;
    QPixmap pixmap;
    if(m_strCurrentTool=="pen")
        pixmap.load("./PCBAnnotationTool/images/pen.png");
    else
        pixmap.load("./PCBAnnotationTool/images/eraser.png");
    cursor = QCursor(pixmap, 0, 0);
    setCursor(cursor);
}

void DrawWidget::leaveEvent(QEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

void DrawWidget::showTestImage(QString img_path)
{
    QPixmap pix(img_path);
    m_pixmap = pix;
    update();
}

void DrawWidget::showTestDrawback(const DrawbackInfo &drawback)
{
    if(m_pDrawbackInfo)
        delete[] m_pDrawbackInfo;
    m_pDrawbackInfo = new DrawbackInfo(drawback);
    update();
}

void DrawWidget::clearTestDrawback()
{
    if(m_pDrawbackInfo)
        delete[] m_pDrawbackInfo;
    m_pDrawbackInfo = NULL;
    m_bDrawing = false;
    update();
}

void DrawWidget::setTool(QString tool)
{
    m_strCurrentTool = tool;
}

void DrawWidget::increaseToolSize(int delta_size)
{
    m_nCurrentToolSize += delta_size;
    if (m_nCurrentToolSize<1)
        m_nCurrentToolSize = 1;
}

void DrawWidget::updateImage(QPoint pos)
{
    int x, y;
    x = pos.x();
    y = pos.y();

    if(m_pDrawbackInfo == NULL){
        QMessageBox::warning(this, "error", "please first edit or create a defect");
        return;
    }


    m_pDrawbackInfo->x1_ = max(min(x-MARGIN-m_nCurrentToolSize, m_pDrawbackInfo->x1_), 0);
    m_pDrawbackInfo->y1_ = max(min(y-MARGIN-m_nCurrentToolSize, m_pDrawbackInfo->y1_), 0);
    m_pDrawbackInfo->x2_ = min(max(x+MARGIN+m_nCurrentToolSize, m_pDrawbackInfo->x2_), m_pixmap.width()-1);
    m_pDrawbackInfo->y2_ = min(max(y+MARGIN+m_nCurrentToolSize, m_pDrawbackInfo->y2_), m_pixmap.width()-1);
    QPainter painter(&m_pixmap);
    if(m_strCurrentTool=="pen"){
        painter.setBrush(Qt::black);
        painter.setPen(Qt::black);
    }
    else{
        painter.setBrush(Qt::white);
        painter.setPen(Qt::white);
    }
    painter.drawEllipse(pos, m_nCurrentToolSize, m_nCurrentToolSize);
    update();
}

void DrawWidget::saveImage(QString path)
{
    QImage img;
    img = m_pixmap.toImage();
    img = img.convertToFormat(QImage::Format_Indexed8);
    // m_pixmap.save(path);
    img.save(path);
}

void DrawWidget::newDrawback(int type)
{
    m_pressing = false;
    m_bDrawing = true;
    if(m_pDrawbackInfo)
        delete[] m_pDrawbackInfo;
    m_pDrawbackInfo = new DrawbackInfo(99999, 99999, -1, -1, type);
    if(type == DRAWBACK_BROKEN || type == DRAWBACK_HOLE || type == DRAWBACK_GAP)
        setTool("eraser");
    else
        setTool("pen");
}
