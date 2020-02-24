void main() 
{	//RB =   7654321
   TRISB = 0b00000000;	// Inicializa todos os pinos B como saída
   PORTB = 0b00000000;	// Inicializa todos os pinos B como nível lógico baixo

   while(1)
   {

     RB1_bit = 1;		// Seleciona o pino 1 como nível lógico alto
     delay_ms(1000);	// Delay de 1 segundo
     RB1_bit = 0;		// Seleciona o pino 1 como nível lógico baixo
     delay_ms(1000);	// Delay de 1 segundo

   }

}