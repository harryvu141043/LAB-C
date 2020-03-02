/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ADMIN
 *
 * Created on March 1, 2020, 4:19 PM
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
void Split(char s[],char s1[],char w[][1001],int &size){
    char ss[strlen(s)];
    strcpy(ss,s);
    int k=0;
    char* pc=strstr(ss,s1);
    while(pc!=NULL){
        strcpy(w[k],ss);
        w[k][pc-&ss[0]]=0;
//        printf("%s\n",w[k]);
        k++;
        strcpy(&ss[0],pc+strlen(s1));
        pc=strstr(ss,s1);
        
    }
    strcpy(w[k++],ss);
    size=k;
}
char EoE(){
    char ch;
    do{
        fpurge(stdin);
        ch=getchar();
        
        if(ch==10||ch==27){
            return ch;
        }
        else
            puts("no accept");
    }while(1);
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    char *s=(char*)malloc(1001);
    char c;
    do{
        printf("Please enter string:");
        scanf("%s",s);
        printf("The old string:%s\n",s);
        int size=1;
        char w[size][1001];
        Split(s,"_",w,size);
        strcpy(s,w[size-1]);
        for(int i=size-2;i>=0;i--){

            strcat(s,"_");
            strcat(s,w[i]);
        }
        printf("The new string:%s\n",s);
        puts("Press enter to continue another reverse, ESC to exit");
        c=EoE();
    }while(c!=27);
    
    free(s);

    return 0;
}

