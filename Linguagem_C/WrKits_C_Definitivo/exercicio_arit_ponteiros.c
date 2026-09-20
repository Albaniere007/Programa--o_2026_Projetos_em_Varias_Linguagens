#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define LEVELS 16

void disp_stk();
void push(int value);
int pop();


int count;
char *ptr1, *ptr2, stk[LEVELS];

int main(){

    


    int option, data_stk;

    ptr1 = stk;
    ptr2 = stk;

    for( ; ; ){
        printf("1 - mostrar pilha\n");
        printf("2 - inserir um dado\n");
        printf("3 - remover um dado\n");
        printf("4 - Sair");
        printf(">>>");
        scanf("%d", &option);

        switch(option){


            case 1: disp_stk();
                break;
            case 2: printf("Digite um dado!");
                scanf("%d", &data_stk);
                push(data_stk);
                break;
            case 3: pop();
                break;
            case 4: system("pause");
                exit(0);
        }

        system("clear");


        
    }

    system("pause");
    return 0;
}

void disp_stk(){

    register int i;

    for(i=0; i<=count;i++){
            printf("Stack level %2d: %X\n", i , stk[i]);
        system("PAUSE");

    }



}




void push(int value){
    register long t;

    ptr1++;
    count++;

    if(ptr1 == ptr2+LEVELS){
        printf("STACK OVERFLOW\n");
        system("pause");
        exit(0);

    }else
        printf("Adicionado\n");
    

    for(t=0; t<1E9;t++);
    *ptr1=value;





}


int pop(){
    register long t;

    if(ptr1 == ptr2){

        printf("STACK EMPTY\n");
        system("pause");
    }else
        printf("Removido!\n");
    for(t=0; t<1E9; t++);

    ptr1--;
    count--;

    return *(ptr1+1);
}