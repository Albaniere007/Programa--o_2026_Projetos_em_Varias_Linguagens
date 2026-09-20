#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>



int main() {

    // Ponteiro simples
    int num = 20;
    int* ptr = &num; // 'ptr' guarda o endereço da variável 'num'
    *ptr = 40;       // Altera o valor dentro de 'num' para 40 através do ponteiro

    /* 
     * SITUAÇÃO 1:
     * O 'num' vale 40, mas o '%p' espera um ponteiro/endereço.
     * O 'printf' pega o número inteiro 40 e o converte para hexadecimal.
     * Saída exibida: 0x28 (40 convertido para hexadecimal).
     */
    printf("Endereço de num = %p\n", num);

    /* 
     * SITUAÇÃO 2:
     * O '*ptr' pega o VALOR contido na variável (40), não o endereço.
     * O '%p' recebe esse número 40 e também o converte para hexadecimal.
     * Saída exibida: 0x28
     */
    printf("Endereço de *ptr = %p\n", *ptr);

    /* 
     * SITUAÇÃO 3:
     * Lê o valor inteiro da variável 'num' usando o formato correto '%d'.
     * Saída exibida: 40
     */
    printf("Valor de num = %d\n", num);

    /* 
     * SITUAÇÃO 4:
     * O '*' desreferencia o ponteiro (acessa o valor apontado por 'ptr').
     * Imprime o valor inteiro corretamente usando '%d'.
     * Saída exibida: 40
     */
    printf("Valor de *ptr = %d\n", *ptr);

    /* 
     * SITUAÇÃO 5:
     * Você passou o endereço real de memória ('ptr') para um formato de inteiro comum ('%d').
     * Isso gera um aviso no compilador. O endereço de 64-bits é forçado a virar
     * um número inteiro decimal, resultando em um valor negativo ou aparentemente aleatório.
     * Saída exibida: Ex: -123456789 (o número depende do endereço da RAM).
     */
    printf("Valor de *ptr = %d\n", ptr);

    /* 
     * SITUAÇÃO 6:
     * Você passou o ponteiro 'ptr' diretamente para o formato de endereço '%p'.
     * Esta é a forma correta de imprimir o endereço real da variável 'num'.
     * Saída exibida: Ex: 0x7ffd56a1b41c (o endereço exato em hexadecimal).
     */
    printf("Valor de *ptr = %p\n", ptr);
    




    printf("Fim da festa de ponteiros!\n\n");

    return 0;
}