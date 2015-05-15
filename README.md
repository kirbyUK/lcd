lcd
===

Simple program for writing to a Raspberry Pi LCD. It is set up to work with
[16x2](http://www.adafruit.com/product/181) LCDs, set up following Adafruit's
[tutorial](https://learn.adafruit.com/drive-a-16x2-lcd-directly-with-a-raspberry-pi).

Usage
-----

Usage is easy enough, but requires root. From the program's own help:

```
A simple program to output to the 16x2 LCD screen.
Requires root!
	-h				Display this help and exit.
	-1=[string]		Print [string] to the 1st row.
	-2=[string]		Print [string] to the 2nd row.
	-c				Clear the screen.
```

Building
--------

The program requires the [wiringPi](http://wiringpi.com) library, instructs to install
are located on the website. Once installed, building this program is as simple
as

```
make
sudo make install
```
