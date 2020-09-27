#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);

    void showTemplateImage(QPixmap pixmap);
    void showTemplateImage(QString img_path);

signals:

public slots:

private:
    QPixmap m_pixmap;
};

#endif // IMAGEWIDGET_H
