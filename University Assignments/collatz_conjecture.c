/*
*Description: An conjecture which, taking a number n, if n is even, divides it by 2,
*or if n is odd, multiplies it by 3 and adds 1 to obtain 3n + 1, then repeats the process to give 1.
*/

/*
*FLOW OF THE PROGRAM -> Takes the length and the first element of the sequence,
*prints out the sequence, then finds where the loop begins and finally prints out the histogram of sequence
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 50
#define TRUE 1
#define FALSE 0

void generate_sequence (int, int, int, int *);
int has_loop(int *, int , int , int *, int *);
void check_loop_iterative(void (*f)(int,int,int,int*), int , int, int *,int *);
int firstDigitFinder(int);
void hist_of_firstdigits(void (*f)(int,int,int,int*), int, int, int *, int);

void main(){
    int xs,seqlen,currentlen=0,digit,*h,*seq,looplen,*loop;
    printf("Please enter the sequence length: ");   
    scanf("%d",&seqlen);                            /*  INPUT */
    printf("Please enter the first element: ");             
    scanf("%d",&xs);                                /*  INPUT */
    looplen = seqlen/2;
    h = (int*)calloc(seqlen,sizeof(int));
    seq = (int*)calloc(seqlen,sizeof(int));
    loop = (int*)calloc(seqlen,sizeof(int));
    check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen);
    if(looplen<2) printf("No loop found\n\n");
    else{
        printf("Loop: {");
        for(int i =0;i<looplen;i++){                    
            if(i==looplen-1)printf("%d}\n\n",loop[i]);                  /* PRINTING THE LOOP IF FOUND*/
            else printf("%d, ",loop[i]);
        }
    }    
    hist_of_firstdigits(generate_sequence,xs,seqlen,h,digit);
    for(int i=1;i<10;i++){
        if(i==1)printf("Histogram of the sequence: {%d, ",h[i]);        /* PRINTING THE HISTOGRAM OF THE SEQUENCE */
        else if(i==9)printf("%d}",h[i]);
        else printf("%d, ",h[i]);
    }
}

void generate_sequence (int xs, int currentlen, int seqlen, int *seq){
    if(currentlen==seqlen) return;
    if(currentlen==0){
        seq[currentlen]=xs;
        generate_sequence(xs,currentlen+1,seqlen,seq);// PLACE XS AT INDEX 0 AND CALL FUNCTION RECURSIVELY
    }
    else{
        if(xs%2!=0){
            xs = (xs*3) + 1;
            seq[currentlen]=xs;
        }
        else{
            xs = xs/2;
            seq[currentlen]=xs;
        }
        generate_sequence(xs,currentlen+1,seqlen,seq);//RECURSIVE CALL WITH A GREATER CURRENTLEN VALUE
    }
}


int has_loop(int *arr, int n, int looplen, int *ls, int *le){
    int flag=0; 

    for (int j = 1; j <= looplen; j++){
        *le = n-j;
        *ls = n-looplen-j;
        if(arr[*le]!=arr[*ls]){  //CHECK IF *ls AND *le MATCH OR NOT
            flag++;
            break;
        }
    }
    if(flag==0) return TRUE;  // IF THEY ALL MATCH THEN RETURN TRUE
    else return FALSE; 
}


void check_loop_iterative(void (*f)(int,int,int,int*), int xs, int seqlen, int *loop,int *looplen){
    int *seq,ls,le;
    seq = (int*)calloc(seqlen,sizeof(int));
    static int x=0;
    if(x==0){
        f(xs,0,seqlen,seq);
        printf("\nSequence: {");  
        for (size_t i = 0; i < seqlen-1; i++)printf("%d, ",seq[i]);   
        printf("%d}\n",seq[seqlen-1]);
        printf("\n");
        x++;
    }
    f(xs,0,seqlen,seq);// FILLING *seq ARRAY WITH THE GENERATED SEQ
    if(has_loop(seq,seqlen,*looplen,&ls,&le)==TRUE){//IF LOOP FOUND THEN PRINT THE LOOPLEN, PRINT FIRST AND LAST DIGIT AND PRINT THE LOOP ITSELF
        printf("Checking if there is a loop of length of %d.\n",*looplen);
        printf("\nLoop detected with a length of %d.\n",*looplen);
        printf("The indexes of loop's first occurance: %d (first digit) , %d (last digit)\n",ls,le-1);
        for(int i =ls;i<le;i++)loop[i-ls]=seq[i];
    }
    else if(has_loop(seq,seqlen,*looplen,&ls,&le)==FALSE && *looplen>=2){//IF NO LOOP FOUND THEN PRINT LOOPLEN AND MAKE A RECURSIVE CALL WITH LOOPLEN-1
        printf("Checking if there is a loop of length of %d...\n",*looplen);
        *looplen-=1;
        check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);
    }
}

int firstDigitFinder(int n){
    while(n>=10){
        n /=10;
    }
    return n;
}

void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit){
    if(seqlen==0)return;//END CONDITION FOR RECURSIVE CALL
    int *seq;
    seq = (int*)calloc(seqlen,sizeof(int));
    int flag = 0,seqnum;
    f(xs,0,seqlen,seq);//GENERATING SEQUENCE
    seqnum = seq[seqlen-1];
    if(seqnum<10){
        flag++;
        h[seqnum]++;
    }
    else seqnum = firstDigitFinder(seqnum);
    if(flag==0)h[seqnum]++;
    hist_of_firstdigits(generate_sequence,xs,seqlen-1,h,digit);//RECURSIVE CALL   
}
