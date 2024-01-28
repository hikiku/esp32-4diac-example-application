/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"


#include "application.h"
#include "logger.h"
#include "wifi_component.h"


using namespace esphome;

void setup() {
  App.pre_setup("livingroom", __DATE__ ", " __TIME__, false);
  auto *log = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);  // NOLINT
  log->pre_setup();
  App.register_component(log);

  auto *wifi = new wifi::WiFiComponent();  // NOLINT
  App.register_component(wifi);
  wifi::WiFiAP ap;
  ap.set_ssid("Test SSID");
  ap.set_password("password1");
  wifi->add_sta(ap);


  App.setup();
}

void loop() { App.loop(); }
