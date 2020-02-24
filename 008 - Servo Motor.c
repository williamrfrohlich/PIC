
#define S2     RA0_bit //hardware onboard do PDX9
#define S1     RA1_bit
#define led2   RA2_bit
#define led1   RA3_bit //...
#define servo1 RB0_bit //RB0 controla o servo1

//protótipos das funções de controle do servo
void servo1_horario();
void servo1_centro();
void servo1_antihorario();

void main()
{
    CMCON = 0x07; //desliga comparadores do PIC
    TRISA = 0x03; //RA0 e RA1 como entrada digital
    TRISB = 0x00; //PORTB como saída digital
    PORTA = 0x03; //RA0 e RA1 iniciam em high
    PORTB = 0x00; //PORTB inicia todo em low
    
      while(1)
      {
          //Se manter S1 pressionado...
          //...servo move-se no sentido horário
          if(S1 == 0x00 && S2 == 0x01) servo1_antihorario();
          //Se manter S2 pressionado...
          //...servo move-se no sentido anti horário
        //  else if(S2 == 0x00 && S1 == 0x01) servo1_antihorario();
          //Senão...
          //...centraliza servo
          else servo1_horario();
      }
}
void servo1_horario() //função que move o servo
{ //no sentido horario
    servo1 = 0x00;
    delay_us(17700);
    servo1 = 0x01;
    delay_us(2300); //pulso de 2ms
}
void servo1_centro()
{
    servo1 = 0x00;
    delay_us(18500);
    servo1 = 0x01;
    delay_us(1500); //pulso de 1,5ms
}
void servo1_antihorario()
{
    servo1 = 0x00;
    delay_us(19200);
    servo1 = 0x01;
    delay_us(800); //pulso de 1ms
}