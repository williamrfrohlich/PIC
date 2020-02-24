 #define S1 GPIO.F0			// Define que o pino 0 assume o valor de S1
 #define S2 GPIO.F1			// Define que o pino 1 assume o valor de S2
 #define D1 GPIO.F4			// Define que o pino 4 assume o valor de D1
 #define D2 GPIO.F5			// Define que o pino 5 assume o valor de D2
 

void main()
{
      ANSEL = 0;			// Desliga os pinos AD
      CMCON = 7;			// Desliga os comparadores

      TRISIO0_bit = 1;		// Define o pino 0 como entrada
      TRISIO1_bit = 1;		// Define o pino 1 como entrada
      TRISIO4_bit = 0;		// Define o pino 4 como saída
      TRISIO5_bit = 0;		// Define o pino 5 como saída
      
      S1 = 1;
      S2 = 1;
      D1 = 0;
      D2 = 0;
      

      while(1)
      {
        if(S1 == 0)
        {
          D1 = ~D1;
          delay_ms(300);
        }
        if(S2 == 0)
        {
          D2 = ~D2;
          delay_ms(300);
        }

      }

}