#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random(int a,int b){
	return a+rand()%(b-a+1);
}

main(){
	srand(time(NULL));
	double realmoney;
	FILE *fout;
	fout=fopen("game.txt","w");
//	fscanf(fout,"%lf",&realmoney);
//	fputs("10.00",fout);
	fscanf(fout,"%lf",&realmoney);
	printf("%lf",realmoney);
	fclose(fout);
}
