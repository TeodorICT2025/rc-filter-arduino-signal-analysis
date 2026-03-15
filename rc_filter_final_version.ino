int pin=6; // pin for RC circuit
int pot_2=8;
int read=A0;
int control_1=A1;
int control_2=A2;
float vc_present;
float vc_lasttime;
float v_input;
float t_present;
float t_last;
float tau=0.1;
float omega_1=10.0;
float omega_2=10.0;
float initial_omega=omega_1;
float dt=0;
float t_initial;
void setup() {
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
  pinMode(pot_2, OUTPUT);
  digitalWrite(pot_2, HIGH);
  analogWrite(pin, 128);
  delay(2000);
  vc_lasttime=1023/2.0;
  v_input=1023/2.0;
  t_last=millis()/1000.0;
  t_initial=t_last;
}

void loop() {
  t_present=float(millis())/1000.0;
  float v_read_c=analogRead(read);
  dt=t_present-t_last;
  vc_present=vc_lasttime + (v_input - vc_lasttime) * (1-exp( - dt / tau));
  //derive new omega
  float x_1 = analogRead(control_1);
  omega_1 = initial_omega * (x_1/700.0);
  float x_2=analogRead(control_2);
  omega_2=initial_omega*(x_2/700.0);
  v_input = (1023 * (2.5 * ( 1+ 0.5 * sin(omega_1 * (t_present-t_initial))+ 0.5 * sin(omega_2 * (t_present - t_initial)))/5.0));
  analogWrite(6, v_input/4.0);
  t_last=t_present;
  vc_lasttime=vc_present;
  Serial.print(v_input,3);
  Serial.print(",");
  Serial.print(v_read_c,3);
  Serial.print(",");
  Serial.print(vc_present,3);
  Serial.print(",");
  Serial.print(x_1,3);
  Serial.print(",");
  Serial.print(x_2,3);
  Serial.print(",");
  Serial.println(t_present-t_initial,3);
  delay(1);
  if(t_present-t_initial>3)
  {
    while(true)
    {

    }
  }
  
}