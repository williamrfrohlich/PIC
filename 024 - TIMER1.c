void main() 
{
     CMCON  = 0x07;                     //Desabilita os comparadores
     T1CON = 0x31;                      //Prescaler 1:8 e TMR1 habilitado
     TMR1L = 0x00;                      //Inicializa o Timer1 em 00
     TMR1H = 0x00;
     TRISC = 0xEF;                      // 1110 1111 Apenas o RC4 como saída
     RC4_bit = 0x00;                    // RC4 inicia em low
     
     while(1)
     {
         if(TMR1IF_bit)                 //Houve o estouro do Timer1?
         {                              //Sim...
            TMR1IF_bit = 0x00;          //Limpa a flag
            
            RC4_bit = ~RC4_bit;         //Inverte o estado de RC4
         }
     }
}