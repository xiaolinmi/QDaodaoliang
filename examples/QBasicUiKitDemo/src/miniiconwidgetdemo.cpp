﻿#include "miniiconwidgetdemo.h"
#include "ui_miniiconwidgetdemo.h"
#include <QTimer>

MiniIconWidgetDemo::MiniIconWidgetDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiniIconWidgetDemo)
{
    ui->setupUi(this);
    mMinIconWidget = new QBasicFormMinIconWidget;
    mMinIconWidget->setPixmap(QPixmap(":/image/icon_sun.png"));
    setWindowFlags(Qt::WindowStaysOnTopHint);
    connect(mMinIconWidget,SIGNAL(signalMiniIconClicked()),this,SLOT(showMiniDemoWindow()));
}

MiniIconWidgetDemo::~MiniIconWidgetDemo()
{
    delete ui;
}

void MiniIconWidgetDemo::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange){
        if(windowState() & Qt::WindowMinimized){
            QTimer::singleShot(0,this,SLOT(hideMiniDemoWindow()));
        } else if (windowState() & Qt::WindowNoState) {
            QTimer::singleShot(0,this,SLOT(showMiniDemoWindow()));
        }
    }
    QWidget::changeEvent(event);
}

void MiniIconWidgetDemo::showMiniDemoWindow()
{
    mMinIconWidget->hide();
    move(mMinIconWidget->pos());
    show();
    setWindowState(Qt::WindowNoState);
}

void MiniIconWidgetDemo::hideMiniDemoWindow()
{
    hide();
    mMinIconWidget->move(pos());
    mMinIconWidget->show();
    setWindowState(Qt::WindowMinimized);
}
