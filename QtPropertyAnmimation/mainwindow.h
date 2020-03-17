#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <m_imageinfo.h>
#include <m_graphicsitemgroup.h>
#include <graphicsview.h>
#include <QGraphicsScene>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <graphicsitemgroup.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    // m:n 集合
//    QList<QPair<M_ImageInfo,QList<M_ImageInfo>>> _lstImage; // init m:n list
    QList<M_ImageInfo *> _lstImage;
//    QList<QPair<GraphicsItemGroup *,QList<GraphicsItemGroup *>>> _items;
    QList<GraphicsItemGroup *> _items;
    GraphicsView *_view;
    QGraphicsScene  *_scene;
    QParallelAnimationGroup *_animationGroup;
    QTimer *_timer;
    bool _isStart;
    void iniImageInfo();
    void initData(int w,int h);
    void initGraphicsView();
    void initGraphicsScene();
    void initAnimation();
    void start();
    void play();
    void nextPlay();
    void prePlay();

};

#endif // MAINWINDOW_H
