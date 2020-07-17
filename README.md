# embedded prowl notification transmitter

- to be used with prowlapp.com api key that can be registered on their website
- credential are stored in the credentials.h file in the include folder, just rename the credentials.h.example file and set your own Wifi SSID, Wifi password and api key
- builds in PlatformIO
- the upload speed is set to 1500000 baud in platformio.ini, change it to 115200 baud if you run into problems when uploading
- the compiler flag -Wno-write-strings can be set to ignore the warning "deprecated conversion from string constant to ‘char*’"

## credits

- https://github.com/marcos69 for creating the library
