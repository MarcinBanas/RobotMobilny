




#include <Adafruit_MotorShield.h>
#include <time.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();


// Select which 'port' M1, M2, M3 or M4.
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);



char command;
void setup() {
    Serial.begin(9600);           // set up Serial library at 9600 bps
    srand(time(NULL));

    if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
        Serial.println("Could not find Motor Shield. Check wiring.");
        while (1);
    }
    Serial.println("Motor Shield found.");

    // Set the speed to start, from 0 (off) to 255 (max speed)
    myMotor1->setSpeed(255);
    myMotor2->setSpeed(255);
    myMotor3->setSpeed(255);
    myMotor4->setSpeed(255);

}
void robotRunForward() 
{
    myMotor1->run(BACKWARD);
    myMotor2->run(BACKWARD);
    myMotor3->run(FORWARD);
    myMotor4->run(FORWARD);
}
void robotRunBackward()
{
    myMotor1->run(FORWARD);
    myMotor2->run(FORWARD);
    myMotor3->run(BACKWARD);
    myMotor4->run(BACKWARD);
}
void robotRunLeft()
{
    myMotor1->run(BACKWARD);
    myMotor2->run(FORWARD);
    myMotor3->run(BACKWARD);
    myMotor4->run(FORWARD);
}
void robotRunRight()
{
    myMotor1->run(FORWARD);
    myMotor2->run(BACKWARD);
    myMotor3->run(FORWARD);
    myMotor4->run(BACKWARD);
}
void robotStop()
{
    myMotor1->run(RELEASE);
    myMotor2->run(RELEASE);
    myMotor3->run(RELEASE);
    myMotor4->run(RELEASE);
}


void loop() {
    command = Serial.read();
    
    switch (command)
    {
    case ('F'):
        robotRunForward();
        break;
    case ('S'):
        robotStop();
        break;
    case ('B'):
        robotRunBackward();
        break;
    case ('L'):
        robotRunLeft();
        break;
    case ('R'):
        robotRunRight();
        break;
    case ('1'):
        myMotor1->setSpeed(20);
        myMotor2->setSpeed(20);
        myMotor3->setSpeed(20);
        myMotor4->setSpeed(20);
        break;
    case ('2'):
        myMotor1->setSpeed(50);
        myMotor2->setSpeed(50);
        myMotor3->setSpeed(50);
        myMotor4->setSpeed(50);
        break;
    case ('3'):
        myMotor1->setSpeed(80);
        myMotor2->setSpeed(80);
        myMotor3->setSpeed(80);
        myMotor4->setSpeed(80);
        break;
    case ('4'):
        myMotor1->setSpeed(100);
        myMotor2->setSpeed(100);
        myMotor3->setSpeed(100);
        myMotor4->setSpeed(100);
        break;
    case ('5'):
        myMotor1->setSpeed(120);
        myMotor2->setSpeed(120);
        myMotor3->setSpeed(120);
        myMotor4->setSpeed(120);
        break;
    case ('6'):
        myMotor1->setSpeed(150);
        myMotor2->setSpeed(150);
        myMotor3->setSpeed(150);
        myMotor4->setSpeed(150);
        break;
    case ('7'):
        myMotor1->setSpeed(180);
        myMotor2->setSpeed(180);
        myMotor3->setSpeed(180);
        myMotor4->setSpeed(180);
        break;
    case ('8'):
        myMotor1->setSpeed(205);
        myMotor2->setSpeed(205);
        myMotor3->setSpeed(205);
        myMotor4->setSpeed(205);
        break;
    case ('9'):
        myMotor1->setSpeed(235);
        myMotor2->setSpeed(235);
        myMotor3->setSpeed(235);
        myMotor4->setSpeed(235);
        break;
    case ('q'):
        myMotor1->setSpeed(255);
        myMotor2->setSpeed(255);
        myMotor3->setSpeed(255);
        myMotor4->setSpeed(255);
        break;
        }

}


