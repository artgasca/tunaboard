/*
 * Project: TunaBoard-Test
 * Description: Test inicial tunaboard
 * Author: Arturo Gasca
 * Date:  Octubre-2018
 * Development: Tuna Shields
 *
 * Created on 18 de octubre de 2018, 06:07 PM
 */

 #include <18F46K22.h>
 #use delay(crystal=20mhz)
 #use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=uart1,restart_wdt)
 #use rs232(baud=9600,parity=N,xmit=PIN_D6,rcv=PIN_D7,bits=8,stream=uart2,restart_wdt)

#INT_RDA
void uart_1(){
    char c1;
    c1 = fgetc(uart1);
    fputc(c1,uart1);
}

#INT_RDA2
void uart_2(){
  char c2;
  c2 = fgetc(uart2);
  fputc(c2,uart2);

}

void main(void){
    set_tris_a(0b00000000);
    set_tris_b(0b00000000);
    set_tris_c(0b10000000);
    set_tris_d(0b10000000);
    enable_interrupts(GLOBAL);
    enable_interrupts(INT_RDA);
    enable_interrupts(INT_RDA2);
    
    fprintf(uart1,"Hola UART1!\r\n");
    fprintf(uart2,"Hola UART2!\r\n");
    while(true){
        fprintf(uart1,"Hola Mundo!\r\n");
        output_toggle(PIN_B0);
        output_toggle(PIN_B1);
        delay_ms(2000);
        
    }
}
