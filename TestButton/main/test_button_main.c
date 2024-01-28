/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "iot_button.h"
#include "esp_log.h"

static const char *TAG = "example";

#define BUTTON_IO_NUM  26
#define BUTTON_ACTIVE_LEVEL   0
#define BUTTON_NUM 16

static button_handle_t g_btns[BUTTON_NUM] = {0};

static int get_btn_index(button_handle_t btn)
{
    for (size_t i = 0; i < BUTTON_NUM; i++) {
        if (btn == g_btns[i]) {
            return i;
        }
    }
    return -1;
}

static void button_press_normal_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_PRESS_NORMAL", get_btn_index((button_handle_t)arg));
}

static void button_press_down_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_PRESS_DOWN", get_btn_index((button_handle_t)arg));
}

static void button_press_up_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_PRESS_UP[%d]", get_btn_index((button_handle_t)arg), iot_button_get_ticks_time((button_handle_t)arg));
}

static void button_press_repeat_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_PRESS_REPEAT[%d]", get_btn_index((button_handle_t)arg), iot_button_get_repeat((button_handle_t)arg));
}

static void button_single_click_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_SINGLE_CLICK", get_btn_index((button_handle_t)arg));
}

static void button_double_click_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_DOUBLE_CLICK", get_btn_index((button_handle_t)arg));
}

static void button_long_press_start_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_LONG_PRESS_START", get_btn_index((button_handle_t)arg));
}

static void button_long_press_hold_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_LONG_PRESS_HOLD[%d],count is [%d]", get_btn_index((button_handle_t)arg), iot_button_get_ticks_time((button_handle_t)arg), iot_button_get_long_press_hold_cnt((button_handle_t)arg));
}

static void button_press_repeat_done_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "BTN%d: BUTTON_PRESS_REPEAT_DONE[%d]", get_btn_index((button_handle_t)arg), iot_button_get_repeat((button_handle_t)arg));
}



void app_main(void)
{
    printf("Hello world!\n");


    button_config_t cfg = {
        .type = BUTTON_TYPE_GPIO,
        .long_press_time = CONFIG_BUTTON_LONG_PRESS_TIME_MS,
        .short_press_time = CONFIG_BUTTON_SHORT_PRESS_TIME_MS,
        .gpio_button_config = {
            .gpio_num = BUTTON_IO_NUM,
            .active_level = BUTTON_ACTIVE_LEVEL,
        },
    };
    g_btns[0] = iot_button_create(&cfg);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_NORMAL, button_press_normal_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_DOWN, button_press_down_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_UP, button_press_up_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_REPEAT, button_press_repeat_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_SINGLE_CLICK, button_single_click_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_DOUBLE_CLICK, button_double_click_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_LONG_PRESS_START, button_long_press_start_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_LONG_PRESS_HOLD, button_long_press_hold_cb, NULL);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_REPEAT_DONE, button_press_repeat_done_cb, NULL);







}
