#define rpin 10
#define gpin 9
#define bpin 11

int r, g, b, rnew, gnew, bnew;
void loop1();
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  
  randomSeed(24000);
  r = random()%255;
  g = random()%255;
  b = random()%255;
  analogWrite(rpin, r);
  analogWrite(gpin, g);
  analogWrite(bpin, b);
  rnew = random()%255;
  gnew = random()%255;
  bnew = random()%255;
}

void loop() {
  // put your main code here, to run repeatedly:
  /*rnew = random()%255;
  g = random()%255;
  b = random()%255;
  analogWrite(rpin, r);
  analogWrite(gpin, g);
  analogWrite(bpin, b);
  delay(500);*/
  if(Serial.available()>0)
  {
    loop1();
  }
  if(r>rnew)
  {
    r--;
    analogWrite(rpin, r);
  }
  if(r<rnew)
  {
    r++;
    analogWrite(rpin, r);
  }
  if(r==rnew)
  {
    rnew = random()%255;
  }
  if(g>gnew)
  {
    g--;
    analogWrite(gpin, g);
  }
  if(g<gnew)
  {
    g++;
    analogWrite(gpin, g);
  }
  if(g==gnew)
  {
    gnew = random()%255;
  }
  if(b>bnew)
  {
    b--;
    analogWrite(bpin, b);
  }
  if(b<bnew)
  {
    b++;
    analogWrite(bpin, b);
  }
  if(b==bnew)
  {
    bnew = random()%255;
  }
  delay(15);
}

void loop1()
{
  if(Serial.available()>0)
  {
    r=Serial.parseInt();
    g=Serial.parseInt();
    b=Serial.parseInt();
    analogWrite(rpin, r);
    analogWrite(gpin, g);
    analogWrite(bpin, b);
    Serial.write(r + g + b);
  }
  loop1();
}

