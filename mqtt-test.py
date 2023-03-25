'''
MQTT Test
Author: Sawyer Travis (sjt29)
Sends test messages to the MQTT broker (dev purposes only)
'''
import paho.mqtt.publish as publish
import time

# Set hostname for MQTT broker
BROKER = "mqtt.eclipseprojects.io"

key = 0

# send keystrokes 0 and 1 to the broker every 10 seconds
while True:
    publish.single("hacks/keypad", str(key), hostname=BROKER)
    if key == 0:
        key = 1
    else :
        key = 0
    print(key)
    time.sleep(10)