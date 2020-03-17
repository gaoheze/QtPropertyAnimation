#ifndef M_IMAGEINFO_H
#define M_IMAGEINFO_H
#include <QString>
#include <QSize>
#include <QPointF>
class M_ImageInfo
{
public:
    int ZValue ;
    qreal Scale;
    QPointF Pos;
    QSize Size;
    qreal Opacity;
    QString FileName;
    QString TextTitle;
    QString TextRemark;
};
#endif // M_IMAGEINFO_H
