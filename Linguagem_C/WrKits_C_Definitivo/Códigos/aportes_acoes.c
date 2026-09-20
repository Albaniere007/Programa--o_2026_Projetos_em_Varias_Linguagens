#include<stdlib.h>
#include<stdio.h>



# define N 5

float quantidade_aportes[5];
float valor_aportes[5];
float total_aportes=0;
float total_aportes_realizados=0;
float diferença=0;

int main(){
    
    printf("Qual o valor total do aporte?\n");
    scanf("%f",&total_aportes); // Removed \n

    for (int i=0; i<N; i++){
        printf("Qual o valor da ação?");
        scanf("%f", &valor_aportes[i]); // Removed \n
        printf("Quantas ações comprar?");
        scanf("%f", &quantidade_aportes[i]); // Removed \n
        total_aportes_realizados+= (quantidade_aportes[i] * valor_aportes[i]);

    }

    diferença = total_aportes-total_aportes_realizados;

    if (diferença < 0)
        printf("Não foi possível realizar o aporte porque o valor aportado foi de %.2f e o valor indicado foi de %.2f!\n Repita a transação!", total_aportes, total_aportes_realizados);

    return 0;
}