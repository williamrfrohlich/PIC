//------------------------------------------------
//		Author: Eng. William da Rosa Fr�hlich
//
//		Project: Internal Interruption
//
//		Date: 2018.02.11
//
//------------------------------------------------

int counter = 0x00;                  //Vari�vel de contagem auxiliar

void interrupt()                     //Vetor de interrup��o , endere�o 04h de mem�ria
{
   if(T0IF_bit)                      //Houve o estouro do TIMER0?
   {
       counter++;                    //Incrementa o counter
       TMR0  = 0x06;                 //Reinicia o registrador TMR0

       T0IF_bit = 0x00;              //Limpa a flag para a pr�xima interrup��o

   }
} //end interrupt

void main()
{
     OPTION_REG = 0x81;
     
     INTCON = 0xE4;

     TMR0 = 0x06;
     
     TRISB = 0x00;
     PORTB = 0x00;
     
     while(1)
     {
          if (counter == 1000)  // 1ms * 4 * 250 *
          {
               PORTB++;
               counter = 0x00;
          }
     }
}