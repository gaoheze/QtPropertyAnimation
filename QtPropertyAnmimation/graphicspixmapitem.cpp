#include "graphicspixmapitem.h"

#include <QObject>
#include <QGraphicsPixmapItem>

GraphicsPixmapItem::GraphicsPixmapItem(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{

}
GraphicsPixmapItem::GraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent):QGraphicsPixmapItem(pixmap,parent)
{

}
