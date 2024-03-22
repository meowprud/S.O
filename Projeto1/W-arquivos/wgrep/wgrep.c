#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 512


int main(int argc, char *argv[]){

    if(argc ==1 || argc ==0){

    printf("wgrep: searchterm [file ...]\n");
    exit(1);

}

	else if (argc == 2)
	{
		char input[4096];
		while(fgets(input,4096, stdin) != NULL){
			if(strstr(input, argv[1]) != NULL)
			{
				printf("%s", input);
			}
		}
	}

    else if(argc >=3){

    for(int i = 2; i<argc; i++){

    FILE *fp = fopen(argv[i], "r");
    if(fp == NULL){
    printf("wgrep: cannot open file\n");
    exit(1);
}  

    char linha[BUFFER];
    while(fgets(linha, BUFFER, fp)!= NULL){
    if(strstr(linha, argv[1]) != NULL){
    
    printf("%s", linha);
    }
  }

    fclose(fp);
}

    exit(0);
}
return 0;

}
