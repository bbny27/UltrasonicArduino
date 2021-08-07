const int pingPin = 9;
const int echoPin = 10;
const int buzzerPin = 3;
const int dist = 20;
long duration, lengthm;

void setup() {
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pingPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);     
  digitalWrite(pingPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  lengthm = duration * 0.034 /2;
  Serial.print("Length:");
  Serial.println(lengthm);
  delay(100); 

  if(lengthm <= dist){
    int val = definevalue(lengthm);
    tone(buzzerPin,val);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}

int definevalue(float org){
  int val1 = 65535-map(org,0,dist,31,65535);
  // Highest and lowest value of tone() function is respectively 31 and 65535.
  Serial.print("Value:");
  Serial.println(val1);
  return val1;
}
