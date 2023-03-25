# CalvinHacks-2023
The 2023 CalvinHacks Project Files

This project is an entry as part of 2023 [Calvin Hacks](calvinhacks.org).

# Objective

Create a mechanical keypad that triggers sound effects. The keypad interacts with a BlackPill controller that is connected to a computer. This computer publishes a MQTT that is then received by all listeners that then play the audio effect.

# Hardware

* [STM32F411CE](https://www.adafruit.com/product/4877#technical-details) "BlackPill"
* Raspberry PI 4
* 16x Brown Cherry Switches
* 16x Kailh Hot Swaps
* 16x 1N4148 Diodes
* 1x Custom PCB
* 4x Pull Down Resistors

# Installation

This project uses the Arduino IDE for writing and compiling. To connect with the BlackPill, the [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html#overview) was used.
* Configuration settings to connect with the BlackPill came from [this tutorial](https://www.sgbotic.com/index.php?dispatch=pages.view&page_id=49)
* The board configuration URL in the previous tutorial is depreciated. This url was used instead:
    ```https://www.sgbotic.com/index.php?dispatch=pages.view&page_id=49```
