#include<stdio.h>
#include<stdlib.h>

#define BUFFER (256)


int main(int argc, char *argv[]){

if(argc!=1){

 for(int j=1; j<argc; j++){
    FILE *fp = fopen(argv[j], "r");
    if(fp == NULL){

    printf("wcat: cannot open file\n");
    exit(1);
}

   
    char buf[BUFFER];
    while(fgets(buf,BUFFER, fp) !=NULL){
    printf("%s", buf);
   } 

fclose(fp);
 }
}

exit(0);
return 0;
}

