#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float corrigir_numero_input(char *valor_str);


int main(){




    return 0;
}



float corrigir_numero_input(char *valor_str){

    for(int i = 0; valor_str[i] != '\0'; i++){
        if(valor_str[i]==','){
            valor_str[i] = '.';
            break;
        }
    }

    return strtod(valor_str, NULL);
}
