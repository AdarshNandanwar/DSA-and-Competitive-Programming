#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_die();
void display_board(int, int);
void play_game(int);


int main()
{
	int size;
	printf("Select board size: ");
	scanf("%d",&size);
	play_game(size);
	return 0;
}

void play_game(int size)
{
	int pos=0, prev_pos, die_value;
	int a;
	while(1)
	{
		display_board(size, pos);
		printf("Press enter to roll the die...");
		scanf("%d",&a);
		prev_pos=pos;
		die_value=roll_die();
		printf("%d",die_value);
		pos+=die_value;
		if(pos<(size*size)-1)
		{
			continue;
		}
		else if (pos==(size*size)-1)
		{
			display_board(size, pos);
			printf("You win!\n");
			break;
		}
		else
			pos=prev_pos;
	}
}

void display_board(int size, int pos)
{
	printf("\n");
	for (int j = 0; j < size; ++j)
	{
		printf("-----");
	}
	printf("\n");
	for(int i = size-1; i >= 0; i--)
	{
		for (int j = 0; j < size; ++j)
		{
			if(((size*i)+j)==pos)
				printf("| * |");
			else
				printf("|   |");
		}
		printf("\n");
		for (int j = 0; j < size; ++j)
		{
			printf("-----");
		}
		printf("\n");

	}		
}

int roll_die()
{
	srand(time(0));
	return (rand()%(6-1+1))+1;				//random no bw 1 to 6
}