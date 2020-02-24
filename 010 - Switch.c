
void nibbleDown(char number);
void nibbleUp(char number);

char counter1 = 0, counter2 = 0;

void main() 
{
   CMCON = 0x07;
   TRISA = 0x00;
   TRISB = 0x00;
   PORTA = 0x00;
   PORTB = 0x00;
   
   while(1)
   {
     counter1++;
     
     
     nibbleDown(counter1);
     nibbleUp(counter2);
     
     if(counter1 == 10)
     {
      counter2++;
      counter1 = 0;
      nibbleDown(counter1);
      nibbleUp(counter2);
          if(counter2 == 10)
          {
            counter2 = 0;
            nibbleUp(counter2);
          }
     }

      delay_ms(300);
   
   }

}

void nibbleDown(char number)
{
  switch(number)
  {
     case 0:
       RB0_bit = 0x00;
       RB1_bit = 0x00;
       RB2_bit = 0x00;
       RB3_bit = 0x00;
       break;
     case 1:
       RB0_bit = 0x01;
       RB1_bit = 0x00;
       RB2_bit = 0x00;
       RB3_bit = 0x00;
       break;
     case 2:
       RB0_bit = 0x00;
       RB1_bit = 0x01;
       RB2_bit = 0x00;
       RB3_bit = 0x00;
       break;
     case 3:
       RB0_bit = 0x01;
       RB1_bit = 0x01;
       RB2_bit = 0x00;
       RB3_bit = 0x00;
       break;
     case 4:
       RB0_bit = 0x00;
       RB1_bit = 0x00;
       RB2_bit = 0x01;
       RB3_bit = 0x00;
       break;
     case 5:
       RB0_bit = 0x01;
       RB1_bit = 0x00;
       RB2_bit = 0x01;
       RB3_bit = 0x00;
       break;
     case 6:
       RB0_bit = 0x00;
       RB1_bit = 0x01;
       RB2_bit = 0x01;
       RB3_bit = 0x00;
       break;
     case 7:
       RB0_bit = 0x01;
       RB1_bit = 0x01;
       RB2_bit = 0x01;
       RB3_bit = 0x00;
       break;
     case 8:
       RB0_bit = 0x00;
       RB1_bit = 0x00;
       RB2_bit = 0x00;
       RB3_bit = 0x01;
       break;
     case 9:
       RB0_bit = 0x01;
       RB1_bit = 0x00;
       RB2_bit = 0x00;
       RB3_bit = 0x01;
       break;
  } //end switch

}


void nibbleUp(char number)
{
  switch(number)
  {
     case 0:
       RB4_bit = 0x00;
       RB5_bit = 0x00;
       RB6_bit = 0x00;
       RB7_bit = 0x00;
       break;
     case 1:
       RB4_bit = 0x01;
       RB5_bit = 0x00;
       RB6_bit = 0x00;
       RB7_bit = 0x00;
       break;
     case 2:
       RB4_bit = 0x00;
       RB5_bit = 0x01;
       RB6_bit = 0x00;
       RB7_bit = 0x00;
       break;
     case 3:
       RB4_bit = 0x01;
       RB5_bit = 0x01;
       RB6_bit = 0x00;
       RB7_bit = 0x00;
       break;
     case 4:
       RB4_bit = 0x00;
       RB5_bit = 0x00;
       RB6_bit = 0x01;
       RB7_bit = 0x00;
       break;
     case 5:
       RB4_bit = 0x01;
       RB5_bit = 0x00;
       RB6_bit = 0x01;
       RB7_bit = 0x00;
       break;
     case 6:
       RB4_bit = 0x00;
       RB5_bit = 0x01;
       RB6_bit = 0x01;
       RB7_bit = 0x00;
       break;
     case 7:
       RB4_bit = 0x01;
       RB5_bit = 0x01;
       RB6_bit = 0x01;
       RB7_bit = 0x00;
       break;
     case 8:
       RB4_bit = 0x00;
       RB5_bit = 0x00;
       RB6_bit = 0x00;
       RB7_bit = 0x01;
       break;
     case 9:
       RB4_bit = 0x01;
       RB5_bit = 0x00;
       RB6_bit = 0x00;
       RB7_bit = 0x01;
       break;
  } //end switch

}