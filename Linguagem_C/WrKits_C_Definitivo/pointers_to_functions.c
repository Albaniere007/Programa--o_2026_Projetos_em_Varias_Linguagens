#include <stdio.h>

// Função de protocolo original, exatamente como no Box 7
char protocol(int op1, int op2) {
    char response;
    response = op1 > op2 ? 'H' : 'L';
    return response;
}

// A função que recebe os operandos e o ponteiro para a função de protocolo
void processarProtocolo(int op1, int op2, char (*protoFunc)(int, int)) {
    // Chama a função de protocolo para obter o resultado
    char resultado = protoFunc(op1, op2);
    
    // Imprime a saída no formato exato solicitado: "Resultado do protocolo: X"
    printf("Resultado do protocolo: %c\n", resultado);
}

int main() {
    int operando1 = 10;
    int operando2 = 5;

    // Caso 1: Primeiro operando maior (deve retornar 'H')
    processarProtocolo(operando1, operando2, protocol);

    operando1 = 3;
    operando2 = 8;
    
    // Caso 2: Primeiro operando menor (deve retornar 'L')
    processarProtocolo(operando1, operando2, protocol);

    return 0;
}