

void main() 
{
  ANSEL = 0;			// Desliga os pinos AD
  CMCON = 7;			// Desliga comparadores
  
  TRISIO0_bit = 0;		// Define o pino 0 como saída
  TRISIO1_bit = 0;		// Define o pino 1 como saída
  
  while(1)
  {
    GPIO.F0 = 1;
    delay_ms(10);
    GPIO.F0 = 0;
    delay_ms(10);
    
    GPIO.F1 = 1;
    delay_ms(1);
    GPIO.F1 = 0;
    delay_ms(1);
  
  }


}