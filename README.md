# ApolloBVM - re-nanashi version #
###### Original Author: Thomas Herring ######

## System Overview ##
The ApolloBVM system uses two coordinated microcontrollers in order to facilitate user input while guaranteeing uninterrupted airflow. The system has a master controller, responsible for managing the display and user input, and a slave controller that actually sends motor commands to the servos. This allows the master controller to operate entirely separately from the slave and ensures that the system is real-time safe. In order to give more clarity about the technical operation of this device, we will outline the operation of each controller separately.

In order to facilitate the various functions of the device, the slave controller operates in 3 distinct states: load, on, and off. While in the ‘load’ state, the slave controller will read ventilation parameters from the master over the I2C bus, generate a new trajectory with these parameters, and turn its state to ‘on’. While in the ‘on’ state, the device will follow the trajectory over and over for infinity. This means that the slave controller will never stop moving the motors unless it receives a command from the master to change its state to ‘stop’. If the master controller were to do so, the device would finish its current cycle and stop moving.

The master controller is mainly tasked with running the user display and sending commands to the slave. Internally, the master switches which panel is currently displaying and manages input from the encoder and buttons. Each panel that the master displays is programmed to follow a different behavior and is modular. This makes it easy to implement panels that behave completely differently and interact with the slave controller on the fly.



## Installation Instructions ##
1. Download the latest Arduino IDE from their website [here](https://www.arduino.cc/en/Main/Software).
2. Download the latest posted release of the device firmware [here](https://github.com/apollobvm/apollobvm/releases), it should look something like "apollobvm_X.X.X.zip".
3. Unzip the downloaded release.
3.  Add the ApolloBVM library to the Arduino IDE:
    1. In the Arduino IDE, go to Sketch->Include Library->Add .ZIP Library...
    2. Navigate to and click on the library zip or library directory inside the extracted release. This will be a file that looks like "ApolloBVM.zip" or a directory with the name "ApolloBVM".
4. Open the slave and master code.
    1. In the Arduino IDE, go to File->Open...
    2. Navigate to and click on the slave.ino file inside the extracted release.
    3. Repeat this process for the master.ino file.
5. Flash the Arduino boards with the firmware.
    1. Plug the first Arduino board into your computer.
    2. In the Arduino IDE, go to Tools->Board and select the Arduino board you are using.
    3. Next, in the Arduino IDE, go to Tools->Port and select the port for your Arduino board.
    4. Push the arrow button to upload code on the Arduino IDE window with the slave code.
    5. Unplug the first Arduino, plug in the second, and repeat the above step for the master code.
6. Follow the wiring diagram on the [ApolloBVM website](http://oedk.rice.edu/apollobvm) to complete assembly.
    

