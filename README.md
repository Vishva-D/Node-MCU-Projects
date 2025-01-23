## Node-MCU-Projects
✔This repository consists of hobby projects conducted using Node MCU - ESP8266.
![image](https://github.com/user-attachments/assets/c0a5246c-fae0-4521-99af-92af1f859769)

✔Our ultimate goal is to low-level register manipulations are specific to the ESP8266/ESP32 platform.

🤔Why do we need this? or If someone asks me why did you do this here is the answer --> Normally, in an easier-to-use language like Arduino C++, you can just call digitalWrite() to control pins, but this is slower and less efficient for low-level control. 

By using registers, you can: 

    1.)Directly control the hardware (no middleman like a function).
  
    2.)Make things happen faster because you're working at the hardware level.
  
    3.)Access special features (like timers, interrupts, or custom settings) that aren't available in high-level code.
  
    4.)Using registers like this gives you complete control over how the microcontroller operates and interacts with hardware like LEDs, motors, sensors, etc.

✔The following diagram depicts the pin out diagram for NodeMCU ESP8266.
![image](https://github.com/user-attachments/assets/48ce891b-8c3b-49c9-807b-cd57ce505d76)


