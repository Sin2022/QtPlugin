#ifndef CIRCLEPROGRESSBAR_H
#define CIRCLEPROGRESSBAR_H


#define QDESIGNER_EXPORT_WIDGETS

#include <QWidget>
#include <QPainter>
#include "QtUiPlugin/QDesignerExportWidget"



#define Abs(x) ((x)>=0?(x):-(x))

class QDESIGNER_WIDGET_EXPORT circleprogressbar : public QWidget
{
	Q_OBJECT
		Q_PROPERTY(double _value READ getValue WRITE _setValue)
		Q_PROPERTY(QColor _bgColor READ getBGColor WRITE setBGColor)
		Q_PROPERTY(QColor _changeColor READ getChangeColor WRITE setChangeColor)
		Q_PROPERTY(int _barWidth READ getBarWidth WRITE setBarWidth)

public:
    explicit circleprogressbar(QWidget* parent = nullptr);
    ~circleprogressbar();
	//控制变量
	enum SwitchFlags
	{
		//默认文字
		defaultText = 0x00000001,
		//内圈渐变色
		linearColor = 0x00000004,
		//装饰圆点
		decorateDot = 0x00000008,
		//外圈
		outterCirle = 0x0000000e,
		//动画
		animation = 0x00000010,
		//显示所有效果
		all = 0xffffffff
	};
	//内部文字展示样式
	enum InnerDefaultTextStyle
	{
		//百分比
		percent = 0x00000001,
		//值
		value = 0x00000002,
		//值与最大值
		valueAndMax = 0x00000004
	};

	//设置初始角度，顺时针逆时针
	void setdefault(int, bool);
	//设置线宽
	void setBarWidth(int);
	//设置范围
	void setRange(float, float);
	//设置当前值
	void setValue(float);
	//设置外圈颜色
	void setBGColor(const QColor&);
	//设置内圈渐变色
	void setChangeColor(const QColor&);
	//设置默认文字颜色
	void setDefaultTextColor(const QColor&);
	//设置控制命令
	void setControlFlags(int);
	//设置显示数字精度
	void setPrecision(int);
	//设置内圈默认文字样式
	inline void setInnerDefaultTextStyle(InnerDefaultTextStyle style) { _innerDefaultTextStyle = style; }

	//获取当前值
	inline float getValue() { return _value; }
	inline QColor getBGColor() { return _bgColor; }
	inline QColor getChangeColor() { return _changeColor; }
	inline int getBarWidth() { return _barWidth; }

protected:
	void resizeEvent(QResizeEvent*);
	void paintEvent(QPaintEvent*);
	void caculateSquare();
public:
	double _value;
	//外圈颜色
	QColor _bgColor;
	//内圈渐变颜色
	QColor _changeColor;
	//outterBar宽度
	int _barWidth=10;
private:
	//起始角度 范围0-360
	int _startAngle;
	//顺时针
	bool _clockWise;
	
	//圆点矩形坐标
	float _dotX;
	float _dotY;
	//最小值,最大值，当前值
	float _min;
	float _max;
	
	//默认文字颜色
	QColor _textColor;
	//小数点精度
	int _precision;
	//绘制正方形信息
	float _squareStart;
	float _squareWidth;
	//控制信号
	quint32 _controlFlags = 0x00000000;
	//内圈默认文字样式
	InnerDefaultTextStyle _innerDefaultTextStyle;

	//绘制外圈
	void paintBGBar(QPainter&);
	//绘制内圈
	void paintChangeBar(QPainter&);
	//绘制装饰圆点
	void paintDot(QPainter&);
	//绘制默认内置文字
	void paintText(QPainter&);
	//设置当前值
	void _setValue(float);


};

#endif // CircleProgressBar_H
