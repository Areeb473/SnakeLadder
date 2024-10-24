#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>


//int dice;
int positionplayer1 = 0;
int positionplayer2 = 0;


int count, snakecount=0, laddercount=0; // for player 1

int count2, snake2count=0, ladder2count=0;   // player 2

int main()
{
	printf("*****************PROJECT NAME=LIL'S GAME'****************\n");
		printf("GROUP MEMBERS NAME:SYED AUN ALI\n\t\t  AREEB SHEIKH\n\t\t   ");
		printf("\n****************MOHAMMAD ALI JINNAH UNIVERSITY**************\n\n");
	
	
	int dice1;
	int dice2;
	
	printf("100 99 98 97 96 95 94 93 92 91 \n");
	printf(" 81 82 83 84 85 86 87 88 89 90 \n");
	printf(" 80 79 78 77 76 75 74 73 72 71 \n");
	printf(" 61 62 63 64 65 66 67 68 69 70 \n");
	printf(" 60 59 58 57 56 55 54 53 52 51 \n");
	printf(" 41 42 43 44 45 46 47 48 49 50 \n");
	printf(" 40 39 38 37 36 35 34 33 32 31 \n");
	printf(" 21 22 23 24 25 26 27 28 29 30 \n");
	printf(" 20 19 18 17 16 15 14 13 12 11 \n");
	printf(" 10  9  8  7  6  5  4  3  2  1 \n");
	
	printf("\n");
	
	printf("------------------------------------------------------------------------------\n");
	
	printf("\n");
	
	
	
	do
	{
	    srand(time(NULL));
	    
	    printf("Player 1 Current position %d\n", positionplayer1);
	    
		printf("press any key to roll dice");
		
		getch();
		
		dice1 = 1 +rand()%6;
		
		if(dice1+positionplayer1 > 100)
		{
			printf("\nplayer 1 Got %d, roll dice again!", dice1);
			continue;
		}
		
		positionplayer1 += dice1;
		
		positionplayer1 = snake(positionplayer1);
		
		positionplayer1 = ladder(positionplayer1);
		
	printf("\n player 1Got %d, you landed on new position %d\n",dice1, positionplayer1);	
	printf("------------------------------------------------------------------------------\n");
	count++;
	
	if(positionplayer1 == 100)
	{
		printf("Player 1 won");
		break;
	}
	
	// Player 2
	
	srand(time(NULL));
	    
	    printf("Player 2 Current position %d\n", positionplayer2);
	    
		printf("press any key to roll dice");
		
		getch();
		
		dice2 = 1 +rand()%6;
		
		if(dice2+positionplayer2 > 100)
		{
			printf("\nPlayer 2 Got %d, roll dice again!", dice2);
			continue;   
		}
		
		positionplayer2 += dice2;
		
		positionplayer2 = snake(positionplayer2);
		
		positionplayer2 = ladder(positionplayer2);
		
	printf("\n player 2 Got %d, you landed on new position %d\n",dice2, positionplayer2);
	printf("------------------------------------------------------------------------------\n");	
	count2++;
	
	if(positionplayer2 == 100)
	{
	   printf("Player 2 won");
	   break;
	}
		
	}
	while(positionplayer1 < 100 || positionplayer2 < 100);
    {
    	if(positionplayer1 >= 100)
    	{
	       printf("congrats, Player 1 won in %d dice throws, bitten by SNAKES %d times and got the LADDERS %d times \n",count, snakecount, laddercount);
    	}
    	else
    	{
    		printf("congrats, player 2 won in %d dice throws, bitten by SNAKES %d times and got the LADDERS %d times \n",count2, snake2count, ladder2count);
		}
    }

return 0;
}
	
	
int snake(int b)
{
	int j;
	
	int snake[]={24,36,45,64,78,81,99};
	
	int end[]={5,13,20,49,63,76,46};
	
	for(j=0; j<=7; j++)
	{
		if(b==snake[j])
		{
			b=end[j];
			
			printf("\nBit by snake, now on %d", b);
			
			snakecount++;
			
			break;
		
		}
		
	   j++;
	}
	
	return b;
}

int ladder(int a)
{
	int k;
	
	int ladder[]={4,25,46,60,88,39,84,35,50};
	
	int end[]={14,31,54,68,92,47,97,40,55};
	
	for(k=0; k<=9; k++)
	{
		if(a==ladder[k])
		{
			a=end[k];
			
			printf("\nGo up from ladder, your new position is %d\n", a);
			
			laddercount++;
			
			break;
		
		}
	   k++;
	}
	return a;
}
