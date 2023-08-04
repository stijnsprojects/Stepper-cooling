int dirPin = 2;
int stepPin = 3;
int steps = 800;
int rampUpDelay = 1500;
int rampDownDelay = 500;

void setup() 
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  delay(3000);
  Serial.begin(9600);
}

void loop() 
{
  cw_ramp(rampUpDelay, rampDownDelay);
  ccw_ramp(rampUpDelay, rampDownDelay);
}

void cw_ramp(int maxDelay, int minDelay)
{
  digitalWrite(dirPin, HIGH);
  
  // Ramp-up
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(maxDelay);
    digitalWrite(stepPin, LOW);
    
    if (maxDelay > minDelay)
      maxDelay -= 1; // Gradually reduce the delay time for ramp-up
  }
  
  // Ramp-down
  for (int i = steps; i > 0; i--)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(maxDelay);
    digitalWrite(stepPin, LOW);
    
    if (maxDelay < rampUpDelay)
      maxDelay += 1; // Gradually increase the delay time for ramp-down
  }
  
  delay(1000); // Add a delay between directions for better visibility
}

void ccw_ramp(int maxDelay, int minDelay)
{
  digitalWrite(dirPin, LOW);
  
  // Ramp-up
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(maxDelay);
    digitalWrite(stepPin, LOW);
    
    if (maxDelay > minDelay)
      maxDelay -= 1; // Gradually reduce the delay time for ramp-up
  }
  
  // Ramp-down
  for (int i = steps; i > 0; i--)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(maxDelay);
    digitalWrite(stepPin, LOW);
    
    if (maxDelay < rampUpDelay)
      maxDelay += 1; // Gradually increase the delay time for ramp-down
  }
  
  delay(1000); // Add a delay between directions for better visibility
}
