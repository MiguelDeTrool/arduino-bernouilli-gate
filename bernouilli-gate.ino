int random1 = 0;
int prob1 = 0;
int gate1State = 0;
int lastGate1State = 0;
int random2 = 0;
int prob2 = 0;
int gate2State = 0;
int lastGate2State = 0;

void setup() {
  // put your setup code here, to run once:
  // pins for 1st gate
  pinMode(2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // pins for 2nd gate
  pinMode(15, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  
  // define probability threshold
  prob1 = analogRead(A3) + analogRead(A1)/2;
  prob2 = analogRead(A2) + analogRead(A0)/2;
  
  // read the gate input pin:
  gate1State = digitalRead(2);
  gate2State = digitalRead(14);

  // compare the gateState to its previous state
  if (gate1State != lastGate1State) {
    
    // if the state has changed, increment the counter
    if (gate1State == HIGH) {
      random1 = random(1023);
      if (random1 > prob1) {
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
      } else {
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
      }
    } else {
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
    }
  }

  //same thing again for gate2, compare the gateState to its previous state
  if (gate2State != lastGate2State) {
    
    // if the state has changed, increment the counter
    if (gate2State == HIGH) {
      random2 = random(1023);
      if (random2 > prob2) {
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
      } else {
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
      }
    } else {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
  }
  // Delay a little bit to avoid bouncing
  delayMicroseconds(50);

  
  
  // save the current state as the last state, for next time through the loop
  lastGate1State = gate1State;
  lastGate2State = gate2State;
}
