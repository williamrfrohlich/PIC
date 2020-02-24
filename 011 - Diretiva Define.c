#define led1 RA3_bit
#define led2 RA2_bit
#define S1   RA1_bit
#define S2   RA0_bit

void main() 
{
   CMCON = 0x07;
   TRISA = 0x03; //RA0 e RA1 são entrada digital
   PORTA = 0x03; //RA0 e RA1 iniciam em HIGH
   
   while(1)
   {
     led1 = 0x01;
     led2 = 0x00;
     delay_ms(10);
     led1 = 0x00;
     led2 = 0x01;
     delay_ms(10);
   
   }


}