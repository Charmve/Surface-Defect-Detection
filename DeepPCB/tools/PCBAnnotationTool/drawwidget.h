#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPoint>
#include <QVector>
#include "datadef.h"
#include <QEvent>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void showTestImage(QString img_path);
    void showTestDrawback(const DrawbackInfo& drawback);
    void clearTestDrawback();
    void setTool(QString tool);
    void setToolSize(int tool_size){m_nCurrentToolSize = tool_size;}
    void increaseToolSize(int delta_size);
    void updateImage(QPoint pos);
    void saveImage(QString path);

    void newDrawback(int type);
    DrawbackInfo* getDrawback(){return m_pDrawbackInfo;}
signals:

public slots:

private:
    QPixmap m_pixmap;
    QString m_strCurrentTool;  // "pen", "eraser"
    int m_nCurrentToolSize;
    bool m_bDrawing;
    bool m_pressing;

    DrawbackInfo* m_pDrawbackInfo;
};

#endif // DRAWWIDGET_H
