'''
MQTT Test
Author: Sawyer Travis
Sends test messages to the MQTT broker
'''
import paho.mqtt.publish as publish
import time

# Set hostname for MQTT broker
BROKER = "mqtt.eclipseprojects.io"

key = 0

while True:
    publish.single("hacks/keypad", str(key), hostname=BROKER)
    if key == 0:
        key = 1
    else :
        key = 0
    print(key)
    time.sleep(10)