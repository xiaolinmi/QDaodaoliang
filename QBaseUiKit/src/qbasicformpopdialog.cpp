﻿#include "qbasicformpopdialog.h"
#include <QMouseEvent>
#include <QDebug>

PopDialog::PopDialog(QWidget *parent) :
    QBasicFormMoveableWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool);
    mIsPause = false;
    remainTimer = NULL;
    animation = NULL;
}

PopDialog::~PopDialog()
{
}

void PopDialog::showPopDialog(quint32 paramRemainTime)
{
    mremainTime = paramRemainTime * 500;
    this->move((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height());
    if(!this->isVisible()){
        show();
        showAnimation();
    }
}

void PopDialog::closePopDialog()
{
}

void PopDialog::pausePopDialog()
{
    if(animation != NULL){
        this->move((desktop.availableGeometry().width()-this->width()),(desktop.availableGeometry().height()-this->height()));
        animation->setPaused(true);
        mIsPause = true;
    }
}

void PopDialog::startPopDialog()
{
    if(mIsPause){
        if(animation != NULL){
            animation->setPaused(false);
            mIsPause = false;
        }
    }
}

void PopDialog::showAnimation(){
    if(!mIsPause){
        animation=new QPropertyAnimation(this,"pos");
        animation->setDuration(mremainTime);
        animation->setEasingCurve(QEasingCurve::OutElastic);
        animation->setStartValue(QPoint(this->x(),this->y()));
        animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),(desktop.availableGeometry().height()-this->height())));
        connect(animation,SIGNAL(valueChanged(QVariant)),this,SLOT(animationValueChanged(QVariant)));
        animation->start();
        remainTimer=new QTimer();
        connect(remainTimer,SIGNAL(timeout()),this,SLOT(closeAnimation()));
        remainTimer->start(mremainTime*4);
    }
}

void PopDialog::animationValueChanged(QVariant param_value)
{
    QPoint tempValue = param_value.toPoint();
}

void PopDialog::closeAnimation(){
    if(!mIsPause){
        remainTimer->stop();
        disconnect(remainTimer,SIGNAL(timeout()),this,SLOT(closeAnimation()));
        delete remainTimer;
        remainTimer=NULL;
        animation->setStartValue(QPoint(this->x(),this->y()));
        animation->setEndValue(QPoint((desktop.availableGeometry().width()-this->width()),desktop.availableGeometry().height()+50));
        animation->start();
        connect(animation,SIGNAL(finished()),this,SLOT(clearAll()));
    }
}

void PopDialog::clearAll(){
    if(animation != NULL){
        disconnect(animation,SIGNAL(finished()),this,SLOT(clearAll()));
        delete animation;
    }
    animation=NULL;
    hide();
}
