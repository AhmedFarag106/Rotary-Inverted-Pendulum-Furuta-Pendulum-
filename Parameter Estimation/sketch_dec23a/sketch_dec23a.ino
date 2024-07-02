#define pin1 18   
#define pin2 19   
#define theta0_ppr 500

#define motor_pwm 6
#define motor_p1  7
#define motor_p2  8

#define button 10
#define VOLTAGE 10.2


volatile int counter = 0 ; //This variable will increase or decrease depending on the rotation of encoder
int prev_count = 0 , start_time=0,current_time = 0  ;
float my_speed = 0,elapsed_time = 0.0,speed_controller=0,PWM,voltage;
bool motor_direction = 0;
char speed_counter=0;

void setup() 
{
  pinMode(motor_pwm,OUTPUT);
  pinMode(motor_p1,OUTPUT);
  pinMode(motor_p2,OUTPUT);

  pinMode(button,INPUT);


  Serial.begin (9600);
  //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moustArduino.
  pinMode(pin1,INPUT_PULLUP);
  pinMode(pin2,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin1), intr1, RISING);
  attachInterrupt(digitalPinToInterrupt(pin2), intr2, RISING);
  start_time = millis();

}

void loop() 
{
  current_time = millis();


  if ((current_time - start_time) % 100 ==0)
  {
    elapsed_time+=0.1;
    my_speed = ( (long)counter*60*10/ (2*theta0_ppr)) ;


  Serial.print(elapsed_time);
  Serial.print(" , ");
  if (!motor_direction) Serial.print("-");
  Serial.print(voltage);
  Serial.print(" , ");
  Serial.println(my_speed);
  //Serial.print(" , ");
  //Serial.println(counter);
  counter =0;
  }

  if (digitalRead(button) == 1)
  {
    motor_direction = !motor_direction;
    digitalWrite(motor_p1,motor_direction);
    digitalWrite(motor_p2,!motor_direction);
    motor_direction *= -1;
    
    speed_counter ++;
    if (speed_counter %2 ==0)
    {
      speed_controller +=0.1 ;
    }
    PWM = 255*speed_controller;
    analogWrite(motor_pwm,PWM);
    voltage= VOLTAGE * speed_controller;
    while (digitalRead(button) == 1);
  }


}
void intr1() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(pin2)==LOW)
  {
    counter ++;
  }
  
  else
  {
    counter --;
  }
}
void intr2() 
{
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(pin1)==LOW) 
  {
    counter --;
  }
  
  else
  {
    counter ++;
  }
}
