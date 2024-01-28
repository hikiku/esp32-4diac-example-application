idf_component_register(SRCS 
                         "core.cpp"
                         "preferences.cpp"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES 
                    core 
                    nvs_flash
                    main)
