#include<stdio.h>
#include<stdlib.h>
#include<locale.h>





int main(){


    int a= 0;
    int b = 1;
    int c = 0;
    int cont = 0;
    
    

    printf("%d ", a);
    printf("%d ", b);

    while (cont<=15)
    {   
        c = a + b;
        printf("%d ", c);
        
        a = b;
        b = c;
            
        cont++;
    }
    

    system("PAUSE");
    return 0;

}