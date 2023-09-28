#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
int height=30,width=30;
int x,y,fruitX,fruitY,flag,gameEnd,score,level;
int tailX[100],tailY[100],prevX,prevY,prev2X,prev2Y;
int CountTail=0; //whenever the snake will eat the food it will increase//
void load()
{
    int row,col,r,c,q;
    printf("\nloading");
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void logic ()
{
    prevX=tailX[0];
    prevY=tailY[0];
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<=CountTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    sleep(1);
    switch(flag)
    {
    case 1:
    {
        x--;
        break;
    }
    case 2:
    {
        x++;
        break;
    }
     case 3:
    {
        y--;
        break;
    }
     case 4 :
    {
        y++;
        break;
    }
}

if(x<0||x>height||y<0||y>width)
{
    gameEnd=1;
    for(int i=0;i<CountTail;i++)
    {
        if(x==tailX[i]&&y==tailY[i])
        gameEnd=1;
    }
}

if(x==fruitX&&y==fruitY)
{
   label3:
    fruitX=rand()%30;
    if(fruitX==0)
    goto label3;

    
    label4:
    fruitY=rand()%30;
    if(fruitY==0)
    goto label4;
    gameEnd=0;
    score+=10;
    level+=1;
 

    CountTail++;
}
}
void input()
{
    if(kbhit())
    switch(getch())
    {
    case 'w':
            {
            flag=1;
            break;
            }
     case 's': 
            {
            flag=2;
            break;
            }
     case  'a': 
            {
            flag=3;
            break;
            }
      case 'd': 
            {
            flag=4;
            break;
            }
    }
    
}
void Print()
{
    //GotoXY(10,12);
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use A S W D keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27)
        exit(0);
}

void setup()
{
    x=height/2;
    y=width/2;

    label1:
    fruitX=rand()%30;
    if(fruitX==0)
    goto label1;

    
    label2:
    fruitY=rand()%30;
    if(fruitY==0)
    goto label2;
    gameEnd=0;
    
    
}
void draw()
{   system("cls");
    int i,j;
    for (i=0;i<=height;i++)
    {
    for (j=0;j<=width;j++)
    if(i==0||i==height ||j==0||j==width)
    {
        printf("#");
    }
    else
    {
        if(i==x && j==y)
        {
        printf("0");
        }
     else if(i==fruitX && j==fruitY)
    
        {
        printf("@");
        }

        else
        {
            int ch=0;
            for(int k=0;k<CountTail;k++)
            {
                if(i==tailX[k]&& j==tailY[k])
                {
                printf("o");
                ch=1;
                }
            }
            if(ch==0)
            printf(" ");
        }
    }
    printf("\n");
    }
   printf("your score is %d",score); 

     if(score=10)
    {
    printf(" congratulation you reached level 1\n ",level);
    level+=1;
    }

}
int main ()
{   char c;
    label5:
    Print();
    load();
    setup();
    while(gameEnd!=1)
    {
    draw();
    input();
    logic();
   

}
printf("\n press Y to continue again"); 
scanf("%c",&c);
if(c=='y'||c=='Y')
goto label5;
return 0;
}
