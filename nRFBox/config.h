/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Push Buttons-specific Pins (Atualizado conforme sua lista)
#define BUTTON_UP_PIN       17 // Botão 1 Cima (Cinza)
#define BUTTON_DOWN_PIN     14 // Botão 2 Baixo (Vermelho)
#define BUTTON_SELECT_PIN   32 // Botão 3 Select (Marrom)
#define BTN_PIN_RIGHT       33 // Botão 4 (Preto)
#define BTN_PIN_LEFT        21 // Pino dummy para manter retrocompatibilidade com menus

// SD Card Slot-specific Pins
#define SD_CS_PIN 5
#define FIRMWARE_FILE "/firmware.bin"

// nRF24-specific Pins (Atualizado)
#define NRF_CE_PIN_A    25 // Amarelo
#define NRF_CSN_PIN_A   26 // Azul

// Pinos falsos para os rádios B e C para não quebrar a lógica do "ProtoKill"
#define NRF_CE_PIN_B    22  
#define NRF_CSN_PIN_B   13  
#define NRF_CE_PIN_C    12  
#define NRF_CSN_PIN_C   15  

// CC1101-specific Pins (Novos pinos)
#define CC_CSN_PIN      27 // Roxo
#define CC_GDO0_PIN     4  // Azul
#define CC_GDO2_PIN     16 // Laranja

// SPI Pins Compartilhados 
#define SPI_SCK         18 // SCK NRF (Verde) / SCK CC1101 (Amarelo)
#define SPI_MISO        19 // MI NRF (Cinza) / MISO CC1101 (Vermelho)
#define SPI_MOSI        23 // MO NRF (Roxo) / MOSI CC1101 (Verde)

// Common dependencies
#include "setting.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <Preferences.h>
#include <vector>
#include <string>
#include <SD.h>
#include <Update.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

Adafruit_NeoPixel pixels(1, 14, NEO_GRB + NEO_KHZ800);

// BLE-specific dependencies
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// nRF24-specific dependencies
#include <nRF24L01.h>
#include <RF24.h>

// WiFi-specific dependencies
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <esp_system.h>
#include <esp_event.h>
#include <nvs_flash.h>
#include <string>

// ESP-specific configurations
#include <esp_bt.h>
#include <esp_wifi.h>

// External declarations
extern bool neoPixelActive;
extern uint8_t oledBrightness;

// BLE-related namespaces
namespace BleJammer {
  void blejammerSetup();
  void blejammerLoop();
}

namespace BleScan {
  void blescanSetup();
  void blescanLoop();
}

namespace SourApple {
  void sourappleSetup();
  void sourappleLoop();
}

namespace Spoofer {
  void spooferSetup();
  void spooferLoop();
}

// nRF24-related namespaces
namespace Analyzer {
  void analyzerSetup();
  void analyzerLoop();
}

namespace ProtoKill {
  void blackoutSetup();
  void blackoutLoop();
}

namespace Scanner {
  void scannerSetup();
  void scannerLoop();
}

namespace Jammer {
  void jammerSetup();
  void jammerLoop();
}

// CC1101-related namespaces (NOVO)
namespace SubGHz {
  void subGhzSetup();
  void subGhzLoop();
}

// Hardware Test namespace (NOVO)
namespace HwTest {
  void testSetup();
  void testLoop();
}

// WiFi-related namespaces
namespace WifiScan {
  void wifiscanSetup();
  void wifiscanLoop();
}

namespace Deauther {
  void deautherSetup();
  void deautherLoop();
}

#endif // CONFIG_H
