/*
        Teclado Matricial
*/

// --- Hardware ---
#define S2      RA0_bit
#define S1      RA1_bit
#define led2    RA2_bit
#define led1    RA3_bit

#define col_1   RB1_bit
#define col_2   RB2_bit
#define col_3   RB3_bit
#define row_A   RB4_bit
#define row_B   RB5_bit
#define row_C   RB6_bit
#define row_D   RB7_bit


void pulse(char number);                //Função para pulsar o led1


char control = 0x01;


void interrupt()
{
    if(T0IF_bit)                          //Houve estouro do Timer0?
    {                                     //Sim...

      T0IF_bit = 0x00;                    //Limpa a flag
      TMR0     = 0x6C;                    //Reinicia o timer0
      
      if(col_1 && control == 0x01)        //Coluna 1 em nível high? Control igual 1?
      {                                   //Sim...
         control = 0x02;
         col_1 = 0x00;                    //Apenas a coluna 1 em nível baixo
         col_2 = 0x01;
         col_3 = 0x01;
      
         if(!row_A)      pulse(1);
         else if(!row_B) pulse(4);
         else if(!row_C) pulse(7);
         else if(!row_D) pulse(11);
      
      }
      else if(col_2 && control == 0x02)   //Coluna 2 em nível high? Control igual 2?
      {                                   //Sim...
         control = 0x03;
         col_1 = 0x01;                    //Apenas a coluna 2 em nível baixo
         col_2 = 0x00;
         col_3 = 0x01;
         
         if(!row_A)      pulse(2);
         else if(!row_B) pulse(5);
         else if(!row_C) pulse(8);
         else if(!row_D) pulse(10);

      }
      else if(col_3 && control == 0x03)   //Coluna 3 em nível high? Control igual 3?
      {                                   //Sim...
         control = 0x01;
         col_1 = 0x01;                    //Apenas a coluna 3 em nível baixo
         col_2 = 0x01;
         col_3 = 0x00;
         
         if(!row_A)      pulse(3);
         else if(!row_B) pulse(6);
         else if(!row_C) pulse(9);
         else if(!row_D) pulse(12);

      }




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
     TRISB = 0xF0;                        //Nibble mais significativo do PORTB será entrada
     PORTA = 0x03;                        //RA0 e RA1 iniciam em high
     PORTB = 0xFF;                        //Nibble mais significativo inicia em high.


     while(1)                             //Loop Infinito
     {


     } //end while

} //end main


void pulse(char number)
{
   char i;                                //variável de iterações
   
   for(i=0;i<number;i++)
   {
     led1 = 0x01;
     delay_ms(200);
     led1 = 0x00;
     delay_ms(200);
   
   }


}