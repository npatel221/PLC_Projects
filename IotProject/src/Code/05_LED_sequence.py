#!/usr/bin/python3
# -*- coding: utf-8 -*-
import mraa
import sys
import os
import time

''' File location for LEDs'''
greenLed0 = "/sys/class/leds/user-led0-green/brightness"
redLed0 = "/sys/class/leds/user-led0-red/brightness"
greenLed1 = "/sys/class/leds/user-led1-green/brightness"
redLed1 = "/sys/class/leds/user-led1-red/brightness"

# Set LED0 to GREEN
file = open(greenLed0, "w")
file.write("1")
file.close()
time.sleep(1)

# Set LED1 to GREEN
file = open(greenLed1, "w")
file.write("1")
file.close()
time.sleep(1)

# Set LED0 to ORANGE
file = open(redLed0, "w")
file.write("1")
file.close()
time.sleep(1)

# Set LED1 to ORANGE
file = open(redLed1, "w")
file.write("1")
file.close()
time.sleep(1)

# Set LED0 to RED
file = open(greenLed0, "w")
file.write("0")
file.close()
time.sleep(1)

# Set LED1 to RED
file = open(greenLed1, "w")
file.write("0")
file.close()
time.sleep(1)

# Set LED0 to OFF
file = open(redLed0, "w")
file.write("0")
file.close()
time.sleep(1)

# Set LED1 to OFF
file = open(redLed1, "w")
file.write("0")
file.close()
time.sleep(1)