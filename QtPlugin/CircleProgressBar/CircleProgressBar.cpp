#include "circleprogressbar.h"
#include "qmath.h"
#include <QPropertyAnimation>
#include <QDebug>

circleprogressbar::circleprogressbar(QWidget* parent) :
    QWidget(parent), _value(0), _min(0), _max(100), _precision(0)
{
    setdefault(90, true);
}

circleprogressbar::~circleprogressbar()
{
}

//********************************************** 外部接口 ****************************************
//设置初始角度，顺时针逆时针
void circleprogressbar::setdefault(int startAngle, bool clockWise)
{
    _startAngle = startAngle;
    _clockWise = clockWise;
}

//设置外圈宽度
void circleprogressbar::setBarWidth(int width)
{
    _barWidth = width;
}

//设置值的范围
void circleprogressbar::setRange(float min, float max)
{
    //todo 和value比较
    if (max < min)
    {
        max = 100;
        min = 0;
    }
    else
    {
        _max = max;
        _min = min;
    }
}

//设置当前值
void circleprogressbar::setValue(float value)
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "_value");
    animation->setDuration(500);
    animation->setStartValue(_value);
    animation->setEndValue(value);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->start();
}

void circleprogressbar::_setValue(float value)
{
    _value = value;
    repaint();
}

//设置外圈颜色
void circleprogressbar::setBGColor(const QColor& bgColor)
{
    _bgColor = bgColor;
}

//设置内圈渐变色
void circleprogressbar::setChangeColor(const QColor& changeColor)
{
    _changeColor = changeColor;
}

void circleprogressbar::setDefaultTextColor(const QColor& textColor)
{
    _textColor = textColor;
}

//设置控制
void circleprogressbar::setControlFlags(int flags)
{
    this->_controlFlags |= flags;
}

//设置显示数字精度
void circleprogressbar::setPrecision(int precision)
{
    _precision = precision;
}

void circleprogressbar::resizeEvent(QResizeEvent* event)
{   
        this->setMinimumSize(_barWidth * 8, _barWidth * 8);
    //计算绘制正方形区域信息
    caculateSquare();
}

void circleprogressbar::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //绘制外圈
    paintBGBar(painter);
    //绘制内圈
    paintChangeBar(painter);
    //绘制外圈
    paintDot(painter);
    //绘制文字
    paintText(painter);
}

//计算绘制正方形区域信息
void circleprogressbar::caculateSquare()
{
    int minWidth = qMin(this->width(), this->height());
    _squareWidth = minWidth - _barWidth - 2;
    _squareStart = _barWidth / 2 + 1;
    _dotX = _squareStart + _squareWidth / 2;
    _dotY = _squareStart;
}

//绘制外圈
void circleprogressbar::paintBGBar(QPainter& painter)
{
    if (!(_controlFlags & outterCirle))
        return;
    QPen pen;
    pen.setWidth(_barWidth);
    pen.setColor(_bgColor);
    painter.setPen(pen);
    QRectF rectangle(_squareStart, _squareStart, _squareWidth, _squareWidth);
    //从90度开始，逆时针旋转
    painter.drawEllipse(rectangle);
}

//绘制内圈
void circleprogressbar::paintChangeBar(QPainter& painter)
{
    QPen pen;

    pen.setColor(_changeColor);
  
    pen.setWidth(_barWidth);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    QRectF rectangle(_squareStart, _squareStart, _squareWidth, _squareWidth);
    //从90度开始，逆时针旋转
    int startAngle = _startAngle * 16;
    int spanAngle = (_value - _min) / (_max - _min) * 360 * 16 * (_clockWise ? -1 : 1);
    painter.drawArc(rectangle, startAngle, spanAngle);
}

//绘制装饰圆点
void circleprogressbar::paintDot(QPainter& painter)
{
    if (!(_controlFlags & decorateDot))
        return;
    
    painter.setPen(QColor(255, 255, 255));
    painter.setBrush(QColor(255, 255, 255));
    //区域为圆点绘制正方形区域
   // painter.drawEllipse(_dotX - _barWidth / 6, _dotY - _barWidth / 6, _barWidth / 3, _barWidth / 3);
}

//绘制默认内置文字
void circleprogressbar::paintText(QPainter& painter)
{
    if (!(_controlFlags & defaultText))
        return;
    painter.setPen(_textColor);
    painter.setFont(QFont("Microsoft YaHei", 22, 75));
    switch (_innerDefaultTextStyle) {
    case value:
        painter.drawText(_squareStart, _squareStart, _squareWidth, _squareWidth, Qt::AlignCenter, QString::number(_value, 'f', _precision));
        break;
    case valueAndMax:
        painter.drawText(_squareStart, _squareStart, _squareWidth, _squareWidth, Qt::AlignCenter,
            QString::number(_value, 'f', _precision) + "/" + QString::number(_max, 'f', _precision));
        break;
    case percent:
        painter.drawText(_squareStart, _squareStart, _squareWidth, _squareWidth, Qt::AlignCenter,
            QString::number(_value / _max * 100, 'f', _precision) + "%");
        break;
    default:
        break;
    }
}


