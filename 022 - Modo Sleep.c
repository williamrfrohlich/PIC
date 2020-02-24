#define led1  RA3_bit
#define led2  RA2_bit

bit control;

void interrupt()
{
   if(INTF_bit)                                    //Houve a interrupção externa?
   {
       INTF_bit = 0x00;                            //Limpa a flag
       
       control = ~control;                         //Inverte o valor de control
       
       led2 = ~led2;
       
       if(control) asm sleep;                      //Se control HIGH , mcu em modo sleep


   } //end if


} //end interrupt


void main()
{
     CMCON      = 0x07;                            //Desabilitar os comparadores
     OPTION_REG = 0x80;                            //Desligando os pull-ups, configurando a interrução por borda de descida
     GIE_bit    = 0x01;                            //Habilita interrupção global
     PEIE_bit   = 0x00;                            //Desabilitar a interrupção por periféricos
     INTE_bit   = 0x01;                            //Habilita a interrupção externa
     
     TRISA      = 0xf3;                            //Configura RA2 e RA3 como saída digital
     TRISB      = 0xff;                            //Configura todo como entrada
     
     led1       = 0x00;                            //desliga led1
     led2       = 0x00;                            //desliga led2
     
     control    = 0x00;                            //Inicializa control com valor LOW
     
     while(1)
     {
         led1 = 0x01;
         delay_ms(1000);
         led1 = 0x00;
         delay_ms(1000);
     
     } //end main


} //end main