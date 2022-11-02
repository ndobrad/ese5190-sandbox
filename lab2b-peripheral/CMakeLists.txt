if (TARGET tinyusb_device)

add_executable(lab2b_amt102v)

target_sources(lab2b_amt102v PRIVATE pcf8574.c peripheral_test.c)

target_include_directories(lab2b_amt102v PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(lab2b_amt102v PRIVATE pico_stdlib hardware_i2c)
pico_add_extra_outputs(lab2b_amt102v)

pico_enable_stdio_usb(lab2b_amt102v 1)
pico_enable_stdio_uart(lab2b_amt102v 0)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building lab2b_amt102v
 because TinyUSB submodule is not initialized in the SDK")
endif()