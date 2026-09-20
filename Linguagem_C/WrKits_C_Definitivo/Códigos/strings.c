#include<stdio.h>
#include<stdlib.h>






int main(){


    char nome[30]={'L','u','c','a','s'};
    char nome_completo[30]="Lucas Albaniere";

    puts("Freire");

    char nome_todo[20];


    printf("Insira o nome todo");
    scanf("%s", nome_todo);
    gets(nome_todo); //Para strings mais longas


    printf("%d\n", sizeof(nome));
    printf("%d\n", sizeof(nome_completo));

    printf("Meu nome: %s\n", nome);


    return 0;
}