 

#ifndef __RGBLED__
#define __RGBLED__

#include <QObject>
#include <QColor>
#include <wiringPi.h>
#include <softPwm.h>

#define PWM_RANGE 100

class RGBLed : public QObject
{

	Q_OBJECT

public:

	RGBLed( QObject *parent = 0);
	RGBLed( int pinRed, int pinGreen, int pinBlue,QColor col, QObject *parent = 0);
	virtual ~RGBLed();

public slots:

	virtual void initRGBLed(int pinRed, int pinGreen, int pinBlue, QColor col );
	virtual void setColor(  QColor color );

protected:

	int m_pinRed;
	int m_pinGreen;
	int m_pinBlue;
};



#endif
