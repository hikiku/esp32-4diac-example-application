/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "test_led_strip.h"


void app_main(void)
{
    printf("Hello world!\n");


    test_led_strip();

}
