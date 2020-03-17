#ifndef M_PIXMAPINFO_H
#define M_PIXMAPINFO_H

#include <QList>
#include <graphicsitemgroup.h>
class M_GraphicsItemGroup
{
public:
//    GraphicsPixmapItem *PixMapItem = new GraphicsPixmapItem();
//    QList<GraphicsPixmapItem *> LstpixMapItem;
//    QPixmap PixMap;
//    QPropertyAnimation *animation;
    GraphicsItemGroup * Group;
    QList<GraphicsItemGroup *> ListGroup;
};
#endif // M_PIXMAPINFO_H
