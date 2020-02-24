bit control;

void interrupt()
{
   if(INTF_bit)               //Houve a interrup��o externa?
   {                          //Sim..
      control = ~control;    //Inverte o estado da vari�vel de controle
      INTF_bit = 0x00;       //Limpa a flag   
      
      if(control) RA0_bit = 0x01; //Se control igual a 1, acende o led vermelho

      else RA0_bit = 0x00;        //Sen�o, apaga LED vermelho.
   }


}

void main()
{
   CMCON = 0x07;        //Desabilita os comparadores internos
   OPTION_REG = 0x80;
   GIE_bit = 0x01;      //Habilita a interrup��o global
   PEIE_bit = 0x00;     //Desabilita a interrup��o por perif�ricos
   INTE_bit = 0x01;     //Habilita a interrup��o externa
   INTEDG_bit = 0x00;   //Configura a interrup��o por borda de descida
   
   TRISA = 0xFC;        // RA0 e RA1 ser�o sa�da digital
   TRISB = 0xFF;        // Todo PORTB ser� entrada digital
   
   PORTA = 0xFC;        // RA0 e RA1 iniciam em low
   PORTB = 0xFF;        // Iniciando em high
   
   control = 0x00;      // Vari�vel de controle inicia em zero
   
   while(1)
   {
      RA1_bit = 0x01;   //Liga o LED verde
      delay_ms(2000);   //Aguarda 2 segundos
      RA1_bit = 0x00;   //Desliga o LED verde
      delay_ms(2000);   //Aguarda 2 segundos  
   }
}