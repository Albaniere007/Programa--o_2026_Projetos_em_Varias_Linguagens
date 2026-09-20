#include<stdio.h>
#include<stdlib.h>




int main(){

    char chr='0';
    int num2=3, num3=4;
    
    //Sempre inicializar vaiáveis

    scanf("%c",&chr);
    printf("O caractere digitado foi: %c\n",chr);
    //Para a inserção de mais caracteres usar o espaço após a primeira aspas do scanf:
    scanf(" %d",&num2);

    //casting
    (float) num2/num3;



    system("PAUSE");
    return 0;
}