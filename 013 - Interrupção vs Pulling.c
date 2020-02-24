int counter = 0x00;                  //Variável de contagem auxiliar

void interrupt()                     //Vetor de interrupção , endereço 04h de memória
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

       T0IF_bit = 0x00;              //Limpa a flag para a próxima interrupção

   }


} //end interrupt



void main()
{
   OPTION_REG = 0x81;                //Desabilita os resistores de pull-up internos
                                     //Configura o prescaler para 1:4 associado ao TMR0
									 
   GIE_bit    = 0x01;                //Habilita a interrupção global
   PEIE_bit   = 0x01;                //Habilita a interrupção por periféricos
   T0IE_bit   = 0x01;                //Habilita a interrupção por estouro do TMR0

   TMR0       = 0x06;                //Inicia a contagem em zero

   
   TRISB.RB4  = 0x00;                //Configura o RB4 como saída digital
   TRISB.RB5  = 0x00;                //Configura o RB5 como saída digital
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