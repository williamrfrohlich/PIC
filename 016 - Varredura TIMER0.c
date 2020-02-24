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
           led1 = 0x01;                   //Acende led1

      } //end if

      else if(!S2)                      //S2 pressionado?
      {                                 //Sim...
           led1 = 0x00;                   //Apaga led1

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

     TRISA = 0x03;                        //Entrada em RA0 e RA1
     PORTA = 0x03;                        //RA0 e RA1 iniciam em high


     while(1)                             //Loop Infinito
     {
        led2 = 0x00;                      //led2 apagado
        delay_ms(500);                    //aguarda meio segundo
        led2 = 0x01;                      //led2 aceso
        delay_ms(500);                    //aguarda meio segundo
        
     } //end while
     
} //end main