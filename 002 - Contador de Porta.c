void main() 
{
//    RB = 76543210
   TRISB = 0b00000000;	// Inicializa todos os pinos B como saída
   PORTB = 0b00000000;	// Inicializa todos os pinos B como nível lógico baixo
   
   while(1)
   {
     PORTB++;  			// PORTB = PORTB + 1
     delay_ms(300);		// Delay de 0,3 segundos
   }


}