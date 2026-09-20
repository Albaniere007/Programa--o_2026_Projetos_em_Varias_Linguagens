#include<stdlib.h>
#include<stdio.h>




int main(){


    int degraus;                       

    
    

    printf("Quantos degraus tem a escada?\n");
    scanf("%d", &degraus);


    /* 
    
    ----------------NÃO ESQUECER:----------------- 
    
    0 - 0 , 1 - 0 ,  1 - 1 , 2 - 0 , 2 - 1,  2 - 2

    ----------------NÃO ESQUECER------------------ 
    
    */
    for (int i=0; i<degraus; i++){
        
       

        for(int j=0; j<=i; j++){
            

            printf("#");
            
        }

        printf("\n");
        
        
    }
        

    printf("Pressione qualquer tecla para sair...\n");
    getchar();

    
    return 0;
}