#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define STACK_BLOCK_SIZE 10
typedef struct stack{ 
    int *arr; 
    int currentsize; 
    int maxsize;
}stack;

int push(stack *, int);
int pop(stack *);
stack *init_return();/* initializes an empty stack */
int init(stack *);/* returns 1 if initialization is successful */
void movement(stack *, char , stack *, char , int);
void print_move(stack *, char , stack *, char);


void main(){
    int towerSize,counter=0,step=0,n=1;
    printf("Enter tower size: ");
    scanf("%d",&towerSize);
    stack *t1,*t2,*t3;// creating pole 1,2 and 3 and initialization
    t1 = init_return();
    t2 = init_return();
    t3 = init_return();
    n=pow(2,towerSize);//Number of movements required : 2^n -1
    n-=1;

    if(towerSize>=STACK_BLOCK_SIZE){// if the tower size that user entered is larger than stackblocksize than realloc for stack arrays
        t1->arr = realloc(t1->arr,sizeof(int)*towerSize);
        t2->arr = realloc(t2->arr,sizeof(int)*towerSize);
        t3->arr = realloc(t3->arr,sizeof(int)*towerSize);
    }
    
    for(int i=towerSize; i>=1;i--)
        push(t1,i);

    while(counter<n){
        counter+=1;
        step = (step%3)+1;  
        if(towerSize%2==0){//If the tower size is even then we need to change tower2 and tower3
            switch(step){
                case 1://move between pole 1 and 2
                    movement(t1,'1',t3,'2',counter%2);
                    break;
                case 2://move between pole 1 and 3
                    movement(t1,'1',t2,'3',counter%2);
                    break;
                case 3://move between pole 2 and 3
                    movement(t3,'2',t2,'3',counter%2); 
                    break;
            }          
        }
        else{
            switch(step){
                case 1://move between pole 1 and 3
                    movement(t1,'1',t3,'3',counter%2);
                    break;
                case 2://move between pole 1 and 2
                    movement(t1,'1',t2,'2',counter%2);
                    break;
                case 3://move between pole 2 and 3
                    movement(t3,'3',t2,'2',counter%2);
                    break;
            }             
        }
    }
}


stack *init_return(){
    stack * s = (stack*)calloc(1,sizeof(stack));//initilazing a stack for representing a pole
    if(init(s)!=1){printf("initialization is not successful\n");exit(0);}// checks if initialization of stack is succesful
    s->currentsize = 0; 
    s->maxsize = STACK_BLOCK_SIZE;
    s->arr = (int*)calloc(s->maxsize,sizeof(int));// memory allocation for int array of stack s
    return s;
}


int init(stack *s){
    if(s!=NULL)return 1;
    else return -1;
}

int push(stack * s, int d){
    s->currentsize++;           // putting value d in the next index so we need to increment currentsize by 1
    s->arr[s->currentsize] = d; // and at that index making an assignment
    return 1;
}

int pop(stack *s){
    return s->arr[s->currentsize--]; // returns value at index s->currentsize and decrement currentsize by 1
}
void print_move(stack *startTower, char sname, stack *endTower, char ename)
{
    printf("\nMove disk %d from '%c' to '%c'",startTower->arr[startTower->currentsize],sname,ename);
    push(endTower,startTower->arr[startTower->currentsize]);
    pop(startTower);   
}


void movement(stack *s, char snm, stack *e, char enm, int modofcounter){   
    //it is clear that in every two times we need to move disk 1 at the other one we need to move other disks so we need mod 2 of counter
    if(modofcounter==1){//Movement of disk 1
        if(s->arr[s->currentsize]==1)//checking if disk 1 is at top of stack s
            print_move(s,snm,e,enm);
        else if(e->arr[e->currentsize]==1) //checking if disk 1 is at top of stack e
            print_move(e, enm, s, snm);
    }
    else if(modofcounter==0){// Movement of other disks
        if(e->currentsize!=0 &&  e->arr[e->currentsize] < s->arr[s->currentsize])//When all poles have at least 1 disk placing small number over the greater one
            print_move(e, enm, s, snm);
        else if(e->currentsize==0) //If stack e doesnt have any disk place place disk at top of s to e
            print_move(s, snm, e, enm);
        else if(s->currentsize != 0 && s->arr[s->currentsize] < e->arr[e->currentsize])//When all poles have at least 1 disk placing small number over the greater one
            print_move(s, snm, e, enm);
        else if(s->currentsize == 0) //If stack s doesnt have any disk place place disk at top of e to s
            print_move(e, enm, s, snm);
    }
}
