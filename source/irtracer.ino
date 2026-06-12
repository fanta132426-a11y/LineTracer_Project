unsigned long lastPrintTime = 0;
int lastDirection = 0;
int sp = 150;
void setup() {

        // put your setup code here, to run once:
        Serial.begin(9600);
        Serial.println("start");

}

void loop() {
        // put your main code here, to run repeatedly:
        int IR0 = analogRead(A0);
        int IR1 = analogRead(A1);
        
        if (IR0 > 100 && IR1 > 100)
        {
                analogWrite(9, 0);
                analogWrite(10, sp);
                analogWrite(3, sp);
                analogWrite(11, 0);

        }
        else if (IR0 > 100) //우측바퀴만 앞으로
        {
                lastDirection = -150;

                analogWrite(9, 0);
                analogWrite(10, 0);
                analogWrite(3, sp);
                analogWrite(11, 0);

        }
        else if (IR1 > 100) //좌측바퀴만 앞으로
        {
                lastDirection = 150;

                analogWrite(9, 0);
                analogWrite(10, sp);
                analogWrite(3, 0);
                analogWrite(11, 0);
        }
        else if (IR0 < 80 && IR1 < 80)
        {

                if (lastDirection < 0) {
                        lastDirection++;
                        analogWrite(9, 0);
                        analogWrite(10, 0);
                        analogWrite(3, sp);
                        analogWrite(11, 0);
                        Serial.print("-");
                }
                else if (lastDirection > 0) {
                        lastDirection--;
                        analogWrite(9, 0);
                        analogWrite(10, sp);
                        analogWrite(3, 0);
                        analogWrite(11, 0);
                        Serial.print("+");
                }
                else {
                        analogWrite(9, 0);
                        analogWrite(10, 0);
                        analogWrite(3, 0);
                        analogWrite(11, 0);
                        Serial.print("0");
                }



        }

        Serial.print("\t");
        Serial.print(IR0);
        Serial.print(":");
        Serial.println(IR1);
        









}
