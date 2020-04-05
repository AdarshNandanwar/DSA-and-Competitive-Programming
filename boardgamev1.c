// changes made to original to try to make it work for non sqaure mxn boards
// not working as of now
// sometime gives 2 values when m<n
// sometime gives 0 values when m>n
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_die();
void display_board(int, int, int);
void play_game(int, int);


int main()
{
	int m,n;
	printf("Select board size (mxn): ");
	scanf("%d %d", &m, &n);
	play_game(m, n);
	return 0;
}

void play_game(int m, int n)
{
	int pos=0, prev_pos, die_value;
	int a;
	while(1)
	{
		display_board(m, n, pos);
		printf("Press enter to roll the die...");
		scanf("%d",&a);
		prev_pos=pos;
		die_value=roll_die();
		printf("%d",die_value);
		pos+=die_value;
		if(pos<(m*n)-1)
		{
			continue;
		}
		else if (pos==(m*n)-1)
		{
			display_board(m, n, pos);
			printf("You win!\n");
			break;
		}
		else
			pos=prev_pos;
	}
}

void display_board(int m, int n, int pos)
{
	printf("\n");
	for (int j = 0; j < n; ++j)
	{
		printf("-----");
	}
	printf("\n");
	for(int i = m-1; i >= 0; i--)
	{
		for (int j = 0; j < n; ++j)
		{
			if(((m*i)+j)==pos)			//not working because of this incorrect condition
				printf("| * |");		//true for 2 values
			else
				printf("|   |");
		}
		printf("\n");
		for (int j = 0; j < n; ++j)
		{
			printf("-----");
		}
		printf("\n");

	}
	printf("%d\n", pos);		
}

int roll_die()
{
	srand(time(0));
	return (rand()%(6-1+1))+1;
}