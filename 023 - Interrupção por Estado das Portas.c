// --- Fun��o de Interrup��o ---
void interrupt()
{
     if(RBIF_bit)                     				//Houve a mudan�a de estado no PORTB<7:4> ?
     {                               				//Sim...
     
        RBIF_bit = 0x00;              				//Limpa a flag
         
        if(RB4_bit) RC4_bit = ~RC4_bit;           	//Inverte o estado da sa�da
         
        delay_us(500);
     
     
     } //end if


} //end interrupt

// --- Fun��o Principal ---
void main() 
{
     CMCON     = 0x07;                 //Desabilita os comparadores
     RBIE_bit  = 0x01;                 //Habilita a interrup��o por mudan�a do PORTB<7:4>
     RBIF_bit  = 0x00;                 //For�a a flag de sinaliza��o a zero
     GIE_bit   = 0x01;                 //Habilita a interrup��o global
     
     TRISB     = 0xFF;                 //Todo PORTB ser� entrada digital
     TRISC     = 0xEF;                 //Apenas o RC4 ser� sa�da digital
     
     RC4_bit   = 0x00;                 //Inicia a sa�da em low
     
     
     while(1)
     {
     
     
     } //end while


} //end main















