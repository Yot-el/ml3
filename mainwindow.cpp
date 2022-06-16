#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    if(rects.size() > 0)
        rects[0]->draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    Rect *r = nullptr;
    QMessageBox MsgBox;
    QPoint point = event->pos();

    if(check_points == 0){
        r = new Rect(event->x(), event->y(), event->x(), event->y());
        if(r)
            rects.append(r);
        check_points++;
    }
    else if(check_points == 1){
        rects[0]->setX2(event->x());
        rects[0]->setY2(event->y());
        check_points++;
        repaint();
    }
    else{
        int xMax = rects[0]->getX1() > rects[0]->getX2() ? rects[0]->getX1() : rects[0]->getX2();
        int xMin = rects[0]->getX1() < rects[0]->getX2() ? rects[0]->getX1() : rects[0]->getX2();
        int yMax = rects[0]->getY1() > rects[0]->getY2() ? rects[0]->getY1() : rects[0]->getY2();
        int yMin = rects[0]->getY1() < rects[0]->getY2() ? rects[0]->getY1() : rects[0]->getY2();
        if((xMax >= point.x() && point.x() >= xMin) && (yMax >= point.y() && point.y() >= yMin))
            MsgBox.setText("Попал");
        else
            MsgBox.setText("Не попал");
        MsgBox.exec();
    }
}
