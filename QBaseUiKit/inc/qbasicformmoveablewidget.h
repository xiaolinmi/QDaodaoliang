﻿#ifndef QBASICFORMMOVEABLEWIDGET_H
#define QBASICFORMMOVEABLEWIDGET_H

#include "qbaseuikit_global.h"
#include <QWidget>
#include <QPoint>
#include <QCursor>
#include <QRect>

/*接受边框处理的宽度*/
#define PADDING 2

/*!
 * \brief The QBasicFormMoveableWidget class
 *  可以拖动大小、可移动的窗体
 */

/*!
 * \brief The Direction enum
 *  鼠标方向
 */
enum Direction{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};

/*!
 * \brief The MOVEPLAN enum
 *  窗体移动方案
 */
enum MOVEPLAN{
    PLANA,
    PLANB
};

/*!
 * \brief The QBasicFormMoveableWidget class
 *  可移动、可拖拽修改尺寸widget
 */

class QBASEUIKITSHARED_EXPORT QBasicFormMoveableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QBasicFormMoveableWidget(QWidget *parent = 0);
    MOVEPLAN move_plan() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool winEvent(MSG *message, long *result);

private:
    void region(const QPoint &cursorGlobalPoint);
    void setMove_plan(const MOVEPLAN &move_plan);

private:
    bool isLeftPressDown_;
    QPoint dragPosition_;
    Direction dir_;
    MOVEPLAN move_plan_;
};

#endif // QBASICFORMMOVEABLEWIDGET_H
