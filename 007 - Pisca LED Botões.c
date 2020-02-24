#define S1   RA1_bit
#define S2   RA0_bit
#define led1 RA3_bit
#define led2 RA2_bit


void main()
{
  CMCON = 7;	// Desliga os comparadores
  TRISA = 3;    // 0b00000011
  PORTA = 3;	// 0b00000011
  
  while(1)
  {
    if(S1 == 0)
    {
      while(1) //programa 1
      {
        led1 = 1;
        led2 = 0;
        delay_ms(500);
        led1 = 0;
        led2 = 1;
        delay_ms(500);
      }
    }
    if(S2 == 0)
    {
      while(1) //programa 2
      {
        led1 = 1;
        led2 = 1;
        delay_ms(500);
        led1 = 0;
        led2 = 0;
        delay_ms(500);
      }
    }
  
  
  }   //end loop principal


}   //end main