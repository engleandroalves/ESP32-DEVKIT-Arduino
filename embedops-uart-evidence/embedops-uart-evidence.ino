#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

static const unsigned long kBootDelayMs = 1000;
static const unsigned long kHeartbeatMs = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
  delay(kBootDelayMs);

  Serial.println("EMBEDOPS_BOOT");
  Serial.println("BOARD=ESP32_DEVKIT_V1");
  Serial.println("UART_BAUD=115200");
  Serial.println("BOOT_OK");
  Serial.println("TEST_PASS");
}

void loop() {
  static bool ledState = false;
  static unsigned long lastHeartbeat = 0;
  unsigned long now = millis();

  if (now - lastHeartbeat >= kHeartbeatMs) {
    lastHeartbeat = now;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
    Serial.println("HEARTBEAT_OK");
  }
}
