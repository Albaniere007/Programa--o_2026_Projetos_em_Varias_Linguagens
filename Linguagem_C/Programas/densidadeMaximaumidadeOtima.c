#include <stdio.h>
#include <stdlib.h>


void calculaDenominadores(double w1, double w2, double w3, double *D1, double *D2, double *D3);
double calculaCoeficienteA(double p1, double p2, double p3, double D1, double D2, double D3);
double calculaCoeficienteB(double p1, double p2, double p3, double w1, double w2, double w3, double D1, double D2, double D3);
double calculaUmidadeOtima(double A, double B);
double calculaDensidadeMaxima(double p1, double p2, double p3, double w1, double w2, double w3, double D1, double D2, double D3, double wotima);

int main() {
    double p[5], w[5];

    // Leitura dos 5 pontos do ensaio Proctor
    printf("=== ENTRADA DE DADOS DO ENSAIO PROCTOR ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Informe a densidade do %dº ponto: ", i + 1);
        scanf("%lf", &p[i]);
        printf("Informe a umidade do %dº ponto (%%): ", i + 1);
        scanf("%lf", &w[i]);
    }

    
    int idxMax = 0;
    for (int i = 1; i < 5; i++) {
        if (p[i] > p[idxMax]) {
            idxMax = i;
        }
    }

    
    if (idxMax == 0 || idxMax == 4) {
        printf("\n[ERRO] O pico de densidade ocorreu na extremidade (ponto %d).\n", idxMax + 1);
        printf("Para interpolar por Lagrange, é necessário ter pontos antes e depois do pico.\n");
        return 1;
    }

    
    double p1 = p[idxMax - 1], p2 = p[idxMax], p3 = p[idxMax + 1];
    double w1 = w[idxMax - 1], w2 = w[idxMax], w3 = w[idxMax + 1];

    
    double D1, D2, D3;
    calculaDenominadores(w1, w2, w3, &D1, &D2, &D3);

   
    if (D1 == 0 || D2 == 0 || D3 == 0) {
        printf("\n[ERRO] Umidades idênticas detectadas. Os valores de umidade devem ser distintos.\n");
        return 1;
    }

    double A = calculaCoeficienteA(p1, p2, p3, D1, D2, D3);
    double B = calculaCoeficienteB(p1, p2, p3, w1, w2, w3, D1, D2, D3);

   
    if (A >= 0) {
        printf("\n[AVISO] Os pontos selecionados não formam uma parábola côncava para baixo (A >= 0).\n");
    }

    double wotima = calculaUmidadeOtima(A, B);
    double densidadeMax = calculaDensidadeMaxima(p1, p2, p3, w1, w2, w3, D1, D2, D3, wotima);

    // Exibição dos resultados finais
    printf("\n================ RESULTADOS (LAGRANGE) ================\n");
    printf("Ponto de pico detectado: %dº ponto (%.2lf kg/m³ @ %.2lf%%)\n", idxMax + 1, p[idxMax], w[idxMax]);
    printf("Coeficiente A: %lf\n", A);
    printf("Coeficiente B: %lf\n", B);
    printf("Umidade Ótima (Wót): %.2lf%%\n", wotima);
    printf("Densidade Seca Máxima: %.2lf kg/m³\n", densidadeMax);

    return 0;
}

void calculaDenominadores(double w1, double w2, double w3, double *D1, double *D2, double *D3) {
    *D1 = (w1 - w2) * (w1 - w3);
    *D2 = (w2 - w1) * (w2 - w3);
    *D3 = (w3 - w1) * (w3 - w2);
}

double calculaCoeficienteA(double p1, double p2, double p3, double D1, double D2, double D3) {
    return (p1 / D1) + (p2 / D2) + (p3 / D3);
}

double calculaCoeficienteB(double p1, double p2, double p3, double w1, double w2, double w3, double D1, double D2, double D3) {
    return -(((p1 * (w2 + w3)) / D1) + ((p2 * (w1 + w3)) / D2) + ((p3 * (w1 + w2)) / D3));
}

double calculaUmidadeOtima(double A, double B) {
    return (-1.0 * B) / (2.0 * A);
}

double calculaDensidadeMaxima(double p1, double p2, double p3, double w1, double w2, double w3, double D1, double D2, double D3, double wotima) {
    double L1 = ((wotima - w2) * (wotima - w3)) / D1;
    double L2 = ((wotima - w1) * (wotima - w3)) / D2;
    double L3 = ((wotima - w1) * (wotima - w2)) / D3;

    return (p1 * L1) + (p2 * L2) + (p3 * L3);
}