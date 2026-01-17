const int WIND_DIRECTION_PIN = A3;

void setup() {
  Serial.begin(9600);
  pinMode(WIND_DIRECTION_PIN, INPUT);
}

void loop() {
  int rawValue = analogRead(WIND_DIRECTION_PIN);
  float voltage = (rawValue / 1023.0) * 5.0;
  String direction = getWindDirection(voltage);
  
  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Direction: ");
  Serial.println(direction);
  
  delay(1000);
}

String getWindDirection(float voltage) {
  if (voltage >= 0.0 && voltage < 0.6) {
    return "N";
  } 
  else if (voltage >= 0.6 && voltage < 1.2) {
    return "NE";
  } 
  else if (voltage >= 1.2 && voltage < 1.8) {
    return "E";
  } 
  else if (voltage >= 1.8 && voltage < 2.4) {
    return "SE";
  } 
  else if (voltage >= 2.4 && voltage < 3.0) {
    return "S";
  } 
  else if (voltage >= 3.0 && voltage < 3.6) {
    return "SW";
  } 
  else if (voltage >= 3.6 && voltage < 4.2) {
    return "W";
  } 
  else if (voltage >= 4.2 && voltage <= 5.0) {
    return "NW";
  } 
  else {
    return "Unknown";
  }
}
