#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random(int a,int b){
	return a+rand()%(b-a+1);
}

main(){
	srand(time(NULL));
	double money;
	int keep=1,choice,a,b,c;
	FILE *fout;
	fout=fopen("game.txt","r");
	fscanf(fout,"%lf",&money);
	fclose(fout);
	while(keep){
		if(money==0.00){
			puts("Good bye!");
			break;
		}
		if(choice!=2)printf("You have $%.2lf\n",money);
		puts("Choose one of the following menu options:");
		puts("1) Play the slot machine.");
		puts("2) Save game.");
		puts("3) Cash out.");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				money-=0.25;
				a=Random(0,9);
				b=Random(0,9);
				c=Random(0,9);
				printf("The slot machine shows %d%d%d.\n",a,b,c);
				if(a==b&&a==c){
					money+=10.00;
					puts("You win the big prize, $10.00!");
				}
				if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&b!=a)){
					money+=0.5;
					puts("You win 50 cents!");
				}
				else
					puts("Sorry you don't win anything.");
				break;
			case 2:
				fout=fopen("game.txt","w");
				fprintf(fout,"%.2lf",money);
				fclose(fout);
				puts("Your money had saved");
				break;
			case 3:
				keep=0;
				printf("Thank you for playing! you end with $%.2lf\n",money);
				break;
		}
	}


	
}
