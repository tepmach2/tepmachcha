//  Customize these items for each installation
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#ifndef SECRETS

// stalker version
#define STALKERv30
#define STALKERv31

// shield version
#define SHIELDv1
#define SHIELDv2

#define TESTPHONE     "+85512345678"
#define APN           "FONAapn"

#define DMISSENSOR_ID "DMIS sensor id"
#define DMISAPIBEARER "YOUR_BEARER_ID"

#define EWSTOKEN_ID   "EWS_TOKEN"
#define EWSDEVICE_ID  "EWS_DEVICE"
// max 24 chars:
#define DWEETDEVICE_ID "TEP" EWSDEVICE_ID

#define FTPPW         "FTP PASSWORD"
#define FTPUSER       "FTP USER"
#define FTPSERVER     "FTP SERVER"
#define FTPPATH       "/home/ftpuser/files/"
#define FOTAPASSWORD  "FOTA_PASSWORD"  // Password to trigger FOTA update
#define FLASHPASSWORD "FLASH_PASSWORD" // Password to flash app from SD file
#define PINGPASSWORD  "PING_PASSWORD"  //  Password to return info/status sms
#define BEEPASSWORD   "XBEE_PASSWORD"  // Password to turn on XBee by SMS

#define KEY1          0x01020304       // Encryption key 128 bits
#define KEY2          0x05060708
#define KEY3          0x090a0b0c
#define KEY4          0x0d0e0f00

// 10m sonar
#define SONAR_MIN 550       // minumum sonar range (mm)
#define SONAR_MAX 9750      // maximum sonar range (mm)

// 5m sonar
//#define SONAR_MIN 350       // minumum sonar range (mm)
//#define SONAR_MAX 4900      // maximum sonar range (mm)

#define SENSOR_HEIGHT  500  //  Height of top of octagonal gasket from streambed (cm)
#define UTCOFFSET        7  //  Local standard time variance from UTC
#define XBEEWINDOWSTART 14  //  Hour to turn on XBee for programming window
#define XBEEWINDOWEND   17  //  Hour to turn off XBee
#define INTERVAL        15  //  Number of minutes between readings
#endif
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
