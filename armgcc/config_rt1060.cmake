# # config to select component, the format is CONFIG_USE_${component}
# set(CONFIG_USE_driver_enet_MIMXRT1062 true)
# set(CONFIG_USE_middleware_lwip_enet_ethernetif_MIMXRT1062 true)
# set(CONFIG_USE_component_mflash_rt1060_MIMXRT1062 true)
# set(CONFIG_USE_middleware_mbedtls_rt_MIMXRT1062 true)
# # set(CONFIG_USE_middleware_freertos-aws_iot_libraries_coremqtt_MIMXRT1062 true)
# set(CONFIG_USE_middleware_freertos-aws_iot_libraries_corehttp_MIMXRT1062 true)

# set(CONFIG_USE_component_serial_manager_uart_MIMXRT1062 true)
# set(CONFIG_USE_driver_lpuart_MIMXRT1062 true)

# config to select component, the format is CONFIG_USE_${component}
set(CONFIG_USE_component_serial_manager_uart true)
set(CONFIG_USE_driver_lpuart true)
set(MCUX_DEVICE "MIMXRT1062")