#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class GraphicsPixmapItem:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF offset READ offset WRITE setOffset)
    Q_PROPERTY(QSize size READ size)
public:
    GraphicsPixmapItem(QGraphicsItem *parent = nullptr);
    GraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
    QSize size () const { return pixmap().size();}

};

#endif // GRAPHICSPIXMAPITEM_H
