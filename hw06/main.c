#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char game_board[16][31];
int const row=15,column=30;
int i1=1,je1=1,i2=3,je2=3; // 1 VE 2 SAYILARININ KONUMLARI

void fill_array()
{
    // 2 BOYUTLU ARRAYIN ICININ DOLDURULMASI
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if(i==0 || j==0 || i==14 || j==29)game_board[i][j]='.';
            else if(i==2 && j>=2 && j<=27)game_board[i][j]='.';
            else if(i==12 && j>=2 && j<=27)game_board[i][j]='.';
            else if(j==2 && i>=2 && i<=12)game_board[i][j]='.';
            else if(j==27 && i>=2 && i<=12)game_board[i][j]='.';
            else if(i==4 && j>=4 && j<=25)game_board[i][j]='.';
            else if(i==10 && j>=4 && j<=25)game_board[i][j]='.';
            else if(j==4 && i>=4 && i<=10)game_board[i][j]='.';     
            else if(j==25&& i>=4 && i<=10)game_board[i][j]='.'; 
            else if(i==i1 && j==je1)game_board[i][j]='1';
            else if(i==i2 && j==je2)game_board[i][j]='2';
            else if(i==2 && j==1)game_board[i][j]='_';
            else if(i==4 && j==3)game_board[i][j]='_';
            else if(i==1 && j==14)game_board[i][j]='X';
            else if(i==7 && j==28)game_board[i][j]='X';
            else if(i==13&& j==14)game_board[i][j]='X';
            else if(i==3 && j==10)game_board[i][j]='X';
            else if(i==3 && j==18)game_board[i][j]='X';
            else if(i==5 && j==26)game_board[i][j]='X';
            else if(i==10 && j==26)game_board[i][j]='X';
            else if(i==11 && j==10)game_board[i][j]='X';
            else if(i==11 && j==18)game_board[i][j]='X';
            else game_board[i][j]=' ';
        }       
    } 
}


void printmap()
{ 
    // ARRAYIN RENKLI BIR BICIMDE BASTIRILMASI
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char c = game_board[i][j];
            if(c=='X')printf("\033[1;31m%c",c);
            else if(c=='1')printf("\033[1;33m%c",c);
            else if(c=='2')printf("\033[0;34m%c",c);
            else if(c=='.')printf("\033[1;37m%c",c);
            else if(c=='_')printf("\033[1;32m%c",c);
            else printf("%c",game_board[i][j]);
        }
        printf("\n");        
    }
    
}

int dice()
{
    // ZAR ATIMI
    srand(time(NULL));
    return rand()%6 +1; 
}

int startgame(int p1,int p2)
{
    // KAZANAN OYUNCUNUN BELIRLENMESI
    if(p1>p2)return 1;
    else if(p2>p1)return 2;
    else if(p2==p1)return 0;
}

int update(void f(),int p1, int p2)
{
    // 1 SAYISININ KONUMUNUN GUNCELLENMESI
    int flag1;
    if(je1+p1<=28 && i1==1){
        // 1 SAYISININ SAGA GITMESINI SAGLAMA
        if(je1+p1==14){je1=12;printf("\033[1;31mPentaly for player 1\n");}
        else flag1=0;
    }
    if(je1+p1>28 && i1>=1 && i1!=13 ){
        // 1 SAYISININ ASAGI GITMESINI SAGLAMA
        if(i1+p1==7){i1=5;printf("\033[1;31mPentaly for player 1\n");}
        else flag1=1;
    }
    if(i1+p1>13){
        // 1 SAYISININ SOLA GITMESINI SAGLAMA
        if(je1-p1==14){je1=16;printf("\033[1;31mPentaly for player 1\n");}
        else flag1=2;
    }
    if(je1-p1<1 && i1<=13 && i1>=2){
        // 1 SAYISININ YUKARI GITMESINI SAGLAMA
        flag1=3;
    }

    if(flag1==0){
        je1+=p1;
    }
    if (flag1==1){
        p1=p1+je1-28;
        je1=28;
        i1+=p1;
    }
    if(flag1==2){
        p1=p1+i1-13;
        i1=13;
        je1-=p1;
    }
    if(flag1==3){
        p1=p1-je1+1;
        je1=1;
        i1-=p1;
        if(i1<=2){i1=2;printf("\n\n\033[1;32mPlayer 1 winner\n");return -1;}      
    }

    // 1 SAYISININ KONUMUNUN GUNCELLENMESI

    int flag2;
    if(je2+p2<=26 && i2==3){
        // 2 SAYISININ SAGA GITMESINI SAGLAMA
        if(je2+p2==10){je2=8;printf("\033[1;31mPentaly for player 2\n");}
        else if(je2+p2==18){je2=16;printf("\033[1;31mPentaly for player 2\n");}
        else flag2=0;
    }
    if(je2+p2>26 && i2>=3 && i2!=11 ){  
        // 2 SAYISININ ASAGI GITMESINI SAGLAMA
        if(i2+p2+je2-26==5){i2=3;printf("\033[1;31mPentaly for player 2\n");}
        else if(i2+p2+je2-26==10){i2=8;printf("\033[1;31mPentaly for player 2\n");}
        else flag2=1;     
    }
    if(i2+p2>11){
        // 2 SAYISININ SOLA GITMESINI SAGLAMA
        if(je2-p2==10){je2=12;printf("\033[1;31mPentaly for player 2\n");}
        else if(je2-p2==18){je2=20;printf("\033[1;31mPentaly for player 2\n");}
        else flag2=2;
    }
    if(je2-p2<3 && i2<=11 && i2>=4){
        // 2 SAYISININ YUKARI GITMESINI SAGLAMA
        flag2=3;
    }

    if(flag2==0){
        je2+=p2;
    }
    if(flag2==1){        
        p2=p2+je2-26;
        je2=26;
        i2+=p2;                    
    }
    if(flag2==2){
        p2=p2+i2-11;
        i2=11;
        je2-=p2;        
    }
    if(flag2==3){
        p2=p2-je2+3;
        je2=3;
        i2-=p2;
        if(i2<=4){i2=4;printf("\n\n\033[1;32mPlayer 2 winner\n");return -1;}
    }
    f();

}

int main()
{
    int player1=0,player2=0,k;
    k = update(fill_array,player1,player2);
    printmap();
    printf("To start to game, players should dice and decide who is going to start first according to it...\n");
    int winner,s1,s2;
    //OYUNA KIMIN BASLAYACAGINI BELIRLEME
    while(1)
    {
        printf("PLAYER 1... press ENTER to dice");
        getchar();
        player1 = dice();
        printf("DICE : %d\n",player1);
        printf("PLAYER 2... press ENTER to dice");
        getchar();
        player2 = dice();
        printf("DICE : %d\n",player2);
        winner = startgame(player1,player2);
        if(winner==1){
            printf("***PLAYER 1 will start the game***\n");
            break;
        }
        if(winner==2){
            printf("***PLAYER 2 will start the game***\n");
            break;
        }
        if(winner==0)printf("Same dice value... Please try again.\n");
    }

    // OYUNCULARDAN BIRININ YESIL CIZGIYI GECILENE KADAR ZAR ATMA ISLEMININ DEVAM ETMESI
    while (k!=-1)
    {
        if(winner==1){
            printf("PLAYER 1... press ENTER to dice");
            getchar();
            player1 = dice();
            printf("DICE : %d\n",player1);
            printf("PLAYER 2... press ENTER to dice");
            getchar();
            player2 = dice();
            printf("DICE : %d\n",player2);
            k = update(fill_array,player1,player2);
            printmap();
        }
        else if(winner==2)
        {
            printf("PLAYER 2... press ENTER to dice");
            getchar();
            player2 = dice();
            printf("DICE : %d\n",player2);
            printf("PLAYER 1... press ENTER to dice");
            getchar();
            player1 = dice();
            printf("DICE : %d\n",player1);
            k = update(fill_array,player1,player2); 
            printmap();                                
        }
     
    }

    return 0;
}