#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int notallfilled(int *);
int whowon1(int *p);
int where;/*global where user wants to add*/
void BotMove(int *p){
	srand(time(NULL));
	int x; 
	while(1){ x=rand()%9; if(p[x]==' ') {p[x]='O'; break;}  }

}
void keepPlaying2(int *p)
{
	while(1){
		printf("\nEnter Your Move.. ");
		scanf("%d",&where);
		if(p[where-1]!=' ') {printf("Please select empty cell\n"); continue;}
		else{
			for(int i=0;i<9;i++) if(where==(i+1)) p[i]='X';/*adding user selected box*/
			break;
		}
	}
	if(notallfilled(p)!=2) BotMove(p);/*Adding bot random input*/
	
	for(int i=0;i<9;i++){ if((i)%3==0) printf("\n"); printf("[%c]",p[i]);}/*printing final result box*/
	
}
int keepPlaying1(int *p)
{
	while(1){/*This is for registering Player 1 moves*/
		printf("\nPlayer 1 Enter Move: ");
		scanf("%d",&where);
		if(p[where-1]!=' ') {printf("Please select empty cell"); continue;}/*When choosen cell is already filled*/
		else{
			for(int i=0;i<9;i++) if(where==(i+1)) p[i]='X';/*adding user selected box*/
			break;
		}
	}
	for(int i=0;i<9;i++){ if((i)%3==0) printf("\n"); printf("[%c]",p[i]);}/*printing result after player 1 enter*/

	if(whowon1(p)==1) return 1;
	while(1){/*This is for registering Player 2 moves*/
		printf("\nPlayer 2 Enter Move: ");
		scanf("%d",&where);
		if(p[where-1]!=' ') {printf("Please select empty cell"); continue;}
		else{
			for(int i=0;i<9;i++) if(where==(i+1)) p[i]='O';/*adding user selected box*/
			break;
		}
	}
	
	for(int i=0;i<9;i++){ if((i)%3==0) printf("\n"); printf("[%c]",p[i]);}/*printing result after player 2 enter*/
	
}
int notallfilled(int *p)/*If there are empty cells*/
{
	int i;
	for(i=0;i<9;i++) if(p[i]==' ') return 1;
	for(i=0;i<9;i++) if(p[i]!=' ') continue; else break;
	if(i==9) return 2;
	
}


/*whowon1 is for human vs computer(mode 2) only*/
int whowon2(int *p) /*If someone win the game should stop and display who won*/
{
/*All winning conditions as seperate..These will also print who won*/
{if(p[0]=='X'&&p[1]=='X'&&p[2]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[3]=='X'&&p[4]=='X'&&p[5]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[6]=='X'&&p[7]=='X'&&p[8]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[0]=='X'&&p[3]=='X'&&p[6]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[1]=='X'&&p[4]=='X'&&p[7]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[2]=='X'&&p[5]=='X'&&p[8]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[0]=='X'&&p[4]=='X'&&p[8]=='X') {printf("\nYou won!\n"); return 1;}}
{if(p[2]=='X'&&p[4]=='X'&&p[6]=='X') {printf("\nYou won!\n"); return 1;}}

{if(p[0]=='O'&&p[1]=='O'&&p[2]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[3]=='O'&&p[4]=='O'&&p[5]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[6]=='O'&&p[7]=='O'&&p[8]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[0]=='O'&&p[3]=='O'&&p[6]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[1]=='O'&&p[4]=='O'&&p[7]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[2]=='O'&&p[5]=='O'&&p[8]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[0]=='O'&&p[4]=='O'&&p[8]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}
{if(p[2]=='O'&&p[4]=='O'&&p[6]=='O') {printf("\nComputer Won! You lost :(\n"); return 1;}}



	return 0;	
}

/*whowon1 is for human vs human (mode 1) only*/
int whowon1(int *p) /*If someone win the game should stop and display who won*/
{
/*All winning conditions as seperate..These will also print who won*/
{if(p[0]=='X'&&p[1]=='X'&&p[2]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[3]=='X'&&p[4]=='X'&&p[5]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[6]=='X'&&p[7]=='X'&&p[8]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[0]=='X'&&p[3]=='X'&&p[6]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[1]=='X'&&p[4]=='X'&&p[7]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[2]=='X'&&p[5]=='X'&&p[8]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[0]=='X'&&p[4]=='X'&&p[8]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}
{if(p[2]=='X'&&p[4]=='X'&&p[6]=='X') {printf("\nPlayer 1 won!\n"); return 1;}}

{if(p[0]=='O'&&p[1]=='O'&&p[2]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[3]=='O'&&p[4]=='O'&&p[5]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[6]=='O'&&p[7]=='O'&&p[8]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[0]=='O'&&p[3]=='O'&&p[6]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[1]=='O'&&p[4]=='O'&&p[7]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[2]=='O'&&p[5]=='O'&&p[8]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[0]=='O'&&p[4]=='O'&&p[8]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}
{if(p[2]=='O'&&p[4]=='O'&&p[6]=='O') {printf("\nPlayer 2 won!\n"); return 1;}}



	return 0;	
}


int main()
{
	int XorO[9];/*orignal list containing filled boxes*/

	int *p; p=&XorO[0];/*pinter to boxes*/
	foo: for(int i=0;i<9;i++) p[i]=' ';/*initializing space for every box*/
	
	printf("1.Human VS Human\n2.Human VS Computer\n");
	int mode; scanf("%d",&mode);
	if(mode==2)/*This is previousy written code for Human vs computer mode*/
	while( notallfilled(p)){
		if(whowon2(p)==1) break;/*if someone win game will stop*/ 
		keepPlaying2(p);
		if(whowon2(p)==1) break;/*if someone win game will stop*/ 
		printf("\n\n*************************************************************");
		if(notallfilled(p)==2) {printf("\nIts a draw\nThanks for Playing with me :)\t-Dear Bot\n");break;}
	}
	char player1[]="Player 1 'X'";
	char player2[]="Player 2 'O'";
	if(mode==1)/*This is for human vs human mode*/
	{printf("Player 1 is 'X' and Player 2 is 'O'");
	while( notallfilled(p)){
		if(whowon1(p)==1) break;/*if someone win game will stop*/ 
		keepPlaying1(p);
		if(whowon1(p)==1) break;/*if someone win game will stop*/ 
		printf("\n\n*************************************************************");
		if(notallfilled(p)==2) {printf("\nIts a draw\nThanks for Playing\n");break;}
	}
	}
	printf("Play again?\n1.Yes\t2.No\n"); int z; scanf("%d",&z); 
	if(z==1) goto foo;


}
