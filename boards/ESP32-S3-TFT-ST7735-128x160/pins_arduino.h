#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

static const uint8_t TX = 43;
static const uint8_t RX = 44;

static const uint8_t TXD2 = 1;
static const uint8_t RXD2 = 2;

static const uint8_t SDA = 13;
static const uint8_t SCL = 15;

// Modified elsewhere
static const uint8_t SS = 6;
static const uint8_t MOSI = 4;
static const uint8_t MISO = 8;
static const uint8_t SCK = 6;

static const uint8_t G0 = 0;
static const uint8_t G1 = 1;
static const uint8_t G2 = 2;
static const uint8_t G3 = 3;
static const uint8_t G4 = 4;
static const uint8_t G5 = 5;
static const uint8_t G6 = 6;
static const uint8_t G7 = 7;
static const uint8_t G8 = 8;
static const uint8_t G9 = 9;
static const uint8_t G10 = 10;
static const uint8_t G11 = 11;
static const uint8_t G12 = 12;
static const uint8_t G13 = 13;
static const uint8_t G14 = 14;
static const uint8_t G15 = 15;
static const uint8_t G39 = 39;
static const uint8_t G40 = 40;
static const uint8_t G41 = 41;
static const uint8_t G42 = 42;
static const uint8_t G43 = 43;
static const uint8_t G44 = 44;
static const uint8_t G46 = 46;

static const uint8_t ADC1 = 7;
static const uint8_t ADC2 = 8;

#define FM_RSTPIN 40
#define PIN_CLK 43
#define I2S_SCLK_PIN 43
#define I2S_DATA_PIN 46
#define PIN_DATA 46

// #define HAS_RGB_LED 1
#define RGB_LED 38

#define BCLK 41
#define WCLK 43
#define DOUT 42

#define BAD_TX GROVE_SDA
#define BAD_RX GROVE_SCL

#define HAS_BTN 1
#define HAS_5_BUTTONS 1
#define BTN_ALIAS "\"Ok\""
// #define BTN_PIN 0
// #define BTN_ACT HIGH
#define BTN_ACT LOW
#define UP_BTN 1
#define SEL_BTN 41
#define DW_BTN 42
#define ESC_BTN 39
#define R_BTN 2
#define L_BTN 40

#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT 160

#define USER_SETUP_LOADED 1
#define USE_HSPI_PORT 1
#define ST7735_DRIVER 1
#define ST7735_BLACKTAB 1
#define TFT_RGB_ORDER TFT_RGB
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
// #define TFT_WIDTH 160
// #define TFT_HEIGHT 128
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 16
#define TFT_RST 15
#define TFT_DC 7
#define TFT_MOSI 4
#define TFT_SCLK 5
#define TFT_CS 6
// #define TOUCH_CS -1
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 20000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

#define SPI_SCK_PIN 5
#define SPI_MOSI_PIN 4
#define SPI_MISO_PIN 8
#define SPI_SS_PIN 6

#endif /* Pins_Arduino_h */
