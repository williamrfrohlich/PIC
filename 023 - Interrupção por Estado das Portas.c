// --- Função de Interrupção ---
void interrupt()
{
     if(RBIF_bit)                     				//Houve a mudança de estado no PORTB<7:4> ?
     {                               				//Sim...
     
        RBIF_bit = 0x00;              				//Limpa a flag
         
        if(RB4_bit) RC4_bit = ~RC4_bit;           	//Inverte o estado da saída
         
        delay_us(500);
     
     
     } //end if


} //end interrupt

// --- Função Principal ---
void main() 
{
     CMCON     = 0x07;                 //Desabilita os comparadores
     RBIE_bit  = 0x01;                 //Habilita a interrupção por mudança do PORTB<7:4>
     RBIF_bit  = 0x00;                 //Força a flag de sinalização a zero
     GIE_bit   = 0x01;                 //Habilita a interrupção global
     
     TRISB     = 0xFF;                 //Todo PORTB será entrada digital
     TRISC     = 0xEF;                 //Apenas o RC4 será saída digital
     
     RC4_bit   = 0x00;                 //Inicia a saída em low
     
     
     while(1)
     {
     
     
     } //end while


} //end main















