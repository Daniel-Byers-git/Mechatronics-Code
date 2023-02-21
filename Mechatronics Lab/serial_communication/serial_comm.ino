int counter;
char val;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  //part one
//  counter++;
//  if (counter < 2000)
//  {
//    digitalWrite(LED_BUILTIN, HIGH);
//    Serial.println(100); // didn't quite figure out the ASCII aspect
//  }
//  else
//  {
//    digitalWrite(LED_BUILTIN, LOW);
//    Serial.println(200); // ditto
//  }
//  if(counter > 4000){counter = 0;}

  //part two
  while(Serial.available())
  {
    val = Serial.read();
    if(val == 'q')
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (val == 'w')
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(200);
  }
   
}
