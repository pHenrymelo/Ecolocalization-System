byte echo = 3;
byte trigger = 5;
int alarm = 10;
float cm,duracao;

void setup()
{
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(alarm, OUTPUT);
}

void loop()
{
	cm = distancia();
  	delay(50);
  	Serial.println(cm);
  
  if ((cm < 50) && (cm > 0)){
    delay(50);
    analogWrite(10, 100);
    delay(50);
    analogWrite(10, 0);
  } else if ((cm < 100) && (cm > 0)){
    delay(150);
    analogWrite(10, 100);
    delay(150);
    analogWrite(10, 0);
  } else if ((cm < 200) && (cm > 0)){
    delay(300);
    analogWrite(10, 100);
    delay(300);
    analogWrite(10, 0);
  } else if ((cm < 330) && (cm > 0)){
    delay(500);
    analogWrite(10, 100);
    delay(500);
    analogWrite(10, 0);
  }
  
  delay(50);
}

float distancia()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duracao = pulseIn(echo, HIGH);
  float calcDistancia = (duracao/2) * 0.0343;
  if (calcDistancia >= 331) {
    calcDistancia=0;
  }
  return calcDistancia;
}