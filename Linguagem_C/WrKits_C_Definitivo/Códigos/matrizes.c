#include<stdlib.h>
#include<stdio.h>




unsigned int matriz[4][6] = {0};
int row, column, valor_a_inserir;

void print_matrix();

int main(){
    
   


   while (1)
   {
    print_matrix();
    printf("Linha: \n");
    scanf("%d", &row);
    printf("Coluna \n");
    scanf("%d", &column);
    printf("Valor a inserir\n");
    scanf("%d", &valor_a_inserir);
    if(1<row<=4 && 1<column<=6){
        row -=1;
        column -=1;
        matriz[row][column]=valor_a_inserir;}
    else{
        row=0;
        column=0;
        valor_a_inserir=0;
    }
    system("clear");
   }
   

    
    return 0;
}



void print_matrix(){


    printf("=====================================\n");
    for(int i=0; i<4; i++){
 
         
 
         for(int j =0; j<6; j++){
             
             if (j<5){
                 printf("| %3d ", matriz[i][j] );
             }else{
                 printf("| %3d |", matriz[i][j] );
             }
             
         }
         
         putchar('\n');
         
         
    }
    
    printf("=====================================\n");
}