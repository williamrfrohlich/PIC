//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: Counter Interruption
//
//		Date: 2018.11.03
//
//------------------------------------------------

int counter = 0x00;
short int tempo_u = 0x00, tempo_d = 0x00;

void interrupt()
{
      if (T0IF_bit)
      {
           counter ++;
           TMR0 = 0x06;

           T0IF_bit = 0x00;
      }
}

void main()
{
//-- Registradores do Timer 0
     OPTION_REG = 0x81;
     INTCON = 0xE4;
     TMR0 = 0x06;

     CMCON = 7;

     TRISA = 0x00;
     PORTA = 0x00;
     TRISB = 0x00;
     PORTB = 0x00;

     while (1)
     {
          if (counter == 1000)
          {
              tempo_u++;
              PORTB = tempo_u;
              if (tempo_u == 10)
              {
                   PORTB = 0x00;
                   tempo_u = 0x00;
                   tempo_d++;
                   PORTA = tempo_d;
                   if (tempo_d == 7)
                   {
                        tempo_u = 0;
                        tempo_d = 0;
                        PORTA = 0;
                        PORTB = 0;
                   }
              }
              counter = 0;
          }
     }
}