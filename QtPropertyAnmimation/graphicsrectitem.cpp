#include "graphicsrectitem.h"

GraphicsRectItem::GraphicsRectItem(QGraphicsItem *parent):QGraphicsItem (parent)
{

}
void GraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget
    Q_UNUSED(widget);
}
