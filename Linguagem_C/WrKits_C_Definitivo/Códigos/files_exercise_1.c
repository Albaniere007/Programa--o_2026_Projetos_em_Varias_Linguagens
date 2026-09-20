#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da constante de deslocamento (Cifra de César n=3)
#define OFFSET 3

/**
 * @brief Criptografa ou descriptografa um arquivo de texto.
 * * @param arquivo_entrada Nome do arquivo para ler (original ou criptografado).
 * @param arquivo_saida Nome do arquivo para escrever o resultado.
 * @param deslocamento O valor de deslocamento (+OFFSET para criptografar, -OFFSET para descriptografar).
 * @return int Retorna 0 em caso de sucesso, 1 em caso de erro.
 */
int processar_arquivo(const char *arquivo_entrada, const char *arquivo_saida, int deslocamento) {
    FILE *f_entrada = NULL;
    FILE *f_saida = NULL;
    int caractere;

    // 1. Abrir arquivo de entrada (para leitura)
    f_entrada = fopen(arquivo_entrada, "r");
    if (f_entrada == NULL) {
        perror("ERRO: Nao foi possivel abrir o arquivo de entrada");
        return 1;
    }

    // 2. Abrir arquivo de saída (para escrita)
    f_saida = fopen(arquivo_saida, "w");
    if (f_saida == NULL) {
        perror("ERRO: Nao foi possivel criar o arquivo de saida");
        fclose(f_entrada);
        return 1;
    }

    // 3. Processamento caractere por caractere
    while ((caractere = fgetc(f_entrada)) != EOF) {
        // Aplica o deslocamento no valor ASCII do caractere
        int novo_caractere = caractere + deslocamento;
        
        // Escreve o novo caractere no arquivo de saída
        fputc(novo_caractere, f_saida);
    }

    // 4. Fechar arquivos
    fclose(f_entrada);
    fclose(f_saida);
    return 0;
}

// --------------------------------------------------------------------------------------------------
int main() {
    char arquivo_entrada[100];
    char arquivo_saida[100];
    int escolha;
    int deslocamento = 0;

    printf("--- Codificador de Arquivos Cifra de Cesar (n=3) ---\n");
    printf("1 - Criptografar (+%d posicoes)\n", OFFSET);
    printf("2 - Descriptografar (-%d posicoes)\n", OFFSET);
    printf("Escolha uma opcao: ");

    // 1. Corrigir a leitura da escolha (o & e' obrigatorio no scanf para variaveis int)
    if (scanf("%d", &escolha) != 1) {
        printf("ERRO: Entrada invalida. Por favor, insira 1 ou 2.\n");
        return 1;
    }
    
    // Limpar o buffer do teclado apos o scanf para evitar problemas com gets/fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    // 2. Definir o deslocamento com base na escolha
    if (escolha == 1) {
        deslocamento = OFFSET; // +3 para criptografar
        strcpy(arquivo_saida, "CRIPTOGRAFADO.txt");
    } else if (escolha == 2) {
        deslocamento = -OFFSET; // -3 para descriptografar
        strcpy(arquivo_saida, "ORIGINAL_RESTAURADO.txt");
    } else {
        printf("ERRO: Opcao invalida.\n");
        return 1;
    }

    printf("\nQual o nome do arquivo de entrada (Ex: mensagem.txt)? ");
    // 3. Usar fgets para uma leitura de string mais segura
    if (fgets(arquivo_entrada, sizeof(arquivo_entrada), stdin) == NULL) {
        printf("ERRO na leitura do nome do arquivo.\n");
        return 1;
    }
    // Remover o newline (\n) que o fgets adiciona
    arquivo_entrada[strcspn(arquivo_entrada, "\n")] = 0;


    // 4. Executar o processamento
    printf("\nProcessando arquivo...\n");
    if (processar_arquivo(arquivo_entrada, arquivo_saida, deslocamento) == 0) {
        printf("-----------------------------------------------------------\n");
        printf("SUCESSO! O arquivo '%s' foi gerado com a mensagem %s.\n", 
               arquivo_saida, 
               (escolha == 1 ? "criptografada" : "original"));
        printf("-----------------------------------------------------------\n");
    } else {
        printf("FALHA: O processamento nao pode ser concluido.\n");
        return 1;
    }

    return 0;
}