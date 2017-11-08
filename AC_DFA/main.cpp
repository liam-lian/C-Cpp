#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "AC_DFA.h"
#include <iostream>
#include <string.h>
#include "Destorytree.h"
using namespace std;

###
int main(int argc,char *argv[])
{
    FILE * fp,*fp1;
    fpOut=fopen(argv[3],"a");

    fp=fopen(argv[1],"r");
    fp1=fopen(argv[2],"r");
    char strLine[500];

    if(fp==NULL){
         printf("File not Find\n");
         return -1;
     }
 
    init();

    int i=0;

    int countt;

    while (!feof(fp)){ 
         fgets(strLine,500,fp);
         createTree((unsigned char *)strLine);
         i++;
    }
   printf("%d\n",i);

    fclose(fp);
    calfail();
     

    printf("calfail\n");
    int p=0;
    char string[1024*1024+1];
      while(!feof(fp1)){
        int count=fread(string,1,1024*1024+1,fp1);
        search((unsigned char*)string,count);
       // printf("%d-\n",p++);
     }   
   printf("%d\n",line); 
   fclose(fp1);
   fclose(fpOut);

   for(i=0;i<16;i++){
     Destorytree(rootNode.child[i]);
   }

}
