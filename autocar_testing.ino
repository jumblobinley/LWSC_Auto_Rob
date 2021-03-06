/* ************************************************
  LWE Science Club Auto Car

  Description
  
  Details, Details, Details, Details, Details, Details, Details, 
  Details, Details, Details, Details, Details, Details, Details, 
  Details, Details, vDetails, Details, Details, Details, Details, 
  Details, Details, Details, Details, Details, Details, Details, 

  https://github.com/jumblobinley/LWSC_Auto_Rob.git
  (See git examples below)

  
  --Created 2020 Dec 15
  --by Joseph Hauser
  --Modified 2020 jan 26
  --by Joseph Hauser

************************************************** */

// setting up global values for sensors
  
  #define MOTOR1 9
  #define MOTOR2 10
  
  bool sensVals[5] = {LOW, LOW, LOW, LOW, LOW};
  int sensAn = 0;
  
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  //pinMode(A5, OUTPUT); but it's analog
}

// the loop function runs over and over again forever
void loop() {
  
  //flashing pin 2
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(50);                       // wait for a second

//Step 1. Read the line sensor  
  sensorRead();
  delay(10);

//Step 2. process the incoming data, and determine the motor commands   
void dataFilter(void);

//Step 3. send out the motor commands

/*
//test Code #1
  bool motorResponse = 0;
  motorResponse = motorControl(MOTOR1, 200);
  Serial.println(motorResponse);
  delay(500);
  motorResponse = motorControl(MOTOR2, 1023);
  Serial.println(motorResponse);
  delay(500);
  motorResponse = motorControl(3, 1024);
  Serial.println(motorResponse);
  delay(2000);
  motorControl(MOTOR1, 0);
  motorControl(MOTOR2, 0);
*/

/*
   //test code #2
if (sensVals[0] == true){
  motorControl(MOTOR2, 0);
  motorControl(MOTOR1, 200);
}

if (sensVals[2] == true){
  motorControl(MOTOR1, 0);
  motorControl(MOTOR2, 0);
}
  
if (sensVals[4] == true){
  motorControl(MOTOR1, 0);
  motorControl(MOTOR2, 200);
}
*/


    //test code #3
    //put this logic into the data filter function
    if (sensVals[0] == true){
      motorControl(MOTOR2, 20);
      motorControl(MOTOR1, 100);
    }
    
    if (sensVals[1] == true){
      motorControl(MOTOR2, 100);
      motorControl(MOTOR1, 200);
    }
    
    if (sensVals[2] == true){
      motorControl(MOTOR2, 200);
      motorControl(MOTOR1, 200);
    }
    if (sensVals[3] == true){
      motorControl(MOTOR2, 200);
      motorControl(MOTOR1, 100);
    }
      
    if (sensVals[4] == true){
      motorControl(MOTOR2, 100);
      motorControl(MOTOR1, 20);
    }
    
    //check values for all zeros and turn off motor
    bool isZero = true;
    for (int cnt=0;cnt<5; cnt++)
    {
      if (sensVals[cnt] != 0) {isZero=false; break;}  
    }
    if (isZero == true) {motorControl(MOTOR2, 0); motorControl(MOTOR1, 0);}

    //ad  a new line at the end of the output data
    Serial.println(" ");

}


// recieves information from the Cytron Maker Line
void sensorRead(void) {
  // initialize digital pin LED_BUILTIN as an output.
 sensVals[0] = digitalRead(A0);
 sensVals[1] = digitalRead(A1); 
 sensVals[2] = digitalRead(A2);
 sensVals[3] = digitalRead(A3);
 sensVals[4] = digitalRead(A4);
 sensAn = analogRead(A5);

 Serial.print(sensVals[0]);
 Serial.print(", ");
 Serial.print(sensVals[1]);
 Serial.print(", ");
 Serial.print(sensVals[2]);
 Serial.print(", ");
 Serial.print(sensVals[3]);
 Serial.print(", ");
 Serial.print(sensVals[4]);
 Serial.print(", ");
 Serial.print(sensAn);
 Serial.print(" -- ");
}

// filters the data recieved so the motors can understand what actions to take
void dataFilter(void) {
  

}


// commmands sent to the motor controller
bool motorControl(int motorNum, int motorPow) {
  
  Serial.print(" --> ");
  Serial.print(motorNum);
  Serial.print(", ");
  Serial.print(motorPow);
  Serial.print(" <-- ");
  
  if (motorNum == MOTOR1) {
    analogWrite(MOTOR1, motorPow); 
 }
  else if (motorNum == MOTOR2) {
    analogWrite(MOTOR2, motorPow);
    
 }
  else {
    Serial.println("motor nonexiststant");
    return false;
 }
return true;
}

/* GitHub Examples
 *  
 *  ---Write code
 *  ---Add file to repo:
 *  git add <filename>
 *  
 *   --Attach a remote origin to your code repo, Do this one time
 *  git remote add origin git@github.com:jumblobinley/LWSC_Auto_Rob.git
 *  (Note: ssh keys are set up for this computer.  Other students will have to set up thier keys)
 *  
 *  ---When done writing code, commit your code
 *  cd ~/Documents/ArduinoSketchBook/autocar_testing
 *  git commit -m "comment"
 *  
 *  ---Push code to github in the cloud
 *  git push -u origin master
 *  
 */
