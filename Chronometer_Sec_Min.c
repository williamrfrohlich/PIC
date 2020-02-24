//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: Chronometer Sec/Min
//
//		Date: 2018.10.14
//
//------------------------------------------------

void main()
{
     int segundo_u, segundo_d, minuto_u, minuto_d;

     segundo_u = 00;                       // Contador de Unidade de Segundo
     segundo_d = 00;                       // Contador de Dezena de Segundo
     minuto_u = 00;                        // Contador de Unidade de Minuto
     minuto_d = 00;                        // Contador de Dezena de Minuto

     TRISA = 0b000000;                     // Define todas as portas A como saída
     PORTA = 0b000000;                     // Define todas as portas A com valor inicial '0'

     TRISC = 0b110000;                     // Define as portas 04 e 05 como entrada e as demais como saída
     PORTC = 0b000000;                     // Define todas as portas C com valor inicial '0'

     while (1)
     {
           while(RC5_bit == 0)                        // Botão Start/Stop - Quando estiver em 0, manterá contando
           {
                delay_ms(1000);                       // Tempo de 1 segundo
                segundo_u ++;                        // Soma mais 1 no valor do contador de unidade de segundo
                if (segundo_u == 10)                 // Se o contador de unidade for '10', então...
                {
                     segundo_u = 00;                 // O contador de unidade de segundo assumirá '0'
                     segundo_d ++;                   // O contador de dezena de segundo soma mais 1
                     if (segundo_d == 6)             // Se o contador de dezena chegar em '6', então...
                     {
                          segundo_u = 00;            // O contador de unidade de segundo assume valor '0'
                          segundo_d = 00;            // O contador de dezena de segundo assume valor '0'
                          minuto_u ++;                // Soma 1 na variável minuto quando o contador de dezena chegar a '6'
                          if (minuto_u == 10)         // Quando o contador de unidade de minuto chegar a '10'...
                          {
                               minuto_u = 00;         // O contador de unidade de minuto assume valor '0'
                               minuto_d ++;           // O contador de unidade de dezena soma mais 1
                          }
                     }
                }
                if (RC4_bit == 0)                     // Se o valor da porta RC4 for 0, mostra os segundos...
                {
                     PORTC = segundo_u;              // As portas C assumem o valor do contador de unidade de segundo
                     PORTA = segundo_d;              // As portas A assumem o valor do contador de dezena de segundo
                }
                else                                  // Se o valor da porta RC4 for 1, mostra os minutos...
                {
                     PORTC = minuto_u;                // As portas C assumem o valor do contador de unidade de minuto
                     PORTA = minuto_d;                // As portas A assumem o valor do contador de dezena de minuto
                }
           }
     }
}