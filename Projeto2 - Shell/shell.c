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
            linha = leitura();

            if(!linha){
                exit(EXIT_SUCCESS);
            }

            if(linha[0] = '\0' || strcmp(linha, '\n')==0){
                free(linha);
                continue;
            }
            if(strcmp(linha, 'exit\n')){
                free(linha);
                break;
            }

        printf("%s\n", linha);
        
            
        }while(1);

        exit(EXIT_SUCCESS);
        
        linha = leitura();
        argumentos = args(linha);

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
            free(buf);
            exit(0);
        }
        else{
            free(buf);
            fprintf(stderr, "Error while reading\n");
            exit(11);
        }

    }

    return (buf);
}


char *args(char *line){

    int bytes = 64;
    char **tokenize;
    char *token;

     //uso do malloc para alocar espaco
    tokenize = malloc(bytes *sizeof(*char ));

    //validacao
}