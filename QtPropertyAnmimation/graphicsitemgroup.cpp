#include "graphicsitemgroup.h"

GraphicsItemGroup::GraphicsItemGroup(
        QGraphicsSimpleTextItem *titleItem,
        QGraphicsSimpleTextItem *textItem,
        QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    titleItem->setPos(0,100);
    textItem->setPos(0,0);
    titleItem->setZValue(2);
    textItem->setZValue(2);
    this->addToGroup(titleItem);
    this->addToGroup(textItem);
}
GraphicsItemGroup::GraphicsItemGroup(GraphicsPixmapItem *pixmapItem,
                                     QGraphicsSimpleTextItem *titleItem,
                                     QGraphicsSimpleTextItem *textItem,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _pixmapItem     = pixmapItem;
    titleItem       ->setPos(0,100);
    textItem        ->setPos(0,0);
    titleItem       ->setZValue(2);
    textItem        ->setZValue(2);
    pixmapItem      ->setZValue(1);
    this            ->addToGroup(titleItem);
    this            ->addToGroup(textItem);
    this            ->addToGroup(pixmapItem);
}
GraphicsItemGroup::GraphicsItemGroup(QPixmap pixmap,
                                     M_ImageInfo *hImage,
                                     QGraphicsSimpleTextItem *titleItem,
                                     QGraphicsSimpleTextItem *textItem,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _pixmap     = pixmap;
    _pixmapItem = new GraphicsPixmapItem();
//    pixmapItem                     ->setOffset(0,0);
//    pixmapItem                     ->setOpacity(hImage->Opacity);
//    pixmapItem                     ->setPixmap(pixmap);
//    pixmapItem                     ->setScale(hImage->Scale);
    _pixmapItem                     ->setPixmap(pixmap.scaled(hImage->Size));
    _pixmapItem                     ->setZValue(hImage->ZValue);

    QPropertyAnimation *animation = new QPropertyAnimation(this,"offset");
    animation->setDuration(1000);
    animation->setEasingCurve(QEasingCurve::OutQuad);
//    _animation      = animation;
    titleItem       ->setPos(0,100);
    textItem        ->setPos(0,0);
    titleItem       ->setZValue(2);
    textItem        ->setZValue(2);
    _pixmapItem      ->setZValue(1);
//    this->setScale()
    this            ->addToGroup(titleItem);
    this            ->addToGroup(textItem);
    this            ->addToGroup(_pixmapItem);
}

