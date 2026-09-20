#include<stdio.h>
#include<stdlib.h>
#include<locale.h>





int main(){


    setlocale(LC_ALL,"Portuguese_Brazil");

    //Altera o . para ,

    unsigned short num_a_inserir, a , b, c , d ;

    printf("Digite um número <= a 85\n");
    scanf("%hu", &num_a_inserir);


    if(num_a_inserir > 85)
        printf("O número deve ser no máximo 85");
        scanf("%hu", &num_a_inserir);

    a = ++num_a_inserir;
    b = --num_a_inserir-1;

    c = a + b + num_a_inserir;

    d = c*c;


    printf("Incremento de %hu é  %hu\n", num_a_inserir, a);
    printf("Decremento de %hu é  %hu\n", num_a_inserir, b);
    printf("A soma de  de %hu, %hu e %hu é: %hu\n", num_a_inserir, a, b, c);
    printf("O quadrado da soma %hu é  %hu\n", c, d);

    puts("Fim do código");
    

    system("PAUSE");
    return 0;

}