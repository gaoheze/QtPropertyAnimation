#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <m_imageinfo.h>
#include <graphicsview.h>
#include <graphicspixmapitem.h>
#include <QLabel>
#include <QGraphicsSimpleTextItem>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->iniImageInfo();
    this->iniImageInfoV();
//    this->initData(876,368);
    this->initGraphicsScene();
    this->initGraphicsView();
    this->initAnimation();
    this->initAnimationV();
    this->start();
    this->startV();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniImageInfo()
{
    M_ImageInfo *h_imgInfo;
    // 1
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =1;
    h_imgInfo->Size=QSize(120,150);
    h_imgInfo->Pos = QPointF(134,71);
    h_imgInfo->Opacity = 0.6;
    h_imgInfo->FileName ="2f934b7d5fd024982af84f5fa5cd58fe";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImage << h_imgInfo;
    //2
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(0,61);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="4e0610df605137cf23064c73f012060f";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(2);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(2);
    _lstImage << h_imgInfo;
    //3
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(110,37);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="7c574b3ffc0533aae6bdc34cca0e433d";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(3);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(3);
    _lstImage << h_imgInfo;
    //4
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =4;
    h_imgInfo->Size=QSize(224,288);
    h_imgInfo->Pos = QPointF(262,0);
    h_imgInfo->Opacity = 1;
    h_imgInfo->FileName ="8b761e2087a9ce4fb7bced1d449ef310";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(4);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(4);
    _lstImage << h_imgInfo;
    //5
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(468,37);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="8f9f58103411388e36c61cd1a00cef7e";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(5);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(5);
    _lstImage << h_imgInfo;
    //6
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(620,61);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="9b8b675dd03447cd251ea4a89295e741";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(6);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(6);
    _lstImage << h_imgInfo;
    //7
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =1;
    h_imgInfo->Size=QSize(120,150);
    h_imgInfo->Pos = QPointF(496,71);
    h_imgInfo->Opacity = 0.6;
    h_imgInfo->FileName ="33c9b7df15f99d1313afa1a15e91a326";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(7);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(7);
    _lstImage << h_imgInfo;
}
void MainWindow::initData(int w,int h)
{
    QList<QString> fileNames = {
        "2f934b7d5fd024982af84f5fa5cd58fe",
        "4e0610df605137cf23064c73f012060f",
        "7c574b3ffc0533aae6bdc34cca0e433d",
        "8b761e2087a9ce4fb7bced1d449ef310",
        "8f9f58103411388e36c61cd1a00cef7e",
        "9b8b675dd03447cd251ea4a89295e741",
        "33c9b7df15f99d1313afa1a15e91a326",
//        "84d56dd1a64dfed75d53c046ce4f9de4"
    };
    // 构建初始化数据
    // 1:n 集合
    // 版本切换数据 1
    QPair<M_ImageInfo,QList<M_ImageInfo>> pair ;
    for (int i=0; i < fileNames.size();i++) {
        // 计算等比公式
        M_ImageInfo *h_info ;
        h_info->FileName    = fileNames[i];
        h_info->Scale       = 0.5;
        // 检测项目数据 n
        if (i <= 3) {
            h_info->Pos         = QPointF(w/16+i*100,h/4-i*20);
            h_info->Size        = QSize(510+i*30,250+i*40);
            h_info->ZValue      = 1+i;
            h_info->Opacity     = 1;
            h_info->TextTitle   = QString("国家体科所%1").arg(i);
            h_info->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(i);

            for(int j =0; j < 2; j++)
            {
                M_ImageInfo info;
                info.Pos=QPointF(w/16+i*100,h/4-i*20+300*j);
                info.Size=QSize(348+i*30,106+i*40);
                info.ZValue=3-j;
                pair.second.append(info);
            }
        }
        else if (i > 3 ) {
            h_info->Pos         = QPointF(w/16+i*100+50,h/4-(fileNames.size()-i-1)*20);
            h_info->Size        = QSize(510+(fileNames.size()-i-1)*30,250+(fileNames.size()-i-1)*40);
            h_info->ZValue      = fileNames.size() - i;
            h_info->Opacity     = 1;
            h_info->TextTitle   =QString("国家体科所%1").arg(i);
            h_info->TextRemark  =QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(i);

            for(int j =0; j < 2; j++)
            {
                M_ImageInfo info;
                info.Pos=QPointF(w/16+i*100,h/4-(fileNames.size()-i-1)*20+300*j);
                info.Size=QSize(348+(fileNames.size()-i-1)*30,106+(fileNames.size()-i-1)*40);
                info.ZValue=3-j;
                pair.second.append(info);
            }
        }
//        pair.first = h_info;

        _lstImage.append(h_info);
    }

}
void MainWindow::initGraphicsView()
{
     _view = new GraphicsView();
     _view->setFrameShape(QFrame::NoFrame);
     _view->setParent(this);
     _view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     _view->setBackgroundBrush(QColor(46, 46, 46));
     _view->setCacheMode(QGraphicsView::CacheBackground);
     _view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
     _view->setStyleSheet("padding:0;border:0");
     _view->setScene(_scene);
     ui->verticalLayout->addWidget(_view);
}
void MainWindow::initGraphicsScene()
{
    // 设置场景大小
     _scene = new QGraphicsScene(QRect(0, 0, 876, 368), this);
     foreach (auto data , _lstImage){
          QString fileName               = data->FileName;
          QString centerImg              = QString(":/images/%1.jpg").arg(fileName);
          QPixmap pixmap                 = QPixmap(centerImg);
          GraphicsItemGroup *itemGroup = new GraphicsItemGroup(pixmap,data->Size,
                                                               data->TextTitle,QPointF(0,43),16,
                                                               data->TextRemark,QPointF(62,123),10);
          itemGroup->setPos(data->Pos);
          itemGroup->setSize(data->Size);
          itemGroup->setZValue(data->ZValue);
          _scene->addItem(itemGroup);
          _items.append(itemGroup);
     }

     foreach (auto data , _lstImageV){
          QString fileName               = data->FileName;
          QString centerImg              = QString(":/images/%1.jpg").arg(fileName);
          QPixmap pixmap                 = QPixmap(centerImg);
          GraphicsItemGroup *itemGroup = new GraphicsItemGroup(pixmap,data->Size,
                                                               data->TextTitle,QPointF(0,43),16,
                                                               data->TextRemark,QPointF(62,123),10);
          itemGroup->setPos(data->Pos);
          itemGroup->setSize(data->Size);
          itemGroup->setZValue(data->ZValue);
          _scene->addItem(itemGroup);
          _itemsV.append(itemGroup);
     }
}
void MainWindow::initAnimation()
{
    _animationGroup = new QParallelAnimationGroup();
    foreach (auto item , _items)
    {
        _animationGroup->addAnimation(item->AnimationPos());
        _animationGroup->addAnimation(item->AnimationSize());
    }
}
void MainWindow::start()
{
    _animationGroup->start();
    _timer  = new QTimer(this);
    _timer  ->setInterval(5000);

    connect(_timer, &QTimer::timeout, [this](){
        nextPlay();
    });
    connect(_animationGroup, &QParallelAnimationGroup::finished, [this](){
        _isStart = false;
        _timer->start();
    });
    _timer  ->start();
}
void MainWindow::play()
{
    for (int index =0 ; index < _lstImage.size(); index ++) {
        auto data = _lstImage[index];
        auto item = _items[index];

        item->setOpacity(data->Opacity);
        item->setZValue(data->ZValue);

        QPointF pt =item->pos();
        QPointF pte(data->Pos);
        item->AnimationPos()->setStartValue(pt);
        item->AnimationPos()->setEndValue(pte);

        QSize ss = item->size();
        QSize se = data->Size;
        item->AnimationSize()->setStartValue(ss);
        item->AnimationSize()->setEndValue(se);
    }
    _isStart = true;
}
void MainWindow::nextPlay()
{
    _animationGroup->stop();
    auto pixmapItem = _items.takeAt(0);
    _items << pixmapItem;
    this->play();
    _animationGroup->start();
}
void MainWindow::prePlay()
{
    _animationGroup->stop();
    auto pixmapItem = _items.takeAt(_items.size()-1);
    _items.prepend(pixmapItem);
    this->play();
    _animationGroup->start();
}
void MainWindow::iniImageInfoV()
{
    _lstImageV = QList<M_ImageInfo *>();
    M_ImageInfo *h_imgInfo;
    // 1
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =1;
    h_imgInfo->Size=QSize(120,150);
    h_imgInfo->Pos = QPointF(134,271);
    h_imgInfo->Opacity = 0.6;
    h_imgInfo->FileName ="2f934b7d5fd024982af84f5fa5cd58fe";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //2
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(0,261);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="4e0610df605137cf23064c73f012060f";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //3
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(110,237);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="7c574b3ffc0533aae6bdc34cca0e433d";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //4
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =4;
    h_imgInfo->Size=QSize(224,288);
    h_imgInfo->Pos = QPointF(262,200);
    h_imgInfo->Opacity = 1;
    h_imgInfo->FileName ="8b761e2087a9ce4fb7bced1d449ef310";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //5
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(468,237);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="8f9f58103411388e36c61cd1a00cef7e";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //6
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(620,261);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="9b8b675dd03447cd251ea4a89295e741";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
    //7
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =1;
    h_imgInfo->Size=QSize(120,150);
    h_imgInfo->Pos = QPointF(496,271);
    h_imgInfo->Opacity = 0.6;
    h_imgInfo->FileName ="33c9b7df15f99d1313afa1a15e91a326";
    h_imgInfo->TextTitle   = QString("国家体科所%1").arg(1);
    h_imgInfo->TextRemark  = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(1);
    _lstImageV.append(h_imgInfo);
}
void MainWindow::initAnimationV()
{
    _animationGroupV = new QParallelAnimationGroup();
    foreach (auto item , _itemsV)
    {
        _animationGroupV->addAnimation(item->AnimationPos());
        _animationGroupV->addAnimation(item->AnimationSize());
    }
}
void MainWindow::startV()
{
    _animationGroupV->start();
    _timerV  = new QTimer(this);
    _timerV  ->setInterval(2000);

    connect(_timerV, &QTimer::timeout, [this](){
        nextPlayV();
    });
    connect(_animationGroupV, &QParallelAnimationGroup::finished, [this](){
        _isStartV = false;
        _timerV->start();
    });
    _timerV  ->start();
}
void MainWindow::playV()
{
    for (int index =0 ; index < _lstImageV.size(); index ++) {
        auto data = _lstImageV[index];
        auto item = _itemsV[index];
        item->setText(_items[3]->Text());
        item->setOpacity(data->Opacity);
        item->setZValue(data->ZValue);

        QPointF pt =item->pos();
        QPointF pte(data->Pos);
        item->AnimationPos()->setStartValue(pt);
        item->AnimationPos()->setEndValue(pte);

        QSize ss = item->size();
        QSize se = data->Size;
        item->AnimationSize()->setStartValue(ss);
        item->AnimationSize()->setEndValue(se);
    }
    _isStartV = true;
}
void MainWindow::nextPlayV()
{
    _animationGroupV->stop();
    auto pixmapItem = _itemsV.takeAt(0);
    _itemsV << pixmapItem;
    this->playV();
    _animationGroupV->start();
}
void MainWindow::prePlayV()
{
    _animationGroupV->stop();
    auto pixmapItem = _itemsV.takeAt(_items.size()-1);
    _itemsV.prepend(pixmapItem);
    this->playV();
    _animationGroupV->start();
}
