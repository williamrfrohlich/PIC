void main() 
{
  ANSEL = 0x00; 		// Desliga as entradas AD de forma hexadecimal
  CMCON = 7;    		// Desliga os comparadores

  TRISIO4_bit = 1;		// Define o pino 04 como entrada
  TRISIO5_bit = 0;		// Define o pino 05 como saída
  
  GPIO = 0;				// Define todos os pinos de GPIO como nível lógico baixo
  
  while(1)
  {
    if(GPIO.F4)			// Se o nível lógico do pino 04 for alto..
    {
      GPIO.F5 = 1;		// O pino 05 assume nível lógico alto
      delay_ms(2000);	// Delay de 2 segundos
    }
    else
    {
      GPIO.F5 = 0;		// O pino 05 assume nível lógico baixo
    }  
  }

}