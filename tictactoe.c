#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void placeMarker(char* board, char* marker, int position);
void printBoard(char* board);
void addPrintChar(char* board, char* output, char* marker);
bool checkWin(char* board, int turnCounter);


int main( int argc, char* argv[]){
	char* boardSpaces;
	char* x = "X";
	char* o = "O";

	boardSpaces = (char*)malloc(9);
	strncpy(boardSpaces, (char*)".........", 9);
	

	// if the amount of turns exceeds 9, there are no spots on the board and it will be a tie
	int turnCounter = 0;

	char pos[1];
	printf("%s\n", "Welcome to Tic-Tac-Toe! X's are first");
	// printf("%s\n", "The board positions are as follows\n");
	// printf("%s\n", "0 | 1 | 2\n3 | 4 | 5\n6 | 7 | 8\n");

	// Gameplay loop
	bool turn = true;
	bool finished = false;
	while(!finished){
		memset(&pos, '\0', 1);
		printf("%s\n", "\n0 | 1 | 2\n3 | 4 | 5\n6 | 7 | 8\n");
		if(turn){
			printf("%s\n", "Where are you placing an X? : ");
			scanf("%s", pos);
			if(atoi(pos) < 0 || atoi(pos) > 8 || boardSpaces[atoi(pos)] != '.'){
				printf("%s", "Invalid position number\n");
			}else{
				turn = false;
				placeMarker(boardSpaces, x, atoi(pos));
				turnCounter += 1;
			}
		}else{
			printf("%s\n", "Where are you placing an O? : ");
			scanf("%s", pos);
			if(atoi(pos) < 0 || atoi(pos) > 8 || boardSpaces[atoi(pos)] != '.'){
				printf("%s", "Invalid position number\n");
			}else{
				turn = true;
				placeMarker(boardSpaces, o, atoi(pos));
				turnCounter += 1;
			}
		}
		
		printBoard(boardSpaces);
		finished = checkWin(boardSpaces, turnCounter);

	}
	free(boardSpaces);
	return 0;
}

/*
	8 ways to win

	0	1	2
	3	4	5
	6	7	8

	012, 345, 678, 036, 147, 258, 048, 246

*/
bool checkWin(char* board, int turnCounter){
	char* ptr = board;

	if(turnCounter >= 9){
		printf("%s\n", "It's a tie ~~~ Boring");
		return true;
	}

	if(ptr[0] == 'X' && ptr[1] == 'X' && ptr[2] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[3] == 'X' && ptr[4] == 'X' && ptr[5] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[6] == 'X' && ptr[7] == 'X' && ptr[8] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[0] == 'X' && ptr[3] == 'X' && ptr[6] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[1] == 'X' && ptr[4] == 'X' && ptr[7] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[2] == 'X' && ptr[5] == 'X' && ptr[8] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[0] == 'X' && ptr[4] == 'X' && ptr[8] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}else if(ptr[2] == 'X' && ptr[4] == 'X' && ptr[6] == 'X'){
		printf("%s\n", "X's Win!");
		return true;
	}

	if(ptr[0] == 'O' && ptr[1] == 'O' && ptr[2] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[3] == 'O' && ptr[4] == 'O' && ptr[5] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[6] == 'O' && ptr[7] == 'O' && ptr[8] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[0] == 'O' && ptr[3] == 'O' && ptr[6] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[1] == 'O' && ptr[4] == 'O' && ptr[7] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[2] == 'O' && ptr[5] == 'O' && ptr[8] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[0] == 'O' && ptr[4] == 'O' && ptr[8] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}else if(ptr[2] == 'O' && ptr[4] == 'O' && ptr[6] == 'O'){
		printf("%s\n", "O's Win!");
		return true;
	}

	return false;

}

void placeMarker(char* board, char* marker, int position){
	if(position < 0 || position > 8){
		return;
	}
	char* ptr = board + position;
	strncpy(ptr, marker, 1);
}

void printBoard(char* board){
	char* ptr = board;

	// extra line for spacing
	printf("%s\n", "");
	// Add the board to be printed, set the memory to null bytes
	char print[12];
	memset(&print, '\0', 12);
	
	// For each of the 9 board positions
	for(int i=0;i<9;i++){

		
		
		// If it is the 3rd or 6th cell you want a new line for appearances
		if(i%3 == 0 && i != 0){
			strncat(print, (char*)"\n", 1);
			// printf("%s", "bam go down");
		}
		// printf("%d ?= %d or %d or %d\n", ptr[i], 'X', 'O', '.');

		// Chec for X, O, or nothing
		if(ptr[0] == 'X'){
			strncat(print, (char*)"X", 1);
			// ptr += 1;
		}else if(ptr[0] == 'O'){
			strncat(print, (char*)"O", 1);
			// ptr += 1;
		}else{
			strncat(print, (char*)".", 1);
			// ptr += 1;
		}
		ptr += 1;
		// printf("The length of the printer pointer is : %d\n", strlen(print));
	}
	printf("%s\n", print);
}