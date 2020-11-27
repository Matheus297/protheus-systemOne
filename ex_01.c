int cont = 0;
char keypadport at portb;// conexão do modulo do teclado

sbit lcd_rs at rd3_bit;
sbit lcd_en at rd2_bit;
sbit lcd_d4 at rd4_bit;
sbit lcd_d5 at rd5_bit;
sbit lcd_d6 at rd6_bit;
sbit lcd_d7 at rd7_bit;

sbit lcd_rs_direction at trisd3_bit;
sbit lcd_en_direction at trisd2_bit;
sbit lcd_d4_direction at trisd4_bit;
sbit lcd_d5_direction at trisd5_bit;
sbit lcd_d6_direction at trisd6_bit;
sbit lcd_d7_direction at trisd7_bit;

char var_texto[16];
int contador = 0;


void main(){

lcd_init();
lcd_cmd (_lcd_clear); // APAGA O DISPLAY
lcd_cmd (_lcd_cursor_off); // DESLIGA O CURSOR
/*lcd_out (1,1, "POTEN:"); // ESCREVE "TEMP:" NO DISPLAY
lcd_out (1,10,"%"); */

trisc = 0b00000000; // CONFIGURA O PORTC COMO SAÍDA
portc = 0;

keypad_init();

adcon1 = 0x0f;

PWM1_Start();
PWM1_Init(2000);

do{

do
cont = Keypad_Key_Click();
while(!cont);

if(cont == 13 && contador == 0){
 portc.rc0 = 1;
 lcd_out(1,1,"LED: LIGADO          ");
 lcd_out(2,1, "              ");
 contador += 1;
 
}else if(cont == 13 && contador == 1){
 portc.rc0 = 0;
 lcd_out(1,1,"LED: DESLIGADO          ");
 lcd_out(2,1, "              ");
 contador -= 1;
}

switch(cont){
 case 0:
 break;

 case 1: portc.rc2 = 1; //1
 PWM1_Set_Duty(10000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 10% ");
 break;

 case 2: portc.rc2 = 1;    //2
 PWM1_Set_Duty(9000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 20%  ");
 break;

 case 3: portc.rc2 = 1;  //3
 PWM1_Set_Duty(8000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 30%  ");
 break;

 case 4:      //NAO EXISTE
 break;

 case 5: portc.rc2 = 1; //4
 PWM1_Set_Duty(7000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 40%  ");
 break;

 case 6: portc.rc2 = 1;  //5
 PWM1_Set_Duty(6000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 50%  ");
 break;

 case 7: portc.rc2 = 1;    //6
 PWM1_Set_Duty(5000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 60%  ");
 break;

 case 8:
 break;

 case 9: portc.rc2 = 1;      // 7
 PWM1_Set_Duty(4000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 70%  ");
 break;

 case 10: portc.rc2 = 1;    //8
 PWM1_Set_Duty(3000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 80%  ");
 break;

 case 11: portc.rc2 = 1;    //9
 PWM1_Set_Duty(2000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 90%  ");
 break;

 case 12:
 break;

 case 13:
 break;

 case 14: portc.rc2 = 1;    //  0
 PWM1_Set_Duty(0);
 lcd_out(1,1,"MOTOR: DESLIGADO    ");
 lcd_out(2,1,"Potencia: 0%  ");
 break;

 case 15: portc.rc2 = 1;    //  # 100%
 PWM1_Set_Duty(1000);
 lcd_out(1,1,"MOTOR: LIGADO    ");
 lcd_out(2,1,"Potencia: 100%  ");
 break;
 
 case 16:
 break;









}


}while(1);


}
