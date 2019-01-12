int DonmeHizi = 75; 


void ileri(int hiz){
  
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, hiz);
  
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, hiz);
}

void solaDon(int hiz){
  
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  analogWrite(3, hiz); 
  
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, hiz);
}

void sagaDon(int hiz){
  
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, hiz);
  
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, hiz);
}

void geri(int hiz){
  
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  analogWrite(3, hiz);
  
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, hiz);
}

void dur(){
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}



void setup() {
  Serial.begin(9600);
  //A motoru
  pinMode(12,OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(8, OUTPUT);
}

char h = 0;

void loop() {
  if (Serial.available() > 0) {
    h = Serial.read();       
    
    if (h == 'w')
    {
      Serial.print("İleri gidiyor ...\n");
      ileri(DonmeHizi);
      delay(1000);
    }
    
    else if (h == 'a')
    {
      Serial.print("Sola gidiyor ...\n");
      solaDon(DonmeHizi);
      delay(1000);
    }
    
    else if (h == 'd')
    {
      Serial.print("Sağa gidiyor ...\n");
      sagaDon(DonmeHizi);
      delay(1000);
    }
    
    else if (h == 's')
    {
      Serial.print("Fren yaptı ve durdu.\n");
      dur();
      delay(1000);
    }
  }
}
