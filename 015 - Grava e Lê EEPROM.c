#define  S2     RA0_bit
#define  S1     RA1_bit
#define  led2   RA2_bit
#define  led1   RA3_bit

void changeCont();                      //Muda o valor do contador
void gravaEEPROM();                     //Grava o valor atual do display da EEPROM
void leEEPROM();                        //Função para leitura da EEPROM


 int cont = 0x00;                      //cont incremento/decremento do display (dado a ser armazenado na EEPROM)
 
 unsigned char adress = 0x01;          //Variável conterá o valor inicial do endereço
 
 unsigned store;

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

     CMCON = 0x07;             //desabilita comparadores

     TRISA = 0x03;
     TRISB = 0x00;             //todo PORTB configurado como saída
     PORTA = 0x03;
     PORTB = 0x00;             //PORTB inicia em nível baixo


      leEEPROM();


    while(1)
    {

        changeCont();            //Muda o valor de Count

        if(!S2) gravaEEPROM();   //Se pressionar S2, grava valor atual de Count na EEPROM

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
   unsigned char aux1, aux2;              //Variáveis auxiliares locais
   
   aux1 = EEPROM_Read(0x00);              //Lemos o endereço 0h da EEPROM e armazemos o valor na aux1
   
   if(aux1 == 0xFF)                       //Testando aux1, EEPROM limpa?
   {                                      //Sim...
     EEPROM_Write(0x00,adress);           //Força escrita do valor 1 no endereço 0x00;
     delay_ms(10);                        //Tempo para escrita
   }

   store = EEPROM_Read(0x00);             //Lemos o valor do endereço zero e salvamos em store
   delay_ms(10);                          //Tempo para escrita
   aux2 = store;                          //Armazena o valor de store em aux2
   EEPROM_Write(store, cont);             //Salvamos o valor atual de cont no endereço de número "store"
   delay_ms(10);
   
   aux2++;                                //Incrementa aux2
   
   if(aux2 > 128) aux2 = 0x00;            //Teste se aux2 é maior que 128
   
   EEPROM_Write(0x00,aux2);               //Salva o valor de aux2 no endereço 00 da eeprom

   
   delay_ms(10);
   led1 = 0x01;
   delay_ms(500);
   led1 = 0x00;
}

void leEEPROM()
{
   unsigned char anchor;
   
   anchor = EEPROM_Read(0x00);
   
   cont = EEPROM_Read(0x00+(anchor-1));

}
