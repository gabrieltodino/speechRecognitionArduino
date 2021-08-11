String datafromUser="";
int IN5 = 5;
int IN6 = 6;
byte speed = 150;

void setup() {
  // put your setup code here, to run once:
  pinMode(7 , OUTPUT );
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    datafromUser=Serial.readString();
  }

  datafromUser.toLowerCase();

  if(datafromUser == "acender led"){
    digitalWrite( 7 , HIGH );
  }else if(datafromUser == "apagar led"){
    digitalWrite( 7, LOW);
  }else if(datafromUser == "ligar motor"){
    avancar(speed);
  }else if(datafromUser == "aumentar velocidade"){
    speed += 25;
    avancar(speed);
  }else if(datafromUser == "diminuir velocidade"){
    speed -= 25;
    avancar(speed);
  }
}

void avancar(byte power) {
  analogWrite(IN5, power);
  digitalWrite(IN6, LOW);
}
