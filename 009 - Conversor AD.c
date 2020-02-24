#define D1 GPIO.F1
#define D2 GPIO.F2
#define D3 GPIO.F4
#define D4 GPIO.F5

int leitura = 0;

void main()
{
  ANSEL = 1;  				// 0b00000001	Seleciona o AN0 como entrada analógica
  ADCON0 = 1; 				// 0b00000001	Seleciona a entrada AN0
  CMCON = 7;
  
  TRISIO = 1;				// Define que GPIO.F0 seja uma entrada
  GPIO = 0;					// Inicia tudo em nível lógico baixo
  
  while(1)
  {
    leitura = ADC_Read(0);	// Leitura recebe o valor do AD
    
    if(leitura > 0)			// Se a variável leitura tiver valor 0
    {
      D1 = 0;
      D2 = 0;
      D3 = 0;
      D4 = 0;
    }
    if(leitura > 204)		// Se a variável leitura tiver valor 204
    {
      D1 = 1;
      D2 = 0;
      D3 = 0;
      D4 = 0;
    }
    if(leitura > 408)		// Se a variável leitura tiver valor 408
    {
      D1 = 1;
      D2 = 1;
      D3 = 0;
      D4 = 0;
    }
    if(leitura > 612)		// Se a variável leitura tiver valor 612
    {
      D1 = 1;
      D2 = 1;
      D3 = 1;
      D4 = 0;
    }
    if(leitura > 816)		// Se a variável leitura tiver valor 816
    {
      D1 = 1;
      D2 = 1;
      D3 = 1;
      D4 = 1;
    }
  
     delay_ms(100); //taxa de atualização do ADC
  } //end while

} //end main