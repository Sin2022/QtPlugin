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

//********************************************** �ⲿ�ӿ� ****************************************
//���ó�ʼ�Ƕȣ�˳ʱ����ʱ��
void circleprogressbar::setdefault(int startAngle, bool clockWise)
{
    _startAngle = startAngle;
    _clockWise = clockWise;
}

//������Ȧ���
void circleprogressbar::setBarWidth(int width)
{
    _barWidth = width;
}

//����ֵ�ķ�Χ
void circleprogressbar::setRange(float min, float max)
{
    //todo ��value�Ƚ�
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

//���õ�ǰֵ
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

//������Ȧ��ɫ
void circleprogressbar::setBGColor(const QColor& bgColor)
{
    _bgColor = bgColor;
}

//������Ȧ����ɫ
void circleprogressbar::setChangeColor(const QColor& changeColor)
{
    _changeColor = changeColor;
}

void circleprogressbar::setDefaultTextColor(const QColor& textColor)
{
    _textColor = textColor;
}

//���ÿ���
void circleprogressbar::setControlFlags(int flags)
{
    this->_controlFlags |= flags;
}

//������ʾ���־���
void circleprogressbar::setPrecision(int precision)
{
    _precision = precision;
}

void circleprogressbar::resizeEvent(QResizeEvent* event)
{   
        this->setMinimumSize(_barWidth * 8, _barWidth * 8);
    //�������������������Ϣ
    caculateSquare();
}

void circleprogressbar::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //������Ȧ
    paintBGBar(painter);
    //������Ȧ
    paintChangeBar(painter);
    //������Ȧ
    paintDot(painter);
    //��������
    paintText(painter);
}

//�������������������Ϣ
void circleprogressbar::caculateSquare()
{
    int minWidth = qMin(this->width(), this->height());
    _squareWidth = minWidth - _barWidth - 2;
    _squareStart = _barWidth / 2 + 1;
    _dotX = _squareStart + _squareWidth / 2;
    _dotY = _squareStart;
}

//������Ȧ
void circleprogressbar::paintBGBar(QPainter& painter)
{
    if (!(_controlFlags & outterCirle))
        return;
    QPen pen;
    pen.setWidth(_barWidth);
    pen.setColor(_bgColor);
    painter.setPen(pen);
    QRectF rectangle(_squareStart, _squareStart, _squareWidth, _squareWidth);
    //��90�ȿ�ʼ����ʱ����ת
    painter.drawEllipse(rectangle);
}

//������Ȧ
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
    //��90�ȿ�ʼ����ʱ����ת
    int startAngle = _startAngle * 16;
    int spanAngle = (_value - _min) / (_max - _min) * 360 * 16 * (_clockWise ? -1 : 1);
    painter.drawArc(rectangle, startAngle, spanAngle);
}

//����װ��Բ��
void circleprogressbar::paintDot(QPainter& painter)
{
    if (!(_controlFlags & decorateDot))
        return;
    
    painter.setPen(QColor(255, 255, 255));
    painter.setBrush(QColor(255, 255, 255));
    //����ΪԲ���������������
   // painter.drawEllipse(_dotX - _barWidth / 6, _dotY - _barWidth / 6, _barWidth / 3, _barWidth / 3);
}

//����Ĭ����������
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


