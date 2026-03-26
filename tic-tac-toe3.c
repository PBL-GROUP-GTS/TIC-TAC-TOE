#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char arr[10];

void resetBoard();
void showboard();
int checkforwin();
int computerMove();

int main()
{
    int mode, playAgain = 1;
    int playerWins = 0, computerWins = 0;
    int p1Wins = 0, p2Wins = 0;

    printf("Select Mode:\n1. Player vs Player\n2. Player vs Computer\n");
    scanf("%d", &mode);

    while(playAgain)
    {
        resetBoard();
        int player = 1, choice, i;
        char mark;

        do
        {
            showboard();
            player = (player % 2) ? 1 : 2;

            if (mode == 2 && player == 2)
            {
                choice = computerMove();
                printf("Computer chose: %d\n", choice);
            }
            else
            {
                printf("Player %d, enter a number: ", player);
                scanf("%d", &choice);
            }

            mark = (player == 1) ? 'X' : 'O';

            if (choice >=1 && choice <=9 && arr[choice] == choice + '0')
                arr[choice] = mark;
            else {
                printf("Invalid move\n");
                player--;
            }

            i = checkforwin();
            player++;

        } while (i == -1);

        showboard();

        // RESULT + SCORE UPDATE
        if (i == 1)
        {
            int winner = player - 1;

            if (mode == 2)
            {
                if (winner == 1)
                {
                    printf("Player wins!\n");
                    playerWins++;
                }
                else
                {
                    printf("Computer wins!\n");
                    computerWins++;
                }
            }
            else
            {
                if (winner == 1)
                {
                    printf("Player 1 wins!\n");
                    p1Wins++;
                }
                else
                {
                    printf("Player 2 wins!\n");
                    p2Wins++;
                }
            }
        }
        else
        {
            printf("Game draw\n");
        }

        // SHOW SCORE
        printf("\n--- SCORE ---\n");
        if (mode == 2)
        {
            printf("Player Wins: %d\n", playerWins);
            printf("Computer Wins: %d\n", computerWins);
        }
        else
        {
            printf("Player 1 Wins: %d\n", p1Wins);
            printf("Player 2 Wins: %d\n", p2Wins);
        }

        // PLAY AGAIN OPTION
        printf("\n1. Play Again\n2. Exit\nEnter choice: ");
        scanf("%d", &playAgain);

        if (playAgain == 1)
            playAgain = 1;
        else
            playAgain = 0;
    }

    printf("Thanks for playing!\n");
    return 0;
}

void resetBoard()
{
    for(int i = 1; i <= 9; i++)
        arr[i] = i + '0';
}

void showboard()
{
    printf("\n   TIC TAC TOE\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[1], arr[2], arr[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[4], arr[5], arr[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[7], arr[8], arr[9]);
    printf("   |   |   \n");
}

int computerMove()
{
    int move;
    do {
        move = rand() % 9 + 1;
    } while (arr[move] == 'X' || arr[move] == 'O');
    return move;
}

int checkforwin()
{
    if (arr[1]==arr[2] && arr[2]==arr[3]) return 1;
    if (arr[4]==arr[5] && arr[5]==arr[6]) return 1;
    if (arr[7]==arr[8] && arr[8]==arr[9]) return 1;

    if (arr[1]==arr[4] && arr[4]==arr[7]) return 1;
    if (arr[2]==arr[5] && arr[5]==arr[8]) return 1;
    if (arr[3]==arr[6] && arr[6]==arr[9]) return 1;

    if (arr[1]==arr[5] && arr[5]==arr[9]) return 1;
    if (arr[3]==arr[5] && arr[5]==arr[7]) return 1;

    if (arr[1]!='1' && arr[2]!='2' && arr[3]!='3' &&
        arr[4]!='4' && arr[5]!='5' && arr[6]!='6' &&
        arr[7]!='7' && arr[8]!='8' && arr[9]!='9')
        return 0;

    return -1;
}