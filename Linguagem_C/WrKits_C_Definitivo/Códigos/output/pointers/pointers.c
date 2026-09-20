#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>


#define SOMA 0
#define SUBTRAI 1
#define MULTIPLICA 2
#define DIVIDE 3

typedef struct {

    char* nome;
    int idade;

}Pessoa;


int soma( int a, int b);
int subtrai( int a, int b);
int multiplica( int a, int b);
int divide(int a, int b);
void preencherNomes(char** nomes, int qtd);


int main(){




    printf("A festa dos ponteiros!!!!\n\n");

    //Aritmética de ponteiros
    int *pointer = malloc(sizeof(int)*3);
    pointer[0]=1;
    pointer[1]=2;
    pointer[2]=3;


    printf("0->%d\n", *pointer);
    printf("1->%d\n", *pointer+1);
    printf("2->%d\n", *pointer+2);
    free(pointer);

    //Ponteiro simples
    int num =20;
    printf("num=%d\n",num);
    int* ptr= &num;
    *ptr = 40;
    printf("num=%d\n", num);

    //Ponteiro para string


    char* string = malloc(sizeof(char)*20);
    strcpy(string, "Lucas Developer");
    printf("string=%s\n", string);
    free(string); //IMPORTANTE !!!!!!



    //Ponteiro para Struct

    Pessoa* pessoa = malloc(sizeof(Pessoa));
    pessoa ->idade = 43;
    pessoa->nome=malloc(sizeof(char)*20);
    strcpy(pessoa->nome,"Lucas");

    printf("Pessoa nome=%s, idade = %d\n", pessoa->nome, pessoa->idade);
    free(pessoa->nome);
    free(pessoa);//Nessa ordem



    //Ponteiro para função

    int (*func)(int, int )= soma;
    printf("soma=%d\n", soma(10,20));//Tanto essa
    printf("soma=%d\n",func(20,30));//Quanto essa maneira é possível



    //Ponteiro para ponteiros

    int qtd =5;
     char** nomes = malloc(sizeof(char*)*qtd);
     preencherNomes(nomes,qtd);
     for(int i=0; i<qtd;i++){
        printf("nome[%d]=%s\n",i, nomes[i]);
        free(nomes[i]);
     }

     free(nomes);



    //Ponteiros para função



    int (*funcs[])(int, int)={soma, subtrai,multiplica,divide};




    for (int i=0; i<4;i++){
        printf("Operação[%d]=%d\n", i, funcs[i](10,20));
    }


    funcs[SOMA](20,30);


    printf("Fim da festa!!!\n\n");

    return 0;

}



int soma(int a, int b){

    return a + b;
}

int subtrai(int a, int b){
    return a-b;
}

int multiplica(int a, int b){
    return a*b;
}


int divide(int a, int b){
    return a/b;
}


#define STRING_SIZE 20

void preencherNomes(char** nomes, int qtd){

    for(int i=0; i<qtd; i++){
        nomes[i] = malloc(sizeof(char) * STRING_SIZE);
    }

    strcpy(nomes[0], "MARIA");
    strcpy(nomes[1], "JOSE");
    strcpy(nomes[2], "PEDRO");
    strcpy(nomes[3], "PAULO");
    strcpy(nomes[4], "MADALENA");



}