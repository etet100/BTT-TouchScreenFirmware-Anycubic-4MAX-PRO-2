#ifndef _PIN_TFT35_V2_0_H_  // modify to actual filename !!!
#define _PIN_TFT35_V2_0_H_  // modify to actual filename !!!

// MCU type (STM32F10x, STM32F2xx, STM32F4xx)
#include "stm32f10x.h"

// Portrait Mode support
// Comment the following line in case the TFT variant supports Portrait Mode
//#undef PORTRAIT_MODE

// LCD resolution, font and icon size
#ifndef TFT_RESOLUTION
  #define TFT_RESOLUTION
  #ifdef PORTRAIT_MODE
    #include "./Resolution/TFT_320X480.h"
  #else
    #include "./Resolution/TFT_480X320.h"
  #endif
#endif

// Update folder for fonts and icons
#ifndef UPDATE_DIR
  #define UPDATE_DIR "TFT35"
#endif

// Hardware manufacturer
#ifndef HARDWARE_MANUFACTURER
  #define HARDWARE_MANUFACTURER "BIGTREETECH_"
#endif

// Hardware version config
#ifndef HARDWARE_VERSION
  #define HARDWARE_VERSION "TFT35_V2.0"
#endif

// Software manufacturer
#ifndef SOFTWARE_MANUFACTURER
  #define SOFTWARE_MANUFACTURER HARDWARE_VERSION"."
#endif

// Debug support (free pins for other functions)
// Free JTAG (PB3/PB4) for SPI3
#define DISABLE_JTAG() RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); \
                       GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE)

// XPT2046 Software SPI pins for touch screen
// It needs CS/SCK/MISO/MOSI for Software SPI and TPEN for pen interrupt
#define XPT2046_CS   PC0
#define XPT2046_SCK  PB3
#define XPT2046_MISO PB4
#define XPT2046_MOSI PB5
#define XPT2046_TPEN PC1

// W25Qxx SPI Flash Memory pins
#define W25Qxx_SPEED  1      // stm32f103 spi1 max 4 division
#define W25Qxx_SPI    _SPI1
#define W25Qxx_CS_PIN PA4

// LCD interface
// Supported LCD drivers: [ST7789, SSD1963, RM68042, NT35310, ILI9488, ILI9341, ILI9325, HX8558]
#ifndef TFTLCD_DRIVER
  #define TFTLCD_DRIVER       (ILI9488 | NT35310)
  #define TFTLCD_DRIVER_SPEED 0x03
#endif

// FSMC 8080 interface (high speed) or normal IO interface (low speed)
#ifndef STM32_HAS_FSMC
  #define STM32_HAS_FSMC
#endif

// LCD data 16bit or 8bit
#ifndef LCD_DATA_16BIT
  #define LCD_DATA_16BIT 1
#endif

// SERIAL_PORT:   communicating with host (Marlin, RRF etc...)
// SERIAL_PORT_X: communicating with other controllers (Octoprint, ESP3D, other UART Touch Screen etc...)
#ifndef SERIAL_PORT
  #define SERIAL_PORT   _USART1  // default USART port
  #define SERIAL_PORT_2 _USART2
  #define SERIAL_PORT_3 _USART3
  //#define SERIAL_PORT_4 _UART4
#endif

// Serial port for debugging
#ifdef SERIAL_DEBUG_ENABLED
  #define SERIAL_DEBUG_PORT SERIAL_PORT_3
#endif

// SD Card SPI pins
#ifndef SD_SPI_SUPPORT
  //#define SD_SPI_SUPPORT
  //#define SD_LOW_SPEED   7      // 2^(SPEED+1) = 256 frequency division
  //#define SD_HIGH_SPEED  0      // 2 frequency division
  //#define SD_SPI         _SPI2
  //#define SD_CS_PIN      PB12
#endif

// SD Card SDIO support
#ifndef SD_SDIO_SUPPORT
  #define SD_SDIO_SUPPORT
#endif

// SD Card CD Detect pin
#ifndef SD_CD_PIN
  #define SD_CD_PIN PC6
#endif

// Power Supply Auto Shutdown Detection pin
#ifndef PS_ON_PIN
  #define PS_ON_PIN PD12
#endif

// Filament Runout Detection pin
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN PD11
#endif

// Buzzer PWM pin
#ifndef BUZZER_PIN
  #define BUZZER_PIN PB2
#endif

#endif
