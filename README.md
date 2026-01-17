# Wind Direction Sensor with Arduino

This project reads wind direction using an 8-position analog wind vane sensor (SN-3000-FXJT-V05) connected to an Arduino Uno.

## Hardware Required

- Arduino Uno
- Wind Direction Sensor: SN-3000-FXJT-V05 (8-position, 0-5V analog output)
- Power Supply: 10-30V DC (recommended: 4x 3.7V Li-ion batteries in series = 14.8V)
- Jumper wires

## Sensor Specifications

- **Model:** SN-3000-FXJT-V05
- **Type:** 8-direction analog wind vane
- **Output:** 0-5V analog voltage
- **Power Input:** 10-30V DC
- **Directions:** N, NE, E, SE, S, SW, W, NW

## Wiring Diagram

### Sensor to Arduino (with external 14.8V battery pack):

```
Battery Pack (14.8V)    →    Wind Sensor Wire    →    Arduino Uno
─────────────────────────────────────────────────────────────────
(+) 14.8V               →    Brown (Power +)     
(-) GND                 →    Black (Power -)     
(-) GND                 →    Yellow/Green (Out-) →    GND
                        →    Blue (Output +)     →    A3 (Analog Pin)
```

**Important:** Connect battery GND to Arduino GND for common ground reference.

### Sensor Wire Colors:
- **Brown:** Power positive (10-30V)
- **Black:** Power negative (GND)
- **Blue:** Signal output positive (0-5V)
- **Yellow/Green:** Signal output negative (GND)

## Installation

1. Clone this repository:
```bash
git clone https://github.com/yourusername/wind-direction-sensor.git
```

2. Open `wind_direction_sensor.ino` in Arduino IDE

3. Connect the hardware as shown in the wiring diagram

4. Upload the code to your Arduino Uno

5. Open Serial Monitor (9600 baud) to view readings

## Code Calibration

The default voltage ranges are estimated. For accurate readings, you need to calibrate:

1. Upload the calibration sketch (see `calibration.ino`)
2. Manually rotate the vane to each of the 8 positions
3. Record the voltage for each direction
4. Update the voltage ranges in `getWindDirection()` function

### Example Calibration:
```cpp
// Default ranges (update with your actual readings)
if (voltage >= 0.0 && voltage < 0.6) return "N";
else if (voltage >= 0.6 && voltage < 1.2) return "NE";
// ... etc
```

## Usage

Once uploaded and calibrated, the sensor will output:
- Raw ADC value (0-1023)
- Voltage (0-5V)
- Wind direction (N, NE, E, SE, S, SW, W, NW)

Example output:
```
Raw: 512 | Voltage: 2.50V | Direction: S
Raw: 307 | Voltage: 1.50V | Direction: E
```

## Troubleshooting

**Problem:** Only getting 4 directions instead of 8
- **Solution:** Sensor needs higher input voltage (10-30V). Use external battery pack instead of Arduino 5V.

**Problem:** Always reading "N"
- **Solution:** Check wiring connections. Verify blue wire is connected to A3 and sensor has power.

**Problem:** Incorrect direction readings
- **Solution:** Calibrate the sensor by recording actual voltages for each position.

## Files in this Repository

- `wind_direction_sensor.ino` - Main program
- `calibration.ino` - Calibration sketch to find voltage ranges
- `README.md` - This file
- `LICENSE` - MIT License

## Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)

## Author

Your Name - [@yourusername](https://github.com/yourusername)

## Acknowledgments

- Shandong Shengbao Electronic Technology Co., Ltd (Sensor manufacturer)
- Arduino Community
