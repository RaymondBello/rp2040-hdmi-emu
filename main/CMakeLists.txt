if (TARGET tinyusb_device)

        add_executable(main main.cpp config.h)

        # Pull in our pico_stdlib which pulls in commonly used features
        target_link_libraries(main pico_stdlib hardware_i2c hardware_pio r6502)

        # enable usb output, disable uart output
        pico_enable_stdio_usb(main 1)
        pico_enable_stdio_uart(main 0)

        # create map/bin/hex file etc.
        pico_add_extra_outputs(main)

elseif(PICO_ON_DEVICE)
        message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()