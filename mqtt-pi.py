'''
MQTT Pi
Author: Sawyer Travis
Sends MQTT message based on macro key press
'''
import paho.mqtt.publish as publish
import time
import keyboard

# Set hostname for MQTT broker
BROKER = "mqtt.eclipseprojects.io"

# read key presses and publish to MQTT broker till keyboard interrupt
while True:
    key = keyboard.read_key()
    print(key)

    if key == 'esc':    # exit on esc key
        break

    publish.single("hacks/keypad", str(key), hostname=BROKER)
    time.sleep(0.1) # debouncing delay 