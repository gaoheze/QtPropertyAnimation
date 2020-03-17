#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H

#include <QObject>
#include <QGraphicsRectItem>

class GraphicsRectItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    GraphicsRectItem(QGraphicsItem *parent = nullptr);
public slots:
protected:
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // GRAPHICSRECTITEM_H
