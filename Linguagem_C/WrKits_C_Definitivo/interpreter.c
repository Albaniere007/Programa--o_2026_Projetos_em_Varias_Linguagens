#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/*
    1. Definir um tamanho para o array command (ex: 100 caracteres)
    scanf("%s", command); // scanf pode ser perigoso para buffer overflows
    Melhor usar fgets para ler strings de forma mais segura
    Lidar com erro de leitura ou EOF
    Remover o '\n' que fgets pode adicionar no final

    2. Usar strcmp para comparar strings. 
      strcmp retorna 0 se as strings forem iguais.
      Queremos continuar enquanto command NÃO FOR "EXIT", então usamos != 0


*/ 



void help();
void clear();

int main(){
    char command[100];
    char sentence[500] = "_ _ _ _";
    int repetitions = 0;
    
    do{ 
        int command_processed = 0;

        printf("Input command:");
        if(fgets(command, sizeof(command), stdin)==NULL){
            break;
        }

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command,"HELP")==0){
            help();
            command_processed = 1;
        } else if (strcmp(command,"CLEAR")==0){
            clear();
            command_processed = 1;
        } else if (strcmp(command,"CLEAR ALL")==0){
            command[0]= '\0';
            strcpy(sentence, "_ _ _ _");
            repetitions = 0;
            clear();
            command_processed = 1;
        } else if (strcmp(command,"TXT")==0){
            printf("Type the text you want!\n");
            if(fgets(sentence,sizeof(sentence),stdin)== NULL){
                printf("Type a valide message");
            }else{
                sentence[strcspn(sentence, "\n")]=0;
            }
            command_processed = 1;
        } else if (strcmp(command,"REP")==0){
            printf("Please enter the number of repetitions.");
            scanf("%d",&repetitions);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            command_processed = 1;
        } else if (strcmp(command,"RUN")==0){
            int i=0;
            while (i< repetitions)
            {   
                printf("'%s'\n",sentence);
                i++;
            }
            command_processed = 1;
        } else if (strcmp(command,"RUN SOUND")==0){
            int i=0;
            while (i< repetitions)
            {   
                printf("'%s', \a\n",sentence);
                i++;
            }
            command_processed = 1;
        }
        
        if (!command_processed && strcmp(command, "EXIT") != 0){
            printf("Type a valid command\n");
            printf("TIP: Use HELP for more options\n");
        }
    }while (strcmp(command,"EXIT") !=0);
    
    printf("Program closed. \n");

    return 0;
}

void help(){
    char *commands[] = {"RUN", "RUN SOUND", "REP", "TXT", "CLEAR", "CLEAR ALL", "EXIT"};
    char *descriptions[] = {
        "run the interpreter.",
        "run the program with 'bips'.",
        "repeats number, arg: 000 to 999",
        "update text, arg: any text you want",
        "clear screen without lost the data",
        "clear screen and erase data",
        "end interpreter"
    };
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    printf("\n--- Available Commands ---\n");
    for (int i = 0; i < num_commands; i++) {
        printf("%-15s %s\n", commands[i], descriptions[i]);
    }
    printf("--------------------------\n\n");
}

void clear(){
    system("clear");
}