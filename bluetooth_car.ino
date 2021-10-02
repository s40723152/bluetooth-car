char t;
 
void setup() {
pinMode(5,OUTPUT);   //left motors forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(10,OUTPUT);   //right motors forward
pinMode(11,OUTPUT);   //right motors reverse
pinMode(13,OUTPUT);   //Led
Serial.begin(10600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(5,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(10,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(5,HIGH);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(10,HIGH);
}
else if(t == 'w'){
  digitalWrite(10,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
delay(110);
}
