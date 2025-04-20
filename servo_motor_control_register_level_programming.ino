#define F_CPU 80000000UL  // ESP8266 runs at 80 MHz by default

// Define the GPIO pin for the servo (GPIO5, which corresponds to D1 on NodeMCU)
#define SERVO_PIN 2  // GPIO5 corresponds to D1

// Set the timer interrupt for 50 Hz PWM (20ms period)
#define PWM_FREQUENCY 50  // 50 Hz (20ms period)
#define PULSE_MIN 1000     // 1ms pulse for 0 degrees

#define PULSE_MAX 2000     // 2ms pulse for 180 degrees

// Function to set up GPIO for PWM output (simple method)
void setupServoPin() {
  // Set GPIO5 as output
  GPIO_REG_WRITE(GPIO_ENABLE_W1TS_ADDRESS, (1 << SERVO_PIN));  // Set GPIO5 as an output
}

// Generate PWM signal with specific pulse width (in microseconds)
void generatePWM(uint16_t pulseWidth) {
  // Toggle the pin: pulse high for the duration of pulseWidth, then low for the remaining time.
  // We are generating a 50Hz PWM signal with a 20ms period
  uint32_t pulseHighDuration = pulseWidth;  // In microseconds
  uint32_t pulseLowDuration = 20000 - pulseHighDuration;  // Remaining time for 20ms period

  // Set the pin high for the pulseWidth duration
  GPIO_REG_WRITE(GPIO_OUT_W1TS_ADDRESS, (1 << SERVO_PIN));  // Set GPIO5 high
  delayMicroseconds(pulseHighDuration);                     // Wait for the high pulse duration
  
  // Set the pin low for the rest of the period
  GPIO_REG_WRITE(GPIO_OUT_W1TC_ADDRESS, (1 << SERVO_PIN));  // Set GPIO5 low
  delayMicroseconds(pulseLowDuration);                      // Wait for the low duration
}

void setup() {
  // Initialize the GPIO pin for the servo motor
  setupServoPin();
}

void loop() {
  // Sweep the servo from 0° to 180° and back
  for (int angle = 0; angle <= 18; angle++) {
    // Calculate the pulse width for the current angle
    uint16_t pulseWidth = map(angle, 0, 180, PULSE_MIN, PULSE_MAX);
    
    // Generate the PWM signal with the calculated pulse width
    generatePWM(pulseWidth);
    
    // Wait for the next cycle (20ms)
    delay(10);  // 50Hz PWM (20ms period)
  }

  // Reverse direction: Sweep back from 180° to 0°
  for (int angle = 18; angle >= 0; angle--) {
    uint16_t pulseWidth = map(angle, 0, 180, PULSE_MIN, PULSE_MAX);
    generatePWM(pulseWidth);
    delay(10);  // Wait for the next cycle
  }
}
