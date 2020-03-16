#ifndef M_PIXMAPINFO_H
#define M_PIXMAPINFO_H
#include <graphicspixmapitem.h>
#include <QList>
#include <QPixmap>
#include <QPropertyAnimation>
class M_PixmapInfo
{
public:
    GraphicsPixmapItem *PixMapItem = new GraphicsPixmapItem();
    QList<GraphicsPixmapItem *> LstpixMapItem;
    QPixmap PixMap;
    QPropertyAnimation *animation;
};
#endif // M_PIXMAPINFO_H
