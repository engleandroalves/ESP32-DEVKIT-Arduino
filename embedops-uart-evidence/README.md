# EmbedOps UART Evidence Firmware

Minimal ESP32 DevKit V1 Arduino sketch for EmbedOps hardware validation.

It emits deterministic UART markers at 115200 baud:

```text
EMBEDOPS_BOOT
BOARD=ESP32_DEVKIT_V1
UART_BAUD=115200
BOOT_OK
TEST_PASS
```

The main loop toggles the default LED, usually GPIO 2 on ESP32 DevKit V1, and prints:

```text
HEARTBEAT_OK
```

These stable ASCII markers are intended for EmbedOps post-flash UART capture and assertions.
