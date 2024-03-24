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
	//���Ʊ���
	enum SwitchFlags
	{
		//Ĭ������
		defaultText = 0x00000001,
		//��Ȧ����ɫ
		linearColor = 0x00000004,
		//װ��Բ��
		decorateDot = 0x00000008,
		//��Ȧ
		outterCirle = 0x0000000e,
		//����
		animation = 0x00000010,
		//��ʾ����Ч��
		all = 0xffffffff
	};
	//�ڲ�����չʾ��ʽ
	enum InnerDefaultTextStyle
	{
		//�ٷֱ�
		percent = 0x00000001,
		//ֵ
		value = 0x00000002,
		//ֵ�����ֵ
		valueAndMax = 0x00000004
	};

	//���ó�ʼ�Ƕȣ�˳ʱ����ʱ��
	void setdefault(int, bool);
	//�����߿�
	void setBarWidth(int);
	//���÷�Χ
	void setRange(float, float);
	//���õ�ǰֵ
	void setValue(float);
	//������Ȧ��ɫ
	void setBGColor(const QColor&);
	//������Ȧ����ɫ
	void setChangeColor(const QColor&);
	//����Ĭ��������ɫ
	void setDefaultTextColor(const QColor&);
	//���ÿ�������
	void setControlFlags(int);
	//������ʾ���־���
	void setPrecision(int);
	//������ȦĬ��������ʽ
	inline void setInnerDefaultTextStyle(InnerDefaultTextStyle style) { _innerDefaultTextStyle = style; }

	//��ȡ��ǰֵ
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
	//��Ȧ��ɫ
	QColor _bgColor;
	//��Ȧ������ɫ
	QColor _changeColor;
	//outterBar���
	int _barWidth=10;
private:
	//��ʼ�Ƕ� ��Χ0-360
	int _startAngle;
	//˳ʱ��
	bool _clockWise;
	
	//Բ���������
	float _dotX;
	float _dotY;
	//��Сֵ,���ֵ����ǰֵ
	float _min;
	float _max;
	
	//Ĭ��������ɫ
	QColor _textColor;
	//С���㾫��
	int _precision;
	//������������Ϣ
	float _squareStart;
	float _squareWidth;
	//�����ź�
	quint32 _controlFlags = 0x00000000;
	//��ȦĬ��������ʽ
	InnerDefaultTextStyle _innerDefaultTextStyle;

	//������Ȧ
	void paintBGBar(QPainter&);
	//������Ȧ
	void paintChangeBar(QPainter&);
	//����װ��Բ��
	void paintDot(QPainter&);
	//����Ĭ����������
	void paintText(QPainter&);
	//���õ�ǰֵ
	void _setValue(float);


};

#endif // CircleProgressBar_H
