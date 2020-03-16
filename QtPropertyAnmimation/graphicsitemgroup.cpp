#include "graphicsitemgroup.h"
#include <QFont>
#include <QLabel>

// 1行文字样式
GraphicsItemGroup::GraphicsItemGroup(QColor color,
                                     QString text1,qreal x1,qreal y1,qreal fontSize1,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _rectItem       = new QGraphicsRectItem();
    _rectItem       ->setBrush(QBrush(color));//QColor(60, 188, 243)
    this            ->addToGroup(_rectItem);
    QGraphicsTextItem *textItem;
    textItem        = new QGraphicsTextItem(text1);
    textItem        ->setPos(x1,y1);
    textItem        ->setFont(QFont("Source Han Sans CN",fontSize1));
    textItem        ->setDefaultTextColor(QColor(158, 211, 236));
    textItem        ->setZValue(2);
    this            ->addToGroup(textItem);
}
// 2行文字样式
GraphicsItemGroup::GraphicsItemGroup(QSize size,
                                     QString text1,QPointF pos1,double fontSize1,
                                     QString text2,QPointF pos2,double fontSize2,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _size           = size;
    _rectItem       = new QGraphicsRectItem(0,0,size.width(),size.height());
    _rectItem       ->setBrush(QColor(60, 188, 243));//QBrush(color)
    this            ->addToGroup(_rectItem);
    QTextBlockFormat *format;
    QGraphicsTextItem *textItem;
    QTextCursor cursor;
    textItem        = new QGraphicsTextItem(text1);
    textItem        ->setPos(pos1);
    textItem        ->setFont(QFont("Source Han Sans CN",fontSize1));
    textItem        ->setDefaultTextColor(QColor(158, 211, 236));
    textItem        ->setZValue(2);
    textItem        ->setTextWidth(_rectItem->boundingRect().width());
    format          = new QTextBlockFormat();
    format          ->setAlignment(Qt::AlignCenter);
    cursor = textItem->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(*format);
    cursor.clearSelection();
    textItem        ->setTextCursor(cursor);
    this            ->addToGroup(textItem);

    textItem        = new QGraphicsTextItem(text2);
    textItem        ->setPos(pos2);
    textItem        ->setFont(QFont("Source Han Sans CN",fontSize2));
    textItem        ->setDefaultTextColor(QColor(123, 172, 214));
    textItem        ->setZValue(2);
    textItem        ->setTextWidth(_rectItem->boundingRect().width());

    format = new QTextBlockFormat();
    format->setAlignment(Qt::AlignLeft);
    cursor = textItem->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(*format);
    cursor.clearSelection();
    textItem        ->setTextCursor(cursor);
    this            ->addToGroup(textItem);

    _animationPos = new QPropertyAnimation(this,"pos");
    _animationPos->setDuration(1000);
    _animationPos->setEasingCurve(QEasingCurve::OutQuad);
    _animationSize = new QPropertyAnimation(this,"size");
    _animationSize->setDuration(1000);
    _animationSize->setEasingCurve(QEasingCurve::OutQuad);
}
// 2行文字+1张图片样式
GraphicsItemGroup::GraphicsItemGroup(QColor color,
                                     QPixmap pixmap,
                                     QString text1,qreal x1,qreal y1,qreal fontSize1,
                                     QString text2,qreal x2,qreal y2,qreal fontSize2,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _rectItem       = new QGraphicsRectItem();
    _rectItem       ->setBrush(QBrush(color));//QColor(60, 188, 243)

    this            ->addToGroup(_rectItem);
    QGraphicsTextItem *textItem;
    textItem        = new QGraphicsTextItem(text1);
    textItem        ->setPos(x1,y1);
    textItem        ->setFont(QFont("Source Han Sans CN",fontSize1));
    textItem        ->setDefaultTextColor(QColor(158, 211, 236));
    textItem        ->setZValue(2);
    this            ->addToGroup(textItem);
    textItem        = new QGraphicsTextItem(text2);
    textItem        ->setPos(x2,y2);
    textItem        ->setFont(QFont("Source Han Sans CN",fontSize2));
    textItem        ->setDefaultTextColor(QColor(123, 172, 214));
    textItem        ->setZValue(2);
    textItem        ->setTextWidth(textItem->boundingRect().width());

    QTextBlockFormat format;
    format.setAlignment(Qt::AlignLeft);
    QTextCursor cursor = textItem->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    cursor.clearSelection();
    textItem        ->setTextCursor(cursor);
    this            ->addToGroup(textItem);
}

void GraphicsItemGroup::setSize(const QSize &size)
{
    _size= size;
    _rectItem->setRect(0,0,size.width(),size.height());
}
