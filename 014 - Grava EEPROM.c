
#define  S2     RA0_bit
#define  S1     RA1_bit
#define  led2   RA2_bit
#define  led1   RA3_bit

void changeCont();                      //Muda o valor do contador
void gravaEEPROM();                     //Grava o valor atual do display da EEPROM


 int cont = 0x00;                      //cont incremento/decremento do display (dado a ser armazenado na EEPROM)

 unsigned char catodo;                 //catodo recebe o valor de cont

 unsigned char segmento[10] = {0x3f,   // display '0'
                               0x06,   // display '1'
                               0x5b,   // display '2'
                               0x4f,   // display '3'
                               0x66,   // display '4'
                               0x6d,   // display '5'
                               0x7d,   // display '6'
                               0x07,   // display '7'
                               0x7f,   // display '8'
                               0x67};  // display '9'

void main()
{

 CMCON = 0x07; //desabilita comparadores

 TRISA = 0x03;
 TRISB = 0x00; //todo PORTB configurado como saída
 PORTA = 0x03;
 PORTB = 0x00; //PORTB inicia em nível baixo

     cont = EEPROM_Read(0x00);

    while(1)
    {

        changeCont();
        
        if(!S2) gravaEEPROM();

        catodo = segmento[cont]; //numero a ser enviado para PORTB

        PORTB = catodo;          //envia pattern para PORT B

        delay_ms(100);

    } //end while

} //end void main

void changeCont()
{
   if(!S1)
   {
     cont++;
     delay_ms(100);
     
     if(cont > 0x09) cont = 0x00;
   
   }

} //end changeCont


void gravaEEPROM()
{
   EEPROM_Write(0x00, cont);
   delay_ms(10);
   led1 = 0x01;
   delay_ms(500);
   led1 = 0x00;
}
