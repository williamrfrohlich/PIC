//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: Chronometer Without Decoder
//
//		Date: 2018.11.11
//
//------------------------------------------------

//-----------------//  Biblioteca  //-------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------------------

//------------------//  Fuses  /------------------------------------------------
#define     _XTAL_FREQ     2000000
//------------------------------------------------------------------------------

//---------------//  Programa Principal  //-------------------------------------
void main()
{
     short int segundo_u = 00, segundo_d = 00, minuto_u = 00, minuto_d = 00, n = 0;
     
     short int display [10] = {0x00,0x39,0x24,0x30,0x19,0x12,0x03,0x38,0x00,0x18};
     short int display_g [10] = {1,1,0,0,0,0,0,1,0,0};

     ANSEL = 0;                            // Desabilita todas as portas analógicas
     CMCON = 7;                            // Desabilita os comparadores
     TRISA = 0b110000;                     // Define as portas 04 e 05 como entrada e as demais como saída
     PORTA = 0b000000;                     // Define todas as portas A com valor inicial '0'

     TRISC = 0b000000;                     // Define todas as portas C como saída
     PORTC = 0b000000;                     // Define todas as portas C com valor inicial '0'

     while (1)
     {
           while(RA5_bit == 0)                         // Botão Start/Stop - Quando estiver em 0, manterá contando
           {
                segundo_u ++;                          // Soma mais 1 no valor do contador de unidade de segundo
                if (segundo_u == 10)                   // Se o contador de unidade for '10', então...
                {
                     segundo_u = 0;                    // O contador de unidade de segundo assumirá '0'
                     segundo_d ++;                     // O contador de dezena de segundo soma mais 1
                     if (segundo_d == 6)               // Se o contador de dezena de segundo chegar em '6', então...
                     {
                          segundo_u = 0;               // O contador de unidade de segundo assume valor '0'
                          segundo_d = 0;               // O contador de dezena de segundo assume valor '0'
                          minuto_u ++;                 // Soma 1 na variável unidade de minuto quando o contador de dezena chegar a '6'
                          if (minuto_u == 10)          // Quando o contador de unidade de minuto chegar a '10'...
                          {
                               minuto_u = 0;           // O contador de unidade de minuto assume valor '0'
                               minuto_d ++;            // O contador de unidade de dezena soma mais 1
                          }
                     }
                }

                for (n=0; n <= 50; n++)                         // Para n = 0 será executado os comandos abaixo até n chegar em 50...
                {
                     if (RA4_bit == 0)                          // Se o valor da porta RC4 for 0, mostra os segundos...
                     {
                          RA1_bit = 1;                          // A porta 1 assume valor 1 ativando display 1
                          RA2_bit = 0;                          // A porta 2 assume valor 0 desativando display 2
                          PORTC = display[segundo_u];           // Todas as portas C assumem o valor do contador de unidade de segundo
                          RA0_bit = display_g[segundo_u];       // A porta A0 assume o valor do contador de unidade de segundo
                          delay_ms(10);                         // Aguarda 0,01 segundo
                          RA1_bit = 0;                          // A porta 1 assume valor 0 desativando display 1
                          RA2_bit = 1;                          // A porta 2 assume valor 1 ativando display 2
                          PORTC = display[segundo_d];           // Todas as portas C assumem o valor do contador de dezena de segundo
                          RA0_bit = display_g[segundo_d];       // A porta A0 assume o valor do contador de dezena de segundo
                          delay_ms(10);                         // Aguarda 0,01 segundo
                     }
                     else                                       // Se o valor da porta RC4 for 1, mostra os minutos...
                     {
                          RA1_bit = 1;                          // A porta 1 assume valor 1 ativando display 1
                          RA2_bit = 0;                          // A porta 2 assume valor 0 desativando display 2
                          PORTC = display[minuto_u];            // Todas as portas C assumem o valor do contador de unidade de segundo
                          RA0_bit = display_g[minuto_u];        // A porta A0 assume o valor do contador de unidade de segundo
                          delay_ms(10);                         // Aguarda 0,01 segundo
                          RA1_bit = 0;                          // A porta 1 assume valor 0 desativando display 1
                          RA2_bit = 1;                          // A porta 2 assume valor 1 ativando display 2
                          PORTC = display[minuto_d];            // Todas as portas C assumem o valor do contador de dezena de segundo
                          RA0_bit = display_g[minuto_d];        // A porta A0 assume o valor do contador de dezena de segundo
                          delay_ms(10);                         // Aguarda 0,01 segundo
                     }
                };
           }
     }
}
//------------------------------------------------------------------------------