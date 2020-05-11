Used Adafruit Trinket (ATtiny85 @ 8 MHz). I had to place the boards.txt file in

  C:\Users\<user>\AppData\Local\Arduino15\packages\adafruit\hardware\avr\1.4.13\boards.txt

I had to modify in boards.txt

  trinket3.upload.maximum_size=8192

to accept compilation for the larger firmware.

AVR Fuse bytes:
  extended: 0xFF
  high: 0xD7
  low: 0xE2


Hex file needs to be burned via ISP.
