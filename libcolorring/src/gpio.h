/*
 * gpio.h
 *
 * Copyright (c) 2014 Jeremy Garff <jer @ jers.net>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 *     1.  Redistributions of source code must retain the above copyright notice, this list of
 *         conditions and the following disclaimer.
 *     2.  Redistributions in binary form must reproduce the above copyright notice, this list
 *         of conditions and the following disclaimer in the documentation and/or other materials
 *         provided with the distribution.
 *     3.  Neither the name of the owner nor the names of its contributors may be used to endorse
 *         or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__


typedef struct
{
    unsigned int fsel[6];                            // GPIO Function Select
    unsigned int resvd_0x18;
    unsigned int set[2];                             // GPIO Pin Output Set
    unsigned int resvd_0x24;
    unsigned int clr[2];                             // GPIO Pin Output Clear
    unsigned int resvd_0x30;
    unsigned int lev[2];                             // GPIO Pin Level
    unsigned int resvd_0x3c;
    unsigned int eds[2];                             // GPIO Pin Event Detect Status
    unsigned int resvd_0x48;
    unsigned int ren[2];                             // GPIO Pin Rising Edge Detect Enable
    unsigned int resvd_0x54;
    unsigned int fen[2];                             // GPIO Pin Falling Edge Detect Enable
    unsigned int resvd_0x60;
    unsigned int hen[2];                             // GPIO Pin High Detect Enable
    unsigned int resvd_0x6c;
    unsigned int len[2];                             // GPIO Pin Low Detect Enable
    unsigned int resvd_0x78;
    unsigned int aren[2];                            // GPIO Pin Async Rising Edge Detect
    unsigned int resvd_0x84;
    unsigned int afen[2];                            // GPIO Pin Async Falling Edge Detect
    unsigned int resvd_0x90;
    unsigned int pud;                                // GPIO Pin Pull up/down Enable
    unsigned int pudclk[2];                          // GPIO Pin Pull up/down Enable Clock
    unsigned int resvd_0xa0[4];
    unsigned int test;
} __attribute__((packed)) gpio_t;


#define GPIO_OFFSET                              (0x00200000)


static inline void gpio_function_set(volatile gpio_t *gpio, unsigned char pin, unsigned char function)
{
    int regnum = pin / 10;
    int offset = (pin % 10) * 3;
    unsigned char funcmap[] = { 4, 5, 6, 7, 3, 2 };  // See datasheet for mapping

    if (function > 5)
    {
        return;
    }

    gpio->fsel[regnum] &= ~(0x7 << offset);
    gpio->fsel[regnum] |= ((funcmap[function]) << offset);
}

static inline void gpio_level_set(volatile gpio_t *gpio, unsigned char pin, unsigned char level)
{
    int regnum = pin >> 5;
    int offset = (pin & 0x1f);

    if (level)
    {
        gpio->set[regnum] = (1 << offset);
    }
    else
    {
        gpio->clr[regnum] = (1 << offset);
    }
}

static inline void gpio_output_set(volatile gpio_t *gpio, unsigned char pin, unsigned char output)
{
    int regnum = pin / 10;
    int offset = (pin % 10) * 3;
    unsigned char function = output ? 1 : 0;  // See datasheet for mapping

    gpio->fsel[regnum] &= ~(0x7 << offset);
    gpio->fsel[regnum] |= ((function & 0x7) << offset);
}

#endif /* __GPIO_H__ */
