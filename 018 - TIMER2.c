void interrupt()
{
   if(TMR2IF_bit)               //Houve o overflow do timer2?
   {                            //Sim...
   
        PORTB = ~PORTB;         //Inverte o valor do PORTB

        TMR2IF_bit = 0x00;      //Limpa a flag
   }
}

void main()
{
     GIE_bit =  0x01;            //Habilita a interrupção global
     PEIE_bit = 0x01;            //Habilita a interrupção por periféricos
     TMR2IE_bit = 0x01;          //Habilita a interrupção do TIMER2
     T2CON = 0b00011101;         //Liga o TIMER2, postscaler 1:4, prescaler 1:4
     PR2   = 100;                //Compara o TMR2 com PR2, PR2 igual a 100
     TRISB = 0x00;
     PORTB = 0x00;

     // Ciclo de máquina x PR2 x prescaler x postscaler
     // 1us x 100 x 4 x 4
     
     while(1)
     {
          //
     
     }


}