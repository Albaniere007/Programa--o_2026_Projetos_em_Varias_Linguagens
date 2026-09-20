#include<stdlib.h>
#include<stdio.h>

#define pi=3.1416
#define multi(a,b)  a*b


int converte_bits(int valor);





int main(){


    int valor = 0.0;
    

    printf("Informe um valor entre 0 e 1023\n");
    scanf("%d", &valor);

    printf("O valor %d convertido em escala de 8 bits é: %d!\n", valor, converte_bits(valor));
    

    int  multiplicacao = multi(3,7);

    
    return 0;
}



int converte_bits(int valor){

    int conv;

    conv = (255*valor)/1023;



    return conv;
}