idf_component_register(SRCS "wifi_component.cpp" "wifi_component_esp_idf.cpp"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES network core esp32_core)
