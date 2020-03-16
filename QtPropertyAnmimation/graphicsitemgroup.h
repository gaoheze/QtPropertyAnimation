#ifndef GRAPHICSITEMGROUP_H
#define GRAPHICSITEMGROUP_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <graphicspixmapitem.h>
#include <m_imageinfo.h>
#include <QPropertyAnimation>

class GraphicsItemGroup:public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos)
public:
    GraphicsItemGroup(QGraphicsSimpleTextItem *titleItem,
                      QGraphicsSimpleTextItem *remarkItem,
                      QGraphicsItem *parent = nullptr);
    GraphicsItemGroup(GraphicsPixmapItem *pixmapItem,
                      QGraphicsSimpleTextItem *titleItem,
                      QGraphicsSimpleTextItem *remarkItem,
                      QGraphicsItem *parent = nullptr);
    GraphicsItemGroup(QPixmap pixmap,
                      M_ImageInfo *hImage,
                      QGraphicsSimpleTextItem *titleItem,
                      QGraphicsSimpleTextItem *remarkItem,
                      QGraphicsItem *parent = nullptr);
    QPixmap Pixmap() const  {return _pixmap;}
    GraphicsPixmapItem *PixmapItem() const {return _pixmapItem;}
    QPropertyAnimation *Animation ;
//    QPointF Pos() const {return this->pos();}
private:
    QPixmap _pixmap;
    GraphicsPixmapItem *_pixmapItem;
};

#endif // GRAPHICSITEMGROUP_H
