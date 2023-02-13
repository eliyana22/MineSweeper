#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#define COL 80
#define ROW 25
#define MAX 10

void score( int c, int a,int l, int t);
void gotoxy(int x, int y);
void Pboard(char Board[ROW][COL]);

int main()
{
    char bomb[ROW][COL], display[ROW][COL],code[25];
    char blank='X', Blan='O', unk='=';
    int randrow,randcol,row,col,cor=0,att=3,i,j,life=3,mode=0,tr=0;


        system("cls");
        gotoxy(13,35); printf("---------YOU KNOW SOME CODE? ----------");
        gotoxy(14,38); printf("          TYPE  HERE: ");
        gets(code);
        gotoxy(15,35); printf("---------- TO SUBMIT CLICK ENTER!! ----------");

        getch();
        system("cls");
        if(strcmp(code,"yghjyghj")==0)
        {
            gotoxy(14,35); printf("---------- CODE ACTIVATED ----------");
            life=3; att = 3; mode=1;
        }
        else if (strcmp(code,"wasdwasd")==0)
        {
            gotoxy(14,35); printf("---------- CHEAT CODE ACTIVATED ----------");
            gotoxy(16,35); printf("---------- PRESS ANY KEY TO START ----------");
            getch();
            life=9999; att=9999;
        }
        else
        {
            gotoxy(13,35); printf("---------- PRESS ANY KEY TO START ----------");
            getch();
        }

                    srand(time(NULL));
                    for(i=0;i<ROW;i++)
                    {
                    for (j=0;j<COL;j++)
                    {
                        bomb[i][j]=blank;
                        display[i][j]=unk;
                    }
                    }

        while (att > 0)
        {
             if(cor!=MAX)
             {
                randrow=rand()%ROW;
                randcol=rand()%COL;
                bomb[randrow][randcol]=Blan;
                 system("cls");
                 gotoxy(2,10); printf("THE GAMER IS IN GAME!! GOODLUCK ^_^");
                 gotoxy(4,1); printf("DIRECTIONS:");
                 gotoxy(5,1); printf("1. FIND THE BOMB THAT LOCATED IN THE BOX");
                 gotoxy(6,1); printf("2. INPUT YOUR ANSWER,\"PRESS ENTER TO SUBMIT\"");
                 gotoxy(7,1); printf("3. THE NUMBER OF ROWS and COLUMNS,\"START IN ZERO NUMBER\"");
                 gotoxy(8,1); printf("4. \"O\" YOUR ANSWER IS CORRECT, \"X\" YOUR ANSWER IS WRONG");
                 score(cor,att,life,tr);
                 Pboard(display);
                 if (mode == 1)
                 {
                     gotoxy(10,83); printf("ANSWER: ROWS: %d ", randrow+=1); gotoxy(11,83); printf("ANSWER: COLUMNS: %d ",randcol+=1);
                 }
                 gotoxy(10,5); printf("ENTER ROWS: ");
                 scanf("%d",&row);
                 gotoxy(11,5); printf("ENTER COLS: ");
                 scanf("%d",&col);
                  col-=1;  row-=1;

                 if (bomb[row][col] == Blan)
                 {
                     display[row][col]=Blan;
                     Pboard(display);
                     cor++;
                      score(cor,att,life,tr);
                 }
                 else
                 {
                     display[row][col]=blank;
                     Pboard(display);
                     att--;
                      score(cor,att,life,tr);
                 }
                 tr++;
                 getch();
             } // END OF IF STATEMENT INSIDE OF WHILE LOOP
             else
             {
                gotoxy(10,30); printf("-----YOU WIN THE GAME!! CONGRATULATIONS!!-----\n\n\n");
                break;
             }
        }// END OF WHILE LOOP
              if (att == 0)
                {
                    gotoxy(10,30); printf("-----YOU LOSE THE GAME!!SORRY,TRY AGAIN!!-----\n\n\n");
                }

    return 0;

} // END OF MAIN PROGRAM
void Pboard(char Board[ROW][COL])
{
    int i, j;

    for(i=0;i<ROW;i++){
        gotoxy(i+14,0);
        for(j=0;j<COL;j++){
            printf("%c ", Board[i][j]);
        }
        printf("\n");
    }
}
void score( int c,int a,int l, int t)
{
     gotoxy(4,80);printf("SCORE: %d/%d\n",c,MAX);
     gotoxy(5,80); printf("ATTEMPT: %d/%d\n",a,l);
     gotoxy(6,80);printf("TRIES: %d\n",t);
}
void gotoxy(int x, int y)
{
     printf("\e[%d;%df",x,y);
}

