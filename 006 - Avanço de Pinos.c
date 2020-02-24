int control = 0xFF;				// Inicializa a variável com valor 255 em hexadecimal
  
void main()
{

  TRISB = 0;					// Inicializa os pinos B como saída em decimal									0b00000000
  PORTB = 0xFF;					// Inicializa os todos os pinos B com nível lógico alto em hexadecimal			0b11111111
  
  while(1)
  {
     PORTB = control;			// Os pinos B recebem a variável control
     delay_ms(300);				// Delay de 0,3 segundos
     
     control = control << 1;	// Desliga em 1 o valor de cada bit
     
      if(control == 0) control = 0xFF;

  
  }
  
  

}