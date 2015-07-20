This is used to test the VBAT function available on the Photon.

Currently [as of firmware V0.4.3] only the Real-time clock feature is demonstrated here.

Things required:

Photon
Coin-cell battery or any separate power supply <3.
USB cable
Normally-opened button
Setup:

Hook up the VBAT supply
Hook up a button to D0 (or any other GPIO but remember to change the code!) and 3.3V
Hold on to the button and power up the Photon. This will tell the Photon to connect to Wifi and sync time
If you have not entered Wifi credentials, please do so before that.
Once you see that the D7 led is blinking, open a serial terminal at 9600baud and watch it print out the time stamp
When you are happy with what you see, unplug the USB cable and let the Photon be alone.
Come back after some coffee and plug back the USB cable but DO NOT press the button
Open a serial terminal again and check the time-stamp smile
Reference:
- https://community.particle.io/t/getting-the-internal-rtc-to-work-on-photon/12875/17
- http://docs.particle.io/photon/photon-datasheet/#3-2-pin-description

The code is here: https://github.com/kennethlimcp/particle-examples/tree/master/photon-vbat

Community post: https://community.particle.io/t/photon-vbat-rtc-demonstation/13501
