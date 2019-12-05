#include<stdio.h>
#include<string.h>
void swapc(char *a,char *b){
	char t;
	t=*a;
	*a=*b;
	*b=t;
}
void charsort(char s[],int size,int type){
	int i=0,j;
	while(i<size-1){
	
		j=i+1;
		while(j<size){
			if(s[i]<s[j]==type){
				swapc(&s[i],&s[j]);
			}
            j++;
        }
        i++;
		}}
int substring(char shortstr[], char longstr[]){
	return strstr(longstr,shortstr)!=NULL?1:0;
}
int subsequence(char shortstr[], char longstr[]){
	int ios=0,count=0,i;
	if(strlen(shortstr)>strlen(longstr)){
		return 0;
	}
	for(i=0;i<strlen(longstr);i++){
		if(longstr[i]==shortstr[ios]){
			ios++;
			count++;
		}
	}
	if(count==strlen(shortstr)){
		return 1;
	}
	return 0;
		
}
int permutation(char string1[], char string2[]){
	char string1cp[29],string2cp[29];
	strcpy(string1cp,string1);
	strcpy(string2cp,string2);
	charsort(string1cp,strlen(string1),0);
	charsort(string2cp,strlen(string2),0);
	return !strcmp(string1cp,string2cp);
}
int matchscore(char string1[],char string2[]){
	int count=0,i;
	for(i=0;i<strlen(string1);i++){
		if(string1[i]!=string2[i]){
		
			count++;
		}
	}
	return count;
}



int main(){
	puts("Welcome to the Spell Checker!");
	puts("The dictionary has been loaded.");
	FILE *fin;
	char choice[3],w[29],dic[30000][29];
	strcpy(choice,"yes");
	while(!(strcmp(choice,"yes"))){
		fin=fopen("dictionary.txt","r");
		int id=0,found=1,found1=0;
		puts("Please enter the word you would like checked.");
		gets(w);
		while(!feof(fin)){
			fscanf(fin,"%s",dic[id]);
			if(!(strcmp(w,dic[id]))){
				printf("Great, %s is in the dictionary\n",w);
				found=0;
				break;
			}
			if(substring(dic[id],w)||subsequence(dic[id],w)||
				(strlen(dic[id])==strlen(w)&&
				(permutation(dic[id],w)
				||matchscore(dic[id],w)<3))){
					found1=1;
			}
		}
		if(found&&found1){
			fin=fopen("dictionary.txt","r");
			puts("Here are possible words you could have meant:");
			while(!feof(fin)){
				fscanf(fin,"%s",dic[id]);
				if(substring(dic[id],w)||subsequence(dic[id],w)||
				(strlen(dic[id])==strlen(w)&&
				(permutation(dic[id],w)
				||matchscore(dic[id],w)<3))){
					printf("%s\n",dic[id]);
				}
			}
		}
		fclose(fin);
		puts("Would you like to enter another word? (yes/no)");
		gets(choice);
		
		
	}




	

}
