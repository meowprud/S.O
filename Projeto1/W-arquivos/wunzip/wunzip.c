#include <stdio.h>
#include <stdlib.h>

void descomprime(char *arquivo)
{
    char atual = 0;
    int contador = 0;
    FILE *fp = fopen(arquivo, "r");
    if(fp == NULL)
    {
        printf("wunzip: cannot open file.\n");
        exit(1);
    }
    while(!feof(fp))
    {
        int verifica = fread(&contador, 1, 4, fp);
        if(verifica != 4)
        {
            break;
        }
        fread(&atual, 1, 1, fp);
        {
            int i = 0;
            for(i = 0; i < contador; i++)
            {
                fwrite(&atual, 1, 1, stdout);
            }
        }
    }
    fclose(fp);
}

int main(int argc, char **argv)
{
    int i = 0;
    if(argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    for(i = 1; i < argc; i++)
    {
        descomprime(argv[i]);
    }
    return 0;
}



