if (TARGET tinyusb_device)

add_executable(lab2b_blink)

target_sources(lab2b_blink PRIVATE blink.c)

target_link_libraries(lab2b_blink PRIVATE pico_stdlib)
pico_add_extra_outputs(lab2b_blink)

pico_enable_stdio_usb(lab2b_blink 1)
pico_enable_stdio_uart(lab2b_blink 0)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building lab2b_blink because TinyUSB submodule is not initialized in the SDK")
endif()