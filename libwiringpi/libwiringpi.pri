

INCLUDEPATH += $$PWD/ $$PWD/src/wiringpi 
DEPENDPATH += $$PWD/ $$PWD/src/wiringpi 
# Input
HEADERS += $$PWD/src/wiringpi/drcSerial.h \
           $$PWD/src/wiringpi/max31855.h \
           $$PWD/src/wiringpi/max5322.h \
           $$PWD/src/wiringpi/mcp23008.h \
           $$PWD/src/wiringpi/mcp23016.h \
           $$PWD/src/wiringpi/mcp23016reg.h \
           $$PWD/src/wiringpi/mcp23017.h \
           $$PWD/src/wiringpi/mcp23s08.h \
           $$PWD/src/wiringpi/mcp23s17.h \
           $$PWD/src/wiringpi/mcp23x08.h \
           $$PWD/src/wiringpi/mcp23x0817.h \
           $$PWD/src/wiringpi/mcp3002.h \
           $$PWD/src/wiringpi/mcp3004.h \
           $$PWD/src/wiringpi/mcp3422.h \
           $$PWD/src/wiringpi/mcp4802.h \
           $$PWD/src/wiringpi/pcf8574.h \
           $$PWD/src/wiringpi/pcf8591.h \
           $$PWD/src/wiringpi/sn3218.h \
           $$PWD/src/wiringpi/softPwm.h \
           $$PWD/src/wiringpi/softServo.h \
           $$PWD/src/wiringpi/softTone.h \
           $$PWD/src/wiringpi/sr595.h \
           $$PWD/src/wiringpi/wiringPi.h \
           $$PWD/src/wiringpi/wiringPiI2C.h \
           $$PWD/src/wiringpi/wiringPiSPI.h \
           $$PWD/src/wiringpi/wiringSerial.h \
           $$PWD/src/wiringpi/wiringShift.h \
           $$PWD/src/wiringpi/wpiExtensions.h
           
SOURCES += $$PWD/src/wiringpi/drcSerial.c \
           $$PWD/src/wiringpi/max31855.c \
           $$PWD/src/wiringpi/max5322.c \
           $$PWD/src/wiringpi/mcp23008.c \
           $$PWD/src/wiringpi/mcp23016.c \
           $$PWD/src/wiringpi/mcp23017.c \
           $$PWD/src/wiringpi/mcp23s08.c \
           $$PWD/src/wiringpi/mcp23s17.c \
           $$PWD/src/wiringpi/mcp3002.c \
           $$PWD/src/wiringpi/mcp3004.c \
           $$PWD/src/wiringpi/mcp3422.c \
           $$PWD/src/wiringpi/mcp4802.c \
           $$PWD/src/wiringpi/pcf8574.c \
           $$PWD/src/wiringpi/pcf8591.c \
           $$PWD/src/wiringpi/piHiPri.c \
           $$PWD/src/wiringpi/piThread.c \
           $$PWD/src/wiringpi/sn3218.c \
           $$PWD/src/wiringpi/softPwm.c \
           $$PWD/src/wiringpi/softServo.c \
           $$PWD/src/wiringpi/softTone.c \
           $$PWD/src/wiringpi/sr595.c \
           $$PWD/src/wiringpi/wiringPi.c \
           $$PWD/src/wiringpi/wiringPiI2C.c \
           $$PWD/src/wiringpi/wiringPiSPI.c \
           $$PWD/src/wiringpi/wiringSerial.c \
           $$PWD/src/wiringpi/wiringShift.c \
           $$PWD/src/wiringpi/wpiExtensions.c
