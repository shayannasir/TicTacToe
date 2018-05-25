#include<stdio.h>
#include<conio.h>

char square[] = {'0','1','2','3','4','5','6','7','8','9'};

void board();
int check();

int main()
{

  int player=1;
  int choice;
  char mark;
  int i;
  char player1[10], player2[10];
  printf("\n\n\t\tWELCOME TO GAME OF TIC TAC TOE\n");
  printf("\n\t\tPlayer 1 state your name: ");
  gets(player1);
  printf("\n\t\tPlayer 2 state your name: ");
  gets(player2);
  printf("\n\t\tPress Any Key when both the players are ready !");
  getch();

  do{
   board();
   player = (player%2)? 1:2;

  /*assigns 1 to player for all odd values of player
    and 2 to player for all even values of player. */
    if(player==1)
    {
      printf("\n\n\t%s Enter a number: ",player1);
      scanf("%d",&choice);
    }

    if(player==2)
    {
      printf("\n\n\t%s Enter a number: ",player2);
      scanf("%d",&choice);
    }
    mark = (player==1)? 'X':'O';
  /*assigns X to mark for player 1
   and O to mark for player 2. */

    if(choice==1 && square[1]=='1')
      square[1] = mark;
    else if(choice==2 && square[2]=='2')
      square[2] = mark;
    else if(choice==3 && square[3]=='3')
      square[3] = mark;
    else if(choice==4 && square[4]=='4')
      square[4] = mark;
    else if(choice==5 && square[5]=='5')
      square[5] = mark;
    else if(choice==6 && square[6]=='6')
      square[6] = mark;
    else if(choice==7 && square[7]=='7')
      square[7] = mark;
    else if(choice==8 && square[8]=='8')
      square[8] = mark;
    else if(choice==9 && square[9]=='9')
      square[9] = mark;

    else{
        printf("\tInvalid move");
        player--;
        getch();
      }

  player++;
  i = check();

  }while(i==-1);

  board();
  if(i==1)
  {
    if(player==2)
      printf("\n\a\t===== Wohooo! %s WINS======",player1);
    else
      printf("\n\a\t===== Wohooo! %s WINS======",player2);
  }
  else
    printf("\n\t===== Sucks!!! Its a DRAW !======");

  getch();

  return 0;
}

void board()
{
  system("cls");
  printf("\n\n\tWELCOME MY SON, WELCOME TO THE MACHINE!\n\n\n\n");
  printf("\t\tTIC-TAC-TOE\n\n\n");

  printf("\tPlayer 1 - (X)     Player 2 - (O)\n\n\n");

  printf("\t\t    |    |   \n");
  printf("\t\t  %c |  %c |  %c \n",square[1],square[2],square[3]);
  printf("\t\t____|____|____\n");
  printf("\t\t    |    |   \n");
  printf("\t\t  %c |  %c |  %c \n",square[4],square[5],square[6]);
  printf("\t\t____|____|____\n");
  printf("\t\t    |    |   \n");
  printf("\t\t  %c |  %c |  %c \n",square[7],square[8],square[9]);
  printf("\t\t    |    |   \n");

}


int check()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
/*The value of i determines the status of the game,
 for i = 1; game is over with a winner
 for i = 0; game is ovber with a DRAW
 for i = -1; game is in progress. */
