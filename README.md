# ESP32 4DIAC Example Application

Refer to [esp32 4diac example application](https://gitlab.com/meisterschulen-am-ostbahnhof-munchen/esp32-4diac-example-application).

## Docs

See [here](https://github.com/hikiku/4diac-forte-esp32-component).

## TODO

Add some submodules for git:

* lua

    ```ini
    [submodule "Application/components/4diac-forte-esp32-component"]
	path = Application/components/4diac-forte-esp32-component
	url = git@github.com:hikiku/4diac-forte-esp32-component.git
    ```

* 4diac-forte-esp32-component

    ```ini
    [submodule "Application/components/lua"]
	path = Application/components/lua
	url = git@github.com:hikiku/alt-esp-idf-lua.git
    ```

* org.eclipse.4diac.forte

    ```ini
    [submodule "org.eclipse.4diac.forte"]
        path = org.eclipse.4diac.forte
        url = https://git.eclipse.org/r/4diac/org.eclipse.4diac.forte.git
    ```




