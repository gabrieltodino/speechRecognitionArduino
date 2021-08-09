String datafromUser="";
void setup() {
  // put your setup code here, to run once:
  pinMode( 7 , OUTPUT );
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    datafromUser=Serial.readString();
  }

  if(datafromUser == "acender led")
  {
    digitalWrite( 7 , HIGH );
  }
  else if(datafromUser == "apagar led")
  {
    digitalWrite( 7, LOW);
  }
  
}
