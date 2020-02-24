//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: External Interruption
//
//		Date: 2018.11.03
//
//------------------------------------------------

#define S1 RA0_bit
#define S2 RA1_bit
#define LED1 RA2_bit
#define LED2 RA3_bit

int counter;

void interrupt ()
{
      if (T0IF_bit)
      {
           counter++;
           T0IF_bit = 0b00000000;
           TMR0 = 0b00000110;
           if (S1)
           {
               LED1 = ~LED1;
           }
           if (S2)
           {
                LED2 = ~LED2;
           }
      }
}

void main() 
{
     CMCON      = 0b00000111;
     OPTION_REG = 0b10000001;
     INTCON     = 0b11100100;
     TMR0       = 0b00000110;
     
     TRISA      = 0b00000000;
     PORTA      = 0b00000000;
     
     while(1)
     {
     
     }

}