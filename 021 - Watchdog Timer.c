void main() 
{
    OPTION_REG = 0x8E;                  //Habilitamos o prescaler associado ao WDT (1:64)
                                        //Desabilita os resistores pull-up
    TRISB      = 0x7E;                  //RB0 e RB7 são saída digital
    
    PORTB      = 0x8E;                  //Liga RB7 e desliga RB0
    
    asm clrwdt;                         //Comando em Assembly que limpa o WDT
    
    while(1)
    {
       asm clrwdt;                      //Comando em Assembly que limpa o WDT
       
       RB0_bit = 0x01;
       delay_ms(300);
       RB0_bit = 0x00;
       delay_ms(300);
    
    
    } //end while

}