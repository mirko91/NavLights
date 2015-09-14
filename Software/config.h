//User configurable parameters

#include "arduino.h"

// I/O setup
#define strobePin     10
#define landPin       9
#define navPin        11
#define beaconPin     6
#define rcPin         2    //interrupt 0
#define led           13    //on-board led

// timing setup
#define strobeOff     1250
#define strobeOn      45
#define dblinkPause   90
#define beaconPause   2500

// rc pulses
#define offCtrl       1350
#define landCtrl      1650

// eeprom setup
#define strobe_addr    0
#define land_addr      1
#define nav_addr       2
#define beacon_addr    3
#define dblink_addr    4
#define hw_addr        20
#define hw1_addr       21
#define sw_addr        22
#define sw1_addr       23
#define sn_addr        24
#define sn1_addr       25
#define sn2_addr       26
#define sn3_addr       27

// Variables
byte strobePWM = 250;
byte landPWM = 37;
byte navPWM = 7;
byte beaconPWM = 40; // real PWM = 2*PWM

// Misc
#define OFF            0
