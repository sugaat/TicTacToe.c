#include <stdio.h>
#include <stdlib.h>    //for system(cls)

char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void showBoard();
int checkForWin();
void markBoard(char mark);
int choice, player;
    
int main()
{
    player = 1;
	int gameStatus;
    char mark; // X or O
	do
    {
        showBoard();
        if (player % 2) {   //If player is even, we assign 1 to player
    		player = 1;		//Otherwise, we assign 2 to player
		} 
		else {
    		player = 2;
   		}
		printf("\nPlayer %d turn :", player);
        scanf("%d", &choice);
        
		if (player == 1)
			mark = 'X';
		else{
			mark = 'O';
		}
				
		markBoard(mark);
        showBoard();
        gameStatus = checkForWin();          //-1,0,1
        player++;
    } while (gameStatus == -1);

    showBoard();
    if (gameStatus == 1)
    {
        printf("Player %d Won\n", --player);
    }
    else
    {
        printf("Game Draw\n");
    }
    return 0;
}

// Function to print the Tic Tac Toe board
void showBoard()
{
    system("cls");
    printf("\tTIC TAC TOE");
    printf("\nPlayer1: X         Player2: O\n");
    printf("\n");
    printf("\n");
    printf("   %c   |   %c   |   %c   \n", arr[1], arr[2], arr[3]);
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[4], arr[5], arr[6]);
    printf("       |       |      \n");
    printf("-------|-------|-------\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c   \n", arr[7], arr[8], arr[9]);
    printf("       |       |      \n");
}

void markBoard(char mark)
{
	if (choice == 1 && arr[1] == '1')
            arr[1] = mark;
        else if (choice == 2 && arr[2] == '2')
            arr[2] = mark;
        else if (choice == 3 && arr[3] == '3')
            arr[3] = mark;
        else if (choice == 4 && arr[4] == '4')
            arr[4] = mark;
        else if (choice == 5 && arr[5] == '5')
            arr[5] = mark;
        else if (choice == 6 && arr[6] == '6')
            arr[6] = mark;
        else if (choice == 7 && arr[7] == '7')
            arr[7] = mark;
        else if (choice == 8 && arr[8] == '8')
            arr[8] = mark;
        else if (choice == 9 && arr[9] == '9')
            arr[9] = mark;
        else 
        {
            printf("Invalid value\n");
            player--;

        }
}

/* A function to check if player won 
 1 for game is over with result
-1 for game is in progress
0 game is over and no result
*/

int checkForWin()
{
    // Win Cases
    //  For Rows
    if (arr[1] == arr[2] && arr[2] == arr[3])
        return 1;

    else if (arr[4] == arr[5] && arr[5] == arr[6])
        return 1;
    else if (arr[7] == arr[8] && arr[8] == arr[9])
        return 1;
    // For Columns
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;
    else if (arr[3] == arr[6] && arr[6] == arr[9])
        return 1;
    // Diagonals
    else if (arr[1] == arr[5] && arr[5] == arr[9])
        return 1;
    else if (arr[3] == arr[5] && arr[5] == arr[7])
        return 1;
    // Draw case    
    else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' && arr[4] != '4' &&
		 arr[5] != '5' && arr[6] != '6' && arr[7] != '7' 
		 && arr[8] != '8' && arr[9] != '9')
        return 0;

    else
        return -1;
}
