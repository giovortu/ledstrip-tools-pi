
#include "NeoRingManager.h"
#include <QDebug>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

 static ws2811_t m_ledstring;

static void ctrl_c_handler(int signum)
{
    ws2811_fini(&m_ledstring);
}

static void setup_handlers(void)
{
    struct sigaction sa;

    sa .sa_handler = ctrl_c_handler;

    sigaction(SIGKILL, &sa, NULL);
}




NeoRingManager::NeoRingManager(int width, int height, int gpio, int freq,int dma, bool invert, int brightness, int channel, QObject* parent):QObject( parent )
{


	m_ledCount = width * height;
	m_width = width;
	m_height = height;
	m_gpio = gpio;
	m_dma = dma;
	m_invert = invert;
	m_brightness = brightness;
	m_freq = freq;

    m_matrix = new ws2811_led_t [m_ledCount];


	for (int x = 0; x < m_ledCount; x++)
	{
		m_matrix[ x ] = 0;
	}



	m_initialized = false;

	m_ledstring.freq = m_freq;
	m_ledstring.dmanum = m_dma;

	m_ledstring.channel[0].gpionum = m_gpio;
	m_ledstring.channel[0].count = m_ledCount;
	m_ledstring.channel[0].invert = m_invert?1:0;
	m_ledstring.channel[0].brightness = brightness;

	m_ledstring.channel[1].gpionum = 0;
	m_ledstring.channel[1].count = 0;
	m_ledstring.channel[1].invert = 0;
	m_ledstring.channel[1].brightness = 0;


	if (board_info_init() >= 0)
	{
		setup_handlers();

		if (0 == ws2811_init( &m_ledstring))
		{
			m_initialized = true;
			qWarning() << "INIT ok";
		}
		else
   		  qWarning() << "Error initializing led string";

	}
	else
		qWarning() << "Error initializing board";

	show();




}

NeoRingManager::~NeoRingManager()
{
	if ( m_initialized )
	{
		ws2811_fini( &m_ledstring );
	}

    delete [] m_matrix;

}

void NeoRingManager::show()
{
	if ( !m_initialized ) return;

	for (int x = 0; x < m_ledCount; x++)
	{
		m_ledstring.channel[0].leds[ x ] = m_matrix[ x ];
	}

	int resp = ws2811_render( &m_ledstring );

	if ( resp != 0 )
		qWarning() << "ws2811_render failed with code " << resp;
}

void NeoRingManager::setPixelColor(int x, int y, QColor color)
{
	if ( !m_initialized ) return;

	if ( x > m_width || y > m_height )
	{
		qWarning() << "Pixels out of range";
		return;
	}

	ws2811_led_t col = (color.red() <<16 ) | ( color.green() << 8 ) | color.blue();



	m_matrix[ y * m_width + x ] = col;

	show();

}

void NeoRingManager::setPixelColorRGB(int x, int y, unsigned char r,unsigned char g, unsigned char b)
{
	if ( !m_initialized ) return;


	if ( x > m_width || y > m_height )
	{
		qWarning() << "Pixels out of range";
		return;
	}

	ws2811_led_t col = ( r <<16 ) | ( g<< 8 ) | b;

	m_matrix[ y * m_width + x ] = col;


	show();

}

void NeoRingManager::setBrightness(int brightness)
{
	Q_UNUSED( brightness)
	//ws2811_channel_t_brightness_set( g_channel, brightness);
}

void NeoRingManager::setPixelBrightness(int x, int y, int brightness)
{
	Q_UNUSED( x)
	Q_UNUSED( y)
	Q_UNUSED( brightness)
}

QColor NeoRingManager::getPixelColor(int x, int y)
{
	Q_UNUSED( x)
	Q_UNUSED( y)
	return QColor(m_matrix[ y * m_width + x ] );
}

int NeoRingManager::numPixels()
{
	return m_ledCount;
}


