/*
        Curso de PIC WR Kits

        Aula 30 - PWM configurado a partir do Timer 2

        Eng. Wagner Rambo, Junho de 2015
*/

// --- Hardware ---
#define S2      RA0_bit
#define S1      RA1_bit
#define led2    RA2_bit
#define led1    RA3_bit

void interrupt()
{
    if(T0IF_bit)                          //Houve estouro do Timer0?
    {                                     //Sim...

      T0IF_bit = 0x00;                    //Limpa a flag

      TMR0     = 0x6C;                    //Reinicia o timer0

      if(!S1)                           //S1 pressionado?
      {                                 //Sim...
        CCPR1L++;

      } //end if

      else if(!S2)                      //S2 pressionado?
      {                                 //Sim...
        CCPR1L--;

      } //end else if


    }

} //end interrupt


// --- Função Principal
void main()
{
     CMCON      = 0x07;                   //Desabilita os comparadores
     OPTION_REG = 0x86;                   //Timer0 incrementa com ciclo de instrução, prescaler 1:128
     GIE_bit    = 0x01;                   //Habilita interrupção global
     PEIE_bit   = 0x01;                   //Habilita interrupção por periféricos
     T0IE_bit   = 0x01;                   //Habilita interrução do Timer0
     TMR0       = 0x6C;                   //Inicia o timer0
     
     // periodo = (PR2 + 1) x ciclo de máquina x prescaler do Timer2
     // periodo = 256 x 1us x 16 = 4,096ms
     // frequencia = 1/periodo = 244,14Hz
     
     // PR2+1 = TMR2 (quando há o estouro do Timer2, low para high) / CCPR1L:CCP1CON<5:4>
     
     
     
     PR2        = 0xFF;                   //Inicializa o registrador de controle do timer2 em 255
     T2CON      = 0x06;                   //Liga o timer2 e prescaler 1:16
     CCPR1L     = 0x00;                   //LED iniciará desligado
     CCP1CON    = 0x0C;                   //Habilita o modo PWM
     

     TRISA = 0x03;                        //Entrada em RA0 e RA1
     TRISB = 0x00;                        //Todo PORTB será saída
     PORTA = 0x03;                        //RA0 e RA1 iniciam em high
     PORTB = 0x00;                        //Todo PORTB inicia em nível low


     while(1)                             //Loop Infinito
     {
         //

     } //end while

} //end main