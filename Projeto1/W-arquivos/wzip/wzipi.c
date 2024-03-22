#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
int contador = 0;
char c; 
char a;

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

else if(argc>=2){
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file.\n");
            exit(1);
        }

        if (i == 1) {
            c = fgetc(fp);
            contador= 1;
        }

        while ((a = fgetc(fp)) != EOF) {
            if (c == a) {
                contador++;
            } else {
                fwrite(&contador, sizeof(int), 1, stdout);
                fwrite(&c, sizeof(char), 1, stdout);
                c = a;
                contador = 1;
            }
        }
        fclose(fp);
    }

    fwrite(&contador, sizeof(int), 1, stdout);
    fwrite(&c, sizeof(char), 1, stdout);
}
    return 0;
}


