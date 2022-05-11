#if defined(ESP8266)
  #define PIN_SW     D5
  #define PIN_SCL    D1
  #define PIN_SDA    D2
  #define PIN_DHT    D3
  #define PIN_SW     D5
  #define LED_GREEN  D6
  #define LED_YELLOW D7
  #define LED_RED    D8
#elif defined(ESP32_CAM)
  #if !defined(LED_BUILTIN) // ESP32Cam
    #define LED_BUILTIN 33
  #endif
  #define LED_FLASH   4
  #define LED_RED     2
  #define LED_YELLOW 12
  #define LED_GREEN  16
  #define PIN_SW      0
  #define PIN_DHT    13 // pin 2, 12: program failed, 16: dht read error
  #define PIN_SDA    14
  #define PIN_SCL    15
#elif defined(NODEMCU_ESP32_C3_13)
  #define LED_BUILTIN_RED GPIO_NUM_3
  #define LED_BUILTIN_GREEN GPIO_NUM_4
  #define LED_BUILTIN_BLUE GPIO_NUM_5
  #define LED_BUILTIN_COOL GPIO_NUM_19
  #define LED_BUILTIN_WARM GPIO_NUM_18
  #define LED_BUILTIN LED_BUILTIN_WARM
  #define LED_RED     LED_BUILTIN_RED
  #define LED_YELLOW  LED_BUILTIN_WARM
  #define LED_GREEN   LED_BUILTIN_GREEN
  #define PIN_SW     6
  #define PIN_SDA    1
  #define PIN_SCL    2
  // #define PIN_DHT    2 // pin 2, 12: program failed, 16: dht read error
  
#endif

#define LED_BUILTIN_ON  0
#define LED_BUILTIN_OFF 1

#define LED_ON  1
#define LED_OFF 0
