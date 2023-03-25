'''
MQTT Computer
Author: Sawyer Travis
Plays music files based on MQTT messages
'''
import paho.mqtt.client as mqtt
from playsound import playsound

# Constants
PORT = 1883
QOS = 0

# Set hostname for MQTT broker
BROKER = 'mqtt.eclipseprojects.io'

# Callback when connecting to the MQTT broker
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe("hacks/keypad", qos=QOS)

# Callback when client receives a PUBLISH message from the broker
def on_message(client, data, msg):
    if msg.topic == 'hacks/keypad':
        message = msg.payload
        print(f'Received message: Key = {message}')
        sound = ""
        if message == b'0' :
            sound = "audio/pls-dont-click-By-Tuna.mp3"
        elif message == b'1' :
            sound = "audio/emotional-damage-meme.mp3"
        elif message == b'2' :
            sound = "audio/k.o.-sound-effect-By-Tuna.mp3"
        elif message == b'3' :
            sound = "audio/anime-wow-sound-effect.mp3"
        elif message == b'4' :
            sound = "audio/metal-pipe-falling-By-Tuna.mp3"
        elif message == b'5' :
            sound = "audio/fortnite-default-dance-bass-boosted.mp3"
        elif message == b'6' :
            sound = "audio/kowalski-analysis.mp3"
        elif message == b'7' :
            sound = "audio/obi-wan-hello-there.mp3"
        elif message == b'8' :
            sound = "audio/tim_and_eric_it_s_free_real_estate.mp3"
        elif message == b'9' :
            sound = "audio/vine-boom.mp3"
        elif message == b'a' :
            sound = "audio/maro-jump-sound-effect_1.mp3"
        elif message == b'b' :
            sound = "audio/lego-breaking.mp3"
        elif message == b'c' :
            sound = "audio/loud-noti.mp3"
        elif message == b'd' :
            sound = "audio/nfl.mp3"
        elif message == b'e' :
            sound = "audio/bruh.mp3"

        # play sound if it exists
        if sound != "" :
            print("Playing sound: " + sound)
            playsound(sound, 0)
            print("Sound finished")

# Setup MQTT client and callbacks
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# Connect to MQTT broker and subscribe to the button topic
client.connect(BROKER, PORT, 60)
client.loop_forever()