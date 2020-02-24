//------------------------------------------------
//		Author: Eng. William da Rosa Fröhlich
//
//		Project: Counter
//
//		Date: 2018.10.13
//
//------------------------------------------------

void main()
{
     int contador_u, contador_d;
     
     contador_u = 00;           // Contador do Display de Unidade
     contador_d = 00;           // Contador do Display de Dezena

     TRISA = 0b000000;          // Define todas as portas A como saída
     PORTA = 0b000000;          // Define todas as portas A com valor inicial '0'

     TRISC = 0b110000;          // Define as portas 04 e 05 como entrada e as demais como saída
     PORTC = 0b000000;          // Define todas as portas C com valor inicial '0'
     
     while(1)
     {
           delay_ms(1000);                // Tempo de 1 segundo
           contador_u++;                  // Soma mais 1 no valor do contador de unidade
           PORTC = contador_u;            // As portas C assumem o valor do contador de unidade
           if (contador_u == 10)          // Se o contador de unidade for '10', então...
           {
              contador_u = 00;            // O contador de unidade assumirá '0'
              PORTC = contador_u;         // As portas C assumem o valor do contador de unidade
              contador_d++;               // O contador de dezena soma mais 1
              if (contador_d == 6)        // Se o contador de dezena for '6', então...
              {
                 PORTA = contador_d;      // As portas A assumem o valor do contador de dezena
                 delay_ms(1000);          // Tempo de 1 segundo
                 contador_u = 00;         // O contador de unidade assume valor '0'
                 contador_d = 00;         // O contador de dezena assume valor '0'
              }
              PORTA = contador_d;         // As portas A assumem o valor do contador de dezena
           }
     }
}