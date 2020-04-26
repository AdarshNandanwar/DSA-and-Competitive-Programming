#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<ctype.h>

// obviously this program will take a while to run. please be patient with the output
int get_score(char arr[]) {
	int len = strlen(arr);
	int score = 0;
	for(int i=0; i<len; i++) {
		int asc = arr[i];
		score+=asc;
	}
	return score;
}

int main()
{
	char str[]="This ONLINE EXAM is based on Strings";
    srand(time(0));
    //DO NOT MODIFY THE ABOVE CODE
    	
	int len = strlen(str);
	/* int num=rand();
	printf("%d",num); */
    
   // int players[2]={0,0};  //player[0] corresponds to first player position and player[1] corresponds to computer position
	int scores[2];
	int wins[] = {0, 0};

	int N;
	printf("Enter the number of simulations: ");
	scanf("%d", &N);

	int turn = 0; // if turn = 0 or -1, player. else if turn = 1 or 2, comp
	char *point, *temp;
	char ch;

	int p;
	int n;
	int d;
	int max_games = (N/2)+1;
	// printf("Length = %d\n", len);
	do {
		scores[0] = 0;
		scores[1] = 0;
		do {
			point = str;
			int score_length;
			char score_string[len];

			p = rand()%len;
			// printf("Random: %d\n", p);
		
			ch = str[p];
			// printf("Character: %c\n", ch);
			if (ch==' ') {
				d=0;
			}
			else {
				point+=p;
				temp = strchrnul(point, ' ');
				score_length = temp-point;
				strncpy(score_string, point, score_length);
				score_string[score_length] = '\0';
				// printf("Score string: %s\n", score_string);
				n = get_score(score_string);
				// printf("n: %d\n", n);
				d = (n%6)+1;
				// printf("d: %d\n", d);
			
				if(isupper(ch))
					str[p] = tolower(ch);
				else
					str[p] = toupper(ch);
				// printf("String is now: %s\n", str);
			}
	
			if(turn==0 || turn==-1) {
				if(d==0) {
					turn = 2;
				}
				else if(d==6) {
					scores[0]+=d;
				}
				else {
					scores[0]+=d;
					turn++;
				}
			}
			else if(turn==1 || turn==2) {
				if(d==0) {
					turn = -1;
				}
				else if(d==6) {
					scores[1]+=d;
				}
				else {
					scores[1]+=d;
					turn--;
				}
			}
		} while((scores[0]<50) && (scores[1]<50));

		// printf("Scores[0]: %d\tScores[1]: %d\n", scores[0], scores[1]);

		if(scores[0]>scores[1])
			wins[0]+=1;
		else
			wins[1]+=1;
		if(N%2==0) {
			if((wins[0]==(N/2)) && (wins[1]==(N/2)))
				break;
		}
		
		
	} while((wins[0]<max_games) && (wins[1]<max_games));
    
   // printf("Rand: %d\n", p);
	// printf("%d", 'a');
	// printf("This %d\n", isupper('A'));
	if(wins[0]>wins[1])
		printf("Player is winner\n");
	else if(wins[1]>wins[0])
		printf("Computer is winner\n");
	else
		printf("Its a tie!\n");
	printf("Number of games simulated: %d\n", wins[0]+wins[1]);
	printf("Number of games won by computer: %d\n", wins[1]);
	printf("Number of games won by player: %d\n", wins[0]);
    
	return 0;
}
