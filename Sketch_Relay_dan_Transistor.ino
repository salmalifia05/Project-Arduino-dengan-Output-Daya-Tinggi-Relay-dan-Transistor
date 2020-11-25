//Proyek #41: Relai dan Transistor
int Relai = 13;//pin untuk relai
int Motor = 5; //pin untuk transistor motor
int saklar_lampu = 3;//input pin saklar tekan kontrol lampu
int saklar_motor = 2;//input pin saklar tekan motor dc
int val_1 = 0;//variabel keadaan awal saklar lampu
int val_2 = 0;//variabel keadaan awal saklar motor dc
int old_val_1 = 0;//var.keadaan saklar lampu sebelumnya
int old_val_2 = 0; //var.keadaan saklar motor sebelumnya
int state_relai = 0;
int state_motor = 0;
void setup() {
pinMode(Relai, OUTPUT);//relai dan motor sbg output
pinMode(Motor, OUTPUT);
pinMode(saklar_lampu, INPUT);//saklar sebagai input
pinMode(saklar_motor, INPUT);
}
void loop(){
relai();//panggil fungsi blok relai
motor();//panggil fungsi blok motor
}
//buat fungsi blok untuk instruksi relai
void relai(){
val_1 = digitalRead(saklar_lampu);//cek input saklar lampu
//cek jika terjadi transisi
if ((val_1 == HIGH) && (old_val_1 == LOW)){
 state_relai = 1 - state_relai;
 delay(10);//delay untuk debounce saklar
}
old_val_1 = val_1; //nilai old_val_1 sekarang
if (state_relai == 1) {
 digitalWrite(Relai, HIGH);//On-kan relai
} 
else {
 digitalWrite(Relai, LOW);//off-kan relai
}
}
//buat fungsi blok untuk instruksi motor
void motor(){
val_2 = digitalRead(saklar_motor);
//cek jika terjadi transisi
if ((val_2 == HIGH) && (old_val_2 == LOW)){
 state_motor = 1 - state_motor;
 delay(10);
}
old_val_2 = val_2; 
if (state_motor == 1) {
 digitalWrite(Motor, HIGH);//motor dc on
 } 
else {
 digitalWrite(Motor, LOW);//motor dc off
 }
}
