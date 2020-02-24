int counter = 0x00;                  //Vari�vel de contagem auxiliar

void interrupt()                     //Vetor de interrup��o , endere�o 04h de mem�ria
{
   if(T0IF_bit)                      //Houve o estouro do TIMER0?
   {
       counter++;                    //Incrementa o counter
       TMR0  = 0x06;                 //Reinicia o registrador TMR0
       
       
       if(counter == 500)              // 1us * 4 * 250 * 500 = 500ms
       {

          RB4_bit = ~RB4_bit;
          counter = 0x00;

       }

       T0IF_bit = 0x00;              //Limpa a flag para a pr�xima interrup��o

   }


} //end interrupt



void main()
{
   OPTION_REG = 0x81;                //Desabilita os resistores de pull-up internos
                                     //Configura o prescaler para 1:4 associado ao TMR0
									 
   GIE_bit    = 0x01;                //Habilita a interrup��o global
   PEIE_bit   = 0x01;                //Habilita a interrup��o por perif�ricos
   T0IE_bit   = 0x01;                //Habilita a interrup��o por estouro do TMR0

   TMR0       = 0x06;                //Inicia a contagem em zero

   
   TRISB.RB4  = 0x00;                //Configura o RB4 como sa�da digital
   TRISB.RB5  = 0x00;                //Configura o RB5 como sa�da digital
   RB4_bit    = 0x00;                //Inicia RB4 em LOW
   RB5_bit    = 0x00;                //Inicia RB5 em LOW

   while(1)
   {
        RB5_bit = 0x01;
        delay_ms(500);
        RB5_bit = 0x00;
        delay_ms(500);

   } //end while

} //end main