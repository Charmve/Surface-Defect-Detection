#include "imagewidget.h"
#include <QPalette>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    this->setMaximumSize(640,640);
    this->setMinimumSize(640,640);
    this->setAutoFillBackground(true);
    this->setPalette(Qt::white);
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,0,m_pixmap.toImage());
}

void ImageWidget::showTemplateImage(QPixmap pixmap)
{
    m_pixmap = pixmap;
    update();
}

void ImageWidget::showTemplateImage(QString img_path)
{
    QPixmap pix(img_path);
    m_pixmap = pix;
    update();
}
