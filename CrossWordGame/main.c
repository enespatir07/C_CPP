#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int row=15,column=15;
char tableBoard[15][15];
enum directions {right = 1,down,diagonal};


int is_unique(int arr2[],int x, int index){
    // Is used when finding 7 unique element from the wordlist.txt
    for (int i = 0; i < 6; i++){
        if(i==index)continue;
        if(arr2[i]==x) return 0;
    }
    return 1;
}

void readfile(char str[][50])
{
    // Reads worldlist.txt file and stores the variables in an strings of array
    FILE * fp = fopen("wordlist.txt","r");
    int i=0;
    while(!feof(fp)){
        fscanf(fp,"%s",str[i]);
        i++;
    }
    fclose(fp);
}

void randomWord(int arr1[], int arr2[],char sevenArray[][50], char stringFromText[][50])
{
    // Finds 7 random words from the wordlist.txt file and put them in an strings of array
    for (int i = 0; i < 7 ; i++){
        arr2[i] =arr1[rand()%50];
        while(is_unique(arr2,arr2[i],i)==0){
            arr2[i] =arr1[rand()%50];
        }
        strcpy(sevenArray[i],stringFromText[arr2[i]]);  
    }
}

void resetBoard()
{
    // Fills the 15X15 board with space chars only
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            tableBoard[i][j] = ' ';
        }    
    }
    
}

void printTable()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%c ",tableBoard[i][j]);
        }
        printf("\n");    
    }    
}


int overWriteControl(char word[][50],int r,int c,int condition,int d){
    //Checks if  rigtward, downward and in diagonal directions of the given position is valid to fill
    int i;
	if (condition==right)
    {
	    for(i=0;i<strlen(word[d]);i++)
        {
            if(tableBoard[r][c]!=' ') return -1;
            c++;
	    }
	}
	
	if (condition==down)
    {
        for(i=0;i<strlen(word[d]);i++)
        {
            if(tableBoard[r][c]!=' ') return -1;
            r++;
        }
	}
	
	if (condition==diagonal)
    {
        for(i=0;i<strlen(word[d]);i++)
        {
            if(tableBoard[r][c]!=' ') return -1;
            c++;
            r++;
        }
	}       
	return 1;

}



void filltable(char sevenRandomChosenWords[][50])
{
    int r,c,d,len,k,yon;
    char *word;
    for (int i = 0; i < 7; i++){
        word = sevenRandomChosenWords[i];
        len = strlen(word); 
        k=0;
        yon = rand()%2;//0 for opposite direction 1 for straight direction
        do{
            r = rand()%11;
            c = rand()%11;
            d = (rand()%3)+1;   
        } while (overWriteControl(sevenRandomChosenWords,r,c,d,i)!=1); 
        // Fills the array with the given(randomly) direction and first position
        if(d == right && yon==0){
            while(len!=0){
                tableBoard[r][c+k] = sevenRandomChosenWords[i][strlen(word)-k-1];
                len--;
                k++;
            }
        }
        if(d == down && yon==0){
            while(len!=0){
                tableBoard[r+k][c] = sevenRandomChosenWords[i][strlen(word)-k-1];
                len--;
                k++;
            }            
        }
        if(d == diagonal && yon ==0){
            while(len!=0){
                tableBoard[r+k][c+k] = sevenRandomChosenWords[i][strlen(word)-k-1];
                len--;
                k++;
            }            
        }
        if(d == right && yon==1){
            while(len!=0){
                tableBoard[r][c+k] = sevenRandomChosenWords[i][k];
                len--;
                k++;
            }
        }
        if(d == down && yon==1){
            while(len!=0){
                tableBoard[r+k][c] = sevenRandomChosenWords[i][k];
                len--;
                k++;
            }            
        }
        if(d == diagonal && yon ==1){
            while(len!=0){
                tableBoard[r+k][c+k] = sevenRandomChosenWords[i][k];
                len--;
                k++;
            }            
        }
    }
    //Fills the table with random letters where the 7 chosen words are not placed
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            char letter = rand()%26 + 97;
            if(tableBoard[i][j]==' ') tableBoard[i][j]=letter;
        }   
    }
}

int scanWord(int n1, int n2,char word[7],char sevenRandomChosenWords[][50])
{
    int i;
    int len=strlen(word);
    int flag=0;
    // Checking if the word is an element of the given array of strings
    for (int i = 0; i < 7; i++)
    {
        if(strcmp(sevenRandomChosenWords[i],word)==0){
            flag++;
            break;
        }
    }
    if(flag==0)return -1;

    for(i=0;i<len;i++)//right
    {
        if(tableBoard[n1][n2+i]!=word[i]) break;
        if(i==(len-1)){
            for (int j = 0; j < len; j++){
                tableBoard[n1][n2+j]='X';
            }
            return 1;
        } 
    }
    
    for(i=0;i<len;i++){// down
        if(tableBoard[n1+i][n2]!=word[i])break;
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1+j][n2]='X';
            }
            return 1;
        } 
    }
  

    for(i=0;i<len;i++){//up
        if(tableBoard[n1-i][n2]!=word[i])break;  // 
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1-j][n2]='X';
            }
            return 1;
        } 
    }

    for(i=0;i<len;i++){// left
        if(tableBoard[n1][n2-i]!=word[i]) break;
        if(i==len-1){
            for (int j = 0; j < len; j++){  
                tableBoard[n1][n2-j]='X';
            }
            return 1;
        } 
    }        
  

    for(i=0;i<len;i++){//southeast
        if(tableBoard[n1+i][n2+i]!=word[i])break;
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1+j][n2+j]='X';
            }
            return 1;
        } 
    }
 

    for(i=0;i<len;i++){//northwest
        if(tableBoard[n1-i][n2-i]!=word[i])break;
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1-j][n2-j]='X';
            }
            return 1;
        } 
    }        
    

    for(i=0;i<len;i++){//northeast
        if(tableBoard[n1-i][n2+i]!=word[i])break;
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1-j][n2+j]='X';
            }
            return 1;
        } 
    }        
    

    for(i=0;i<len;i++){//northwest
        if(tableBoard[n1+i][n2-i]!=word[i]) break;
        if(i==len-1){
            for (int j = 0; j < len; j++){
                tableBoard[n1+j][n2-j]='X';
            }
            return 1;
        }        
    }                  
    return -1;
}



int main(){
    int lives=3,points=0;
    resetBoard();
    char stringFromText[50][50];
    readfile(stringFromText);   
    char sevenRandomChosenWords[50][50];
    srand(time(NULL));
    int arr1[50];
    for (int i = 0; i < 50; i++)arr1[i]=i;
    int arr2[7];
    randomWord(arr1,arr2,sevenRandomChosenWords,stringFromText);
    filltable(sevenRandomChosenWords);
    printTable();
    while (lives!=0 && points!=14)
    {
        int n1,n2;
        char word[50];
        printf("\nEnter the coordinates and word: ");
        scanf("%d",&n1);
        scanf("%d",&n2);
        scanf("%s",word);
        if(strcmp(word,":q")==0){
            printf("\nTerminated");
            return 0;
        }
        if(scanWord(n1,n2,word,sevenRandomChosenWords)==1){
            points+=2;
            printf("Founded you got 2 points! Your total points: %d\n",points);
            printTable();     
        }
        else{
            lives--;
            printf("Wrong choice! You have %d lives left.\n",lives);  
        }
    }
    //GAME ENDS
    if(lives==0 || points==14)printf("Game Is Over!\nYour total point is %d\n",points);
    
    return 0;
}
