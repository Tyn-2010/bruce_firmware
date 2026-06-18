#include "core/powerSave.h"
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    pinMode(UP_BTN, INPUT_PULLUP);
    pinMode(SEL_BTN, INPUT_PULLUP);
    pinMode(ESC_BTN, INPUT_PULLUP);
    pinMode(DW_BTN, INPUT_PULLUP);
    pinMode(R_BTN, INPUT_PULLUP);
    pinMode(L_BTN, INPUT_PULLUP);
}

/***************************************************************************************
** Function name: _post_setup_gpio()
** Location: main.cpp
** Description:   second stage gpio setup to make a few functions work
***************************************************************************************/
void _post_setup_gpio() {
    bruceConfig.colorInverted = 0;
    bruceConfig.setColorInverted(0);
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
    static unsigned long tm = 0;

    // 1. Entprellung (Debounce) & Reaktionszeit optimieren:
    // 1000ms ist viel zu lang für normale Klicks! 150-200ms fühlt sich flüssig an.
    if (millis() - tm < 200 && !LongPress) return;

    // Digitale Pegel einlesen (Invertiert wegen INPUT_PULLUP)
    bool _u = !digitalRead(UP_BTN);
    bool _d = !digitalRead(DW_BTN);
    bool _l = !digitalRead(L_BTN);
    bool _r = !digitalRead(R_BTN);
    bool _s = !digitalRead(SEL_BTN);
    bool _esc = !digitalRead(ESC_BTN); // Deinen neuen ESC-Pin einlesen!

    // Prüfen, ob ÜBERHAUPT eine Taste gedrückt wurde
    if (_s || _u || _d || _r || _l || _esc) {
        tm = millis();
        if (!wakeUpScreen()) {
            AnyKeyPress = true;
        } else {
            return; // Wenn der Bildschirm nur aufgewacht ist, Klick noch nicht auswerten
        }
    } else {
        return; // Keine Taste gedrückt? Dann sofort abbrechen.
    }

    // 2. Einzelne Tastendrücke zuweisen
    if (_l) { PrevPress = true; }
    if (_r) { NextPress = true; }
    if (_u) {
        UpPress = true;
        PrevPagePress = true;
    }
    if (_d) {
        DownPress = true;
        NextPagePress = true;
    }
    if (_s) { SelPress = true; }

    // 3. Dedizierten ESC-Button auswerten (Saubere Lösung via GPIO 39)
    if (_esc) { EscPress = true; }
}

/*********************************************************************
** Function: keyboard
** location: mykeyboard.cpp
** Starts keyboard to type data
**********************************************************************/
// String keyboard(String current_text, int max_size, String textbox_title, bool mask_input) {
//     #include "core/mykeyboard.h"
//     String lang = bruceConfig.keyboardLang;
//     if (lang == "AZERTY") {
//         return generalKeyboard<azerty_keyboard_height, azerty_keyboard_width>(
//             current_text, max_size, textbox_title, azerty_keyset, mask_input
//         );
//     } else if (lang == "QWERTZ") {
//         return generalKeyboard<qwertz_keyboard_height, qwertz_keyboard_width>(
//             current_text, max_size, textbox_title, qwertz_keyset, mask_input
//         );
//     } else {
//         // Default: QWERTY
//         return generalKeyboard<qwerty_keyboard_height, qwerty_keyboard_width>(
//             current_text, max_size, textbox_title, qwerty_keyset, mask_input
//         );
//     }
// }

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turn off the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
