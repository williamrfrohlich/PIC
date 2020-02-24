bit control;

void interrupt()
{
   if(INTF_bit)               //Houve a interrupção externa?
   {                          //Sim..
      control = ~control;    //Inverte o estado da variável de controle
      INTF_bit = 0x00;       //Limpa a flag   
      
      if(control) RA0_bit = 0x01; //Se control igual a 1, acende o led vermelho

      else RA0_bit = 0x00;        //Senão, apaga LED vermelho.
   }


}

void main()
{
   CMCON = 0x07;        //Desabilita os comparadores internos
   OPTION_REG = 0x80;
   GIE_bit = 0x01;      //Habilita a interrupção global
   PEIE_bit = 0x00;     //Desabilita a interrupção por periféricos
   INTE_bit = 0x01;     //Habilita a interrupção externa
   INTEDG_bit = 0x00;   //Configura a interrupção por borda de descida
   
   TRISA = 0xFC;        // RA0 e RA1 serão saída digital
   TRISB = 0xFF;        // Todo PORTB será entrada digital
   
   PORTA = 0xFC;        // RA0 e RA1 iniciam em low
   PORTB = 0xFF;        // Iniciando em high
   
   control = 0x00;      // Variável de controle inicia em zero
   
   while(1)
   {
      RA1_bit = 0x01;   //Liga o LED verde
      delay_ms(2000);   //Aguarda 2 segundos
      RA1_bit = 0x00;   //Desliga o LED verde
      delay_ms(2000);   //Aguarda 2 segundos  
   }
}