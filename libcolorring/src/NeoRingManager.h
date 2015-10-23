
#ifndef __NEORINGMANAGER_H_
#define __NEORINGMANAGER_H_

#include <QObject>
#include <QColor>
extern "C" {
#include "clk.h"
#include "gpio.h"
#include "dma.h"
#include "pwm.h"
#include "ws2811.h"
#include "board_info.h"
}

class NeoRingManager: public QObject
{
	Q_OBJECT
public:

	NeoRingManager( int width, int height, int pin = 18, int freq = WS2811_TARGET_FREQ, int dma = 5, bool invert = false, int brightness = 255, int channel = 0, QObject *parent = 0 );
	virtual ~NeoRingManager();


public slots:

	virtual void show();
    virtual void setPixelColor( int x, int y, QColor color );
    virtual void setPixelColorRGB( int x, int y, unsigned char r, unsigned char g, unsigned char b );
    virtual void setBrightness( int brightness );
    virtual void setPixelBrightness( int x, int y, int brightness );


public :

    QColor getPixelColor( int x, int y );
    int numPixels();


protected:

    int m_dma;
    int m_gpio;
    int m_freq;
    int m_width;
    int m_height;
    bool m_invert;
    int m_brightness;

    int m_ledCount;


private:

    ws2811_led_t *m_matrix;





    bool m_initialized;

    //NeoRingLeds m_leds;

};


#endif
