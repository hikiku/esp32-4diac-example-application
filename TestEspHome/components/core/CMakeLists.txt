idf_component_register(SRCS 
                        "helpers.cpp"
                        "component.cpp"
                        "application.cpp"
                        "scheduler.cpp"
                        "log.cpp"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES logger)
