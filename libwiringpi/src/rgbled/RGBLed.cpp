
#include "RGBLed.h"
#include <QDebug>

RGBLed::RGBLed( QObject *parent):QObject( parent ),
m_pinRed(-1),
m_pinGreen(-1),
m_pinBlue(-1)
{


}

RGBLed::RGBLed(int pinRed, int pinGreen, int pinBlue, QColor col , QObject* parent):QObject( parent )
{
	initRGBLed( pinRed, pinGreen, pinBlue, col );
	qWarning() << "INIT " <<pinRed<< pinGreen<< pinBlue<< col;
}

RGBLed::~RGBLed()
{

}

void RGBLed::initRGBLed(int pinRed, int pinGreen, int pinBlue,  QColor col )
{
	if ( col.isValid() )
	{
		if ( pinRed > 0 )
		{
			m_pinRed = pinRed;
			pinMode(m_pinRed, OUTPUT);
			if ( 0 != softPwmCreate ( m_pinRed,  col.redF() * PWM_RANGE , PWM_RANGE) )
			{
				qWarning() << "Errore nella creazione del PWN RED";
			}
		}

		if ( pinGreen > 0 )
		{
			m_pinGreen = pinGreen;
			pinMode(m_pinGreen, OUTPUT);
			if ( 0 != softPwmCreate ( m_pinGreen,col.greenF() * PWM_RANGE , PWM_RANGE) )
			{
				qWarning() << "Errore nella creazione del PWN RED";
			}
		}

		if ( pinBlue > 0 )
		{
			m_pinBlue = pinBlue;
			pinMode(m_pinBlue, OUTPUT);
			if ( 0 != softPwmCreate ( m_pinBlue, col.blueF() * PWM_RANGE , PWM_RANGE) )
			{
				qWarning() << "Errore nella creazione del PWN RED";
			}
		}
	}

}

void RGBLed::setColor( QColor col )
{
	if ( col.isValid() )
	{
		if ( m_pinRed > 0 )
		{
			softPwmWrite ( m_pinRed,  col.redF() * PWM_RANGE ) ;
		}

		if ( m_pinGreen > 0 )
		{
			softPwmWrite ( m_pinGreen,col.greenF() * PWM_RANGE ) ;
		}

		if ( m_pinBlue > 0 )
		{
			softPwmWrite ( m_pinBlue, col.blueF() * PWM_RANGE ) ;
		}
	}
}
