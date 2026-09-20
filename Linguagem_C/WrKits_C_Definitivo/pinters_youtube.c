#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<stdlib.h>

#define STRING_SIZE 20


typedef struct { //typedef define um tipo -- um apelido para uma struct ou um int p exemplo
    char * nome;
    int idade;
}Pessoa;


int soma(int a , int b);

void fillNames(char ** nomes, int qtd);


int main(){

    printf("Festa dos ponteiros ******\n\n");

    //Ponteiro simples
    int num = 20;
    printf("num=%d\n", num);
    int * ptr = &num; // -> para saber o endereço da variável--Referencia
    *ptr = 40;
    printf("num=%d\n", num);

    printf("------------------------------------------------------------------------\n");

    //Ponteiro para String

    char *string =malloc(sizeof(char) * STRING_SIZE);
    strcpy(string, "LUCAS DEVELOPER");
    printf("string=%s\n", string);
    free(string); //-> fechar o malloc

    printf("------------------------------------------------------------------------\n");

    //Ponteiro para struct

    Pessoa * pessoa= malloc(sizeof(Pessoa));
    pessoa->idade=43;
    pessoa->nome= malloc(sizeof(char)*STRING_SIZE);
    strcpy(pessoa->nome, "LUCAS");

    printf("Pessoa: nome = %s, idade=%d\n", pessoa->nome, pessoa->idade);
    free(pessoa->nome);
    free(pessoa);

    printf("------------------------------------------------------------------------\n");

    //Ponteiro para função

    int (*func) (int, int) = soma; //Passar os parâmetros da função
    printf("Soma = %d\n", soma(10,20));
    printf("Soma = %d\n", func(10,20));


    printf("------------------------------------------------------------------------\n");



    //Ponteiro para ponteiro

    int qtd =5;
    char ** nomes = malloc(sizeof(char*)*qtd);
    fillNames(nomes,  qtd);

    for (int i =0; i<qtd; i++){
        printf("nome[%d]=%s\n", i, nomes[i]);
        free(nomes[i]);
    }

    free(nomes);


    printf("------------------------------------------------------------------------\n");


    //Ponteiro para ponteiros de função


    


    







    printf("Fim da festa dos ponteiros ******\n\n");


    return 0;
}



int soma(int a, int b){


    return a + b;
}



void fillNames(char ** nomes, int qtd){

    for(int i = 0; i< qtd; i++){
        nomes[i]=malloc(sizeof(char) * STRING_SIZE);
    }

    strcpy(nomes[0],"Maria");
    strcpy(nomes[1],"José");
    strcpy(nomes[2],"Pedro");
    strcpy(nomes[3],"Paulo");
    strcpy(nomes[4],"Madalena");

}