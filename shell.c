#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


/*

        Implementacao de um shell simples
        Pontos chave:
        - Estrutura do shell
        - Build-in Commands
        - Comandos paralelos (juncao de comandos)
        - Erros do programa
        - Arquivos em branco/Espacos em branco
        - Direcionamento de diretorio
*/


int main(int argc, char **argv){
    
    size_t count;
    char *buf;
    char *linha;
    char **argumentos;

    //ssize_t line;
    


    //modo interativo
    if(isatty(STDIN_FILENO)){

        write(STDOUT_FILENO, "wish> ", 6);

        //validacao de linhas e argumentos atraves de delimitador
        //funcoes: getline() ; strtok(); strsep().

        do{
            line = leitura();

            if(!line){
                exit(EXIT_SUCCESS);
            }

            if(line[0] = '\0' || strcmp(line, '\n')==0){
                free(line);
                continue;
            }
            if(strcmp(line, 'exit\n')){
                free(line);
                break;
            }

        printf("%s\n", line);
        
            
        }while(1);

        exit(EXIT_SUCCESS)
        
        linha = leitura();
        argumentos = args(line);

        if(strstr(buf, "&")){

            


        }


    }

    //modo batch
    else{

    }

    return 0;
}

char *leitura(void){

    char *buf = NULL;
    size_t count = 0;

    //verificacao de falha do getline
    if(getline(&buf, &count, stdin)== -1){
        if(!feof(stdin)){
            free(line);
            exit(0);
        }
        else{
            free(line);
            fprintf(stderr, "Error while reading\n");
            exit(11);
        }

    }

    return (line);
}


char *args(char *line){

    int bytes = 64;
    char **tokenize;
    char *token;

     //uso do malloc para alocar espaco
    tokenize = malloc(bytes *sizeof(*char ));

    //validacao
}