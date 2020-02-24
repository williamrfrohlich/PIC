//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: Input / Output
//
//		Date: 2018.10.13
//
//------------------------------------------------

void main()
{
     ANSEL = 0x00;      // Desliga as entradas AC
     CMCON = 7;         // Desliga os comparadores

/*                         Todas as I/O podem ser iniciadas ao mesmo tempo com TRISIO = 0b000000
                           Ou as I/O podem ser definidas unitáriamente conforme abaixo*/
                           
     TRISIO0_bit = 1;   // Define o primeiro pino de I/O como "input" digital
     TRISIO1_bit = 0;   // Define o segundo pino de I/O como "output" digital
     TRISIO2_bit = 0;   // Define o segundo pino de I/O como "output" digital
     TRISIO4_bit = 0;   // Define o segundo pino de I/O como "output" digital
     
     GPIO = 0;          // Define como '0' o valor dos I/O
     
     while (1)
     {
           GPIO.F1 = 0;
           GPIO.F2 = 0;
           GPIO.F4 = 1;
           if (GPIO.F0)
           {
              GPIO.F4 = 0;
              GPIO.F1 = 1;
              delay_ms (2000);
              GPIO.F1 = 0;
              GPIO.F2 = 1;
              delay_ms (500);
           }
     }
     
     
     

}