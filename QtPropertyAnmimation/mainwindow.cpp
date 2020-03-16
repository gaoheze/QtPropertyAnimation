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
    //    this->iniImageInfo();
    this->initData(876,368);
    this->initGraphicsScene();
    this->initGraphicsView();
    this->initAnimation();
    this->start();
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
    _lstImage << h_imgInfo;
    //2
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(0,61);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="4e0610df605137cf23064c73f012060f";
    _lstImage << h_imgInfo;
    //3
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(110,37);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="7c574b3ffc0533aae6bdc34cca0e433d";
    _lstImage << h_imgInfo;
    //4
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =4;
    h_imgInfo->Size=QSize(224,288);
    h_imgInfo->Pos = QPointF(262,0);
    h_imgInfo->Opacity = 1;
    h_imgInfo->FileName ="8b761e2087a9ce4fb7bced1d449ef310";
    _lstImage << h_imgInfo;
    //5
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =3;
    h_imgInfo->Size=QSize(170,218);
    h_imgInfo->Pos = QPointF(468,37);
    h_imgInfo->Opacity = 0.88;
    h_imgInfo->FileName ="8f9f58103411388e36c61cd1a00cef7e";
    _lstImage << h_imgInfo;
    //6
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =2;
    h_imgInfo->Size=QSize(130,170);
    h_imgInfo->Pos = QPointF(620,61);
    h_imgInfo->Opacity = 0.7;
    h_imgInfo->FileName ="9b8b675dd03447cd251ea4a89295e741";
    _lstImage << h_imgInfo;
    //7
    h_imgInfo =new M_ImageInfo();
    h_imgInfo->ZValue =1;
    h_imgInfo->Size=QSize(120,150);
    h_imgInfo->Pos = QPointF(496,71);
    h_imgInfo->Opacity = 0.6;
    h_imgInfo->FileName ="33c9b7df15f99d1313afa1a15e91a326";
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
//    QPair<M_ImageInfo,QList<M_ImageInfo> *> *pair;
    // 版本切换数据 1
    M_ImageInfo *h_info;

//    int k = fileNames.size()%2;

    for (int i=0; i < fileNames.size();i++) {
        // 计算等比公式
        h_info              = new M_ImageInfo();
        h_info->FileName    = fileNames[i];
        h_info->Scale       = 0.5;

        if (i <= 3) {
            h_info->Pos         = QPointF(w/16+i*100,h/4-i*20);
            h_info->Size        = QSize(510+i*30,250+i*40);
            h_info->ZValue      = 1+i;
            h_info->Opacity     = 1;
        }
        else if (i > 3 ) {
            h_info->Pos         = QPointF(w/16+i*100+50,h/4-(fileNames.size()-i-1)*20);
            h_info->Size        = QSize(510+(fileNames.size()-i-1)*30,250+(fileNames.size()-i-1)*40);
            h_info->ZValue      = fileNames.size() - i;
            h_info->Opacity     = 1;
        }

        // 检测项目数据 n

        _lstImage.append( h_info);
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
     int index =0;
     foreach(auto hImage,_lstImage)
     {
         QString text1 = QString("国家体科所%1").arg(index);
         QString text2 = QString("体科所主要任务是引领和推动\n中国体育科技事业发展%1").arg(index);
//         QColor color = QColor(60, 188, 243);
         QSize size = hImage->Size;
         GraphicsItemGroup *itemGroup = new GraphicsItemGroup(size,
                                                              text1,QPointF(0,43),49.5,
                                                              text2,QPointF(62,123),30);
         itemGroup->setPos(hImage->Pos);
         itemGroup->setSize(QSize(hImage->Size.width(),hImage->Size.height()));
         itemGroup->setOpacity(hImage->Opacity);
         itemGroup->setZValue(hImage->ZValue);
         _scene->addItem(itemGroup);
         _items.append(itemGroup);
         index ++;
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
    _timer  ->setInterval(2000);

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
        auto image = _lstImage[index];
        auto item = _items[index];

        item->setOpacity(image->Opacity);
        item->setZValue(image->ZValue);
        item->setSize(image->Size);

        QPointF pt =item->pos();
        QPointF pte(image->Pos);
        item->AnimationPos()->setStartValue(pt);
        item->AnimationPos()->setEndValue(pte);

        QSize ss = item->size();
        QSize se = image->Size;
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
