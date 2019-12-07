#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random(int a,int b){
	return a+rand()%(b-a+1);
}

main(){
srand(time(NULL));
	int choice,keep=1;
	int a,b,c;
	double realmoney;
	FILE *f;
	while(keep){
		f=fopen("game.txt","r");
		fscanf(f,"%lf",&realmoney);
		printf("you have $%.2lf.\n",realmoney);
		puts("Choose one of the following menu options:");
		puts("1) Play the slot machine.");
		puts("2) Save game.");
		puts("3) Cash out.");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				a=Random(0,9); 
				b=Random(0,9);
				c=Random(0,9);
				printf("The slot machine shows %d%d%d\n",a,b,c);
				if(a==b&&a==c){
					
				}
				
		}
		break;
	}
}



