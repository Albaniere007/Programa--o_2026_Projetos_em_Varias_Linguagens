#include <stdio.h>
#include <stdlib.h>
#include <string.h>




double pesoInicial, pesoFinal,  areaBandeja,  residuoLaboratorio;

void calculaTaxa();
void imprimeTaxa();
void menuTaxaPrincipal();
void menuCalculaTaxa();


int main(){


    menuTaxaPrincipal();

    return 0;
}



void calculaTaxa(){

        

        double taxaLiquida = (pesoFinal-pesoInicial) /  areaBandeja;
        double taxaResidual = taxaLiquida * residuoLaboratorio;

        printf("TARA DA BANDEJA: %5.4f\n", pesoInicial);
        printf("TARA DA BANDEJA + MATERIAL: %5.4f\n", pesoFinal);
        printf("ÁREA DA BANDEJA: %5.4f\n", areaBandeja);
        printf("RESÍDUO DE LABORATÓRIO: %3.2f\n", residuoLaboratorio);
        printf("TAXA LÍQUIDA: %4.3f L/m²\n", taxaLiquida);
        printf("TAXA RESIDUAL: %4.3f Kg/m²\n", taxaResidual);

}

void imprimeTaxa(){

        
    
    
    FILE *arquivo;
    
    
    if ((arquivo = fopen("relatorio.txt", "w"))== NULL) {
        printf("\n[Erro] Nao foi possivel criar o arquivo relatorio.txt!\n\n");
        return;
    }

    
    double taxaLiquida = (areaBandeja > 0) ? (pesoFinal - pesoInicial) / areaBandeja : 0;
    double taxaResidual = taxaLiquida * residuoLaboratorio;

   
    fprintf(arquivo, "==================================================\n");
    fprintf(arquivo, "       RELATORIO TECNICO - TAXA DE LIGACAO        \n");
    fprintf(arquivo, "==================================================\n\n");
    
    fprintf(arquivo, "DADOS DO ENSAIO:\n");
    fprintf(arquivo, "--------------------------------------------------\n");
    fprintf(arquivo, "Tara da Bandeja:                     %5.4lf Kg\n", pesoInicial);
    fprintf(arquivo, "Tara da Bandeja + Material:          %5.4lf Kg\n", pesoFinal);
    fprintf(arquivo, "Area da Bandeja:                     %5.4lf m²\n", areaBandeja);
    fprintf(arquivo, "Residuo de Laboratorio:              %3.2lf (%%)\n", residuoLaboratorio * 100);
    fprintf(arquivo, "--------------------------------------------------\n\n");
    
    fprintf(arquivo, "RESULTADOS OBTIDOS:\n");
    fprintf(arquivo, "--------------------------------------------------\n");
    fprintf(arquivo, "TAXA LIQUIDA:                        %4.3lf L/m2\n", taxaLiquida);
    fprintf(arquivo, "TAXA RESIDUAL:                       %4.3lf Kg/m2\n", taxaResidual);
    fprintf(arquivo, "==================================================\n");

    
    fclose(arquivo);
    
    printf("\n[OK] Relatorio salvo com sucesso no arquivo 'relatorio.txt'!\n\n");

}

void menuTaxaPrincipal(){



    printf("*******************TAXA DE LIGAÇÃO*************************\n");
    char resposta = '1';
    while (resposta != '0')

    {
        printf("Calcular Taxa [ 2 ]\n");
        printf("Calcular Salvar PDF [ 3 ]\n");
        printf("Sair [ 0 ]\n");
        scanf(" %c", &resposta);
        switch (resposta)
        {
        case '2':
            menuCalculaTaxa();
            break;
            
        case '3':
            imprimeTaxa();
            break;
            
        case '0':
            break;    
        
       
        }

    }
    
}

void menuCalculaTaxa(){
    

    printf("Informe a tara da bandeja\n");
    scanf(" %lf", &pesoInicial);

    printf("Informe a tara da bandeja com material\n");
    scanf(" %lf", &pesoFinal);


    printf("Informe a área da bandeja\n");
    scanf(" %lf", &areaBandeja);

    printf("Informe o resíduo de laboratório\n");
    scanf(" %lf", &residuoLaboratorio);

    calculaTaxa();
}
