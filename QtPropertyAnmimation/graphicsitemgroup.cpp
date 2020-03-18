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
    _rectItem       ->setPen(QPen(Qt::blue,4,Qt::SolidLine));
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
GraphicsItemGroup::GraphicsItemGroup(QPixmap pixmap,QSize size,
                                     QString text1,QPointF pos1,double fontSize1,
                                     QString text2,QPointF pos2,double fontSize2,
                                     QGraphicsItem *parent):QGraphicsItemGroup (parent)
{
    _size           = size;
    _rectItem       = new QGraphicsRectItem(0,0,size.width(),size.height());
    _rectItem       ->setBrush(QColor(60, 188, 243));//QBrush(color)
    _rectItem       ->setPen(QPen(Qt::blue,4,Qt::SolidLine));
    this            ->addToGroup(_rectItem);

    _pixmap         = pixmap    ;
    _pixmapItem     = new GraphicsPixmapItem();
    _pixmapItem     ->setOffset(0,0);
    _pixmapItem     ->setPixmap(_pixmap.scaled(size));
    this            ->addToGroup(_pixmapItem);

    QTextBlockFormat *format;
//    QGraphicsTextItem *textItem;
    QTextCursor     cursor;
    _textTitleItem        = new QGraphicsTextItem(text1);
    _textTitleItem        ->setPos(pos1);
    _textTitleItem        ->setFont(QFont("Source Han Sans CN",fontSize1));
    _textTitleItem        ->setDefaultTextColor(QColor(158, 211, 236));
    _textTitleItem        ->setZValue(2);
    _textTitleItem        ->setTextWidth(_rectItem->boundingRect().width());
    format          = new QTextBlockFormat();
    format          ->setAlignment(Qt::AlignCenter);
    cursor          = _textTitleItem->textCursor();
    cursor          .select(QTextCursor::Document);
    cursor          .mergeBlockFormat(*format);
    cursor          .clearSelection();
    _textTitleItem        ->setTextCursor(cursor);
    this            ->addToGroup(_textTitleItem);

    _textRemarkItem        = new QGraphicsTextItem(text2);
    _textRemarkItem        ->setPos(pos2);
    _textRemarkItem        ->setFont(QFont("Source Han Sans CN",fontSize2));
    _textRemarkItem        ->setDefaultTextColor(QColor(123, 172, 214));
    _textRemarkItem        ->setZValue(2);
    _textRemarkItem        ->setTextWidth(_rectItem->boundingRect().width());

    format          = new QTextBlockFormat();
    format          ->setAlignment(Qt::AlignLeft);
    cursor          = _textRemarkItem->textCursor();
    cursor          .select(QTextCursor::Document);
    cursor          .mergeBlockFormat(*format);
    cursor          .clearSelection();
    _textRemarkItem        ->setTextCursor(cursor);
    this            ->addToGroup(_textRemarkItem);

    _animationPos   = new QPropertyAnimation(this,"pos");
    _animationPos   ->setDuration(1000);
    _animationPos   ->setEasingCurve(QEasingCurve::OutQuad);
    _animationSize  = new QPropertyAnimation(this,"size");
    _animationSize  ->setDuration(1000);
    _animationSize  ->setEasingCurve(QEasingCurve::OutQuad);

}
void GraphicsItemGroup::setText(const QString text)
{
    _textTitleItem->setHtml(text);
}
void GraphicsItemGroup::setSize(const QSize &size)
{
    _size           = size;
    _pixmapItem     ->setPixmap(_pixmap.scaled(size));
    _rectItem       ->setRect(0,0,size.width(),size.height());
}
