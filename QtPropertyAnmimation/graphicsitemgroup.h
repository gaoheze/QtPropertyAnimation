#ifndef GRAPHICSITEMGROUP_H
#define GRAPHICSITEMGROUP_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <graphicspixmapitem.h>
#include <m_imageinfo.h>
#include <QPropertyAnimation>
#include <QTextBlockFormat>
#include <QTextCursor>

class GraphicsItemGroup:public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(QSize size READ size WRITE setSize)
public:
    // 1行文字样式
    GraphicsItemGroup(QColor color,
                      QString text1,qreal x1,qreal y1,qreal fontSize,
                      QGraphicsItem *parent = nullptr);
    // 2行文字样式
    GraphicsItemGroup(QSize size,
                      QString text1,QPointF pos1,double fontSize1,
                      QString text2,QPointF pos2,double fontSize2,
                      QGraphicsItem *parent = nullptr);
    // 2行文字 + 一张图片样式
    GraphicsItemGroup(QColor color,
                      QPixmap pixmap,
                      QString text1,qreal x1,qreal y1,qreal fontSize1,
                      QString text2,qreal x2,qreal y2,qreal fontSize2,
                      QGraphicsItem *parent = nullptr);
    void setSize(const QSize &size);
    QSize size() const {return  _size;}
    QPropertyAnimation *AnimationPos() const {return _animationPos;}
    QPropertyAnimation *AnimationSize() const {return _animationSize;}

private:
    QGraphicsRectItem *_rectItem;
    QPropertyAnimation *_animationPos;
    QPropertyAnimation *_animationSize;
    QSize _size;
};

#endif // GRAPHICSITEMGROUP_H
