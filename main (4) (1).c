/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "snakesandladders.c"


//Neil O'Sullivan R00206266 SDH2B 


//To check if the position is at or past the final square
int check_position(int x, int final){

    if (x >= final ){
        return 1;
    } 
    else return 0;
}

//Roll dice between 1-6
int roll_dice()
{
    int result;
    srand(time(NULL));

    result=(rand()%6)+1;
    return result;
}


// Add a new square to linked list 
square * add(int num, square *head, int sHead, int sTail, int lBottom, int lTop ) {
    
    square *new_square;
    new_square = (square *) malloc(sizeof(square));
    //If x is equal to one of the snake heads set the head and tail of the snake at this square
    if (new_square->x=sHead){
    new_square->x = num;
    new_square->next= head;
    new_square->snakeHead= sHead+1;
    new_square->snakeTail= sTail+1;

    }
    // if x is equal to a ladder bottom set the ladder bottom and top values at this square
     else if (new_square->x=lBottom){
    new_square->x = num;
    new_square->next= head;
    new_square-> ladderBottom= lBottom+1;
    new_square-> ladderTop= lTop+1;

        
    }
    //else just create a square with value x and a pointer to next 
    else{
        new_square->x = num;
        new_square->next= head;
    }
    head = new_square;

return head;
}


//Print all the squares on the board
void print(square *head, int x) {
    square *current_square = head;
   	while ( current_square != NULL) {
   	  
   	  //every 5 squares go to a new line to represent the board 
   	    if(current_square->x%5==0 && current_square ->x !=0){
   	        printf("\n ");
   	    }
   	//Print *P* for current position
   	if (current_square->x == x){
           printf("*P*");
       }
       else if(current_square->x != x)
        //printf("Square = %d ladderBottom = %d SnakeHead = %d", current_square->x, current_square-> ladderBottom, current_square->snakeHead);
        printf(" %d ", current_square->x);
        current_square = current_square->next;
    }
}


int main(void)
{

square *head = NULL;   //pointer to the first square on the board

square final_square; // To pass as parameter to check if its the final square

srandom(time(NULL));

int max = 64; //Max size 64
int min = 32; //Min size  
int size = (rand() % (max-min+1)) + min;

//Different counters
int row, col;
int i=0;
int j=0;
int k=0;
int q=0;
int a =0;
int b=0;
int c =0;
int d=0;
int m=0;
int n=0;
int scounter=0;
int lcounter=0;
int final_x=0;

int numSnakes=0;
int numLadders=0;

//Start square
square start;
start.x=1;

//Pointer to current square
square *current_square = head;

square position;
position.x=1;
position.ladderBottom=0;
position.snakeHead=0;

int option=0;
//Variables to add to report
int rolls =1;
int snakes=0;
int snakesLost=0;
int ladders=0;
int laddersGained =0;


//Input number of snakes and ladders
printf("How many snakes do you want on the board?\n");
scanf("%d",&numSnakes);
printf("How many ladders do you want on the board?\n");
scanf("%d",&numLadders);

//Create arrays of size numSnakes and numLadders
int snakeHeads [numSnakes];
int snakeTails [numSnakes];
int ladderBottoms [numLadders];
int ladderTops [numLadders];

//Generate heads and tails of snakes
  for (j=0; j<numSnakes; j++)
  
{
    snakeHeads[j]= rand() % (size + 1 );
    snakeTails[j] = snakeHeads[j] - ( rand() % ( 10 + 1));
    //Make sure head is not at square 1
     if (snakeHeads[j]<2){
        snakeHeads[j] +2;
    }
    //if tail is less than 1 put tail to 1
    if (snakeTails[j]<1){
        snakeTails[j]=1;
    }
  //Make sure snake heads and tails are not on the same square
    if (snakeHeads[j] == snakeTails[j] || snakeHeads[j] == snakeTails[j+1] ||snakeHeads[j] == snakeTails[j-1])
    {
      snakeTails[j]= snakeTails[j]-1; 

    }
    
    printf("\nSnake Head %d added = %d \n", j+1, snakeHeads[j]+1);
    printf("Snake Tail %d added = %d \n", j+1, snakeTails[j]+1);
    
}

//Generate ladder bottoms and tops
 for (q=0; q<numLadders; q++)
  
{
    ladderBottoms[q]= rand() % (size + 1 );
    ladderTops[q] = ladderBottoms[q] + ( rand() % ( 10 + 1));
    //Make sure bottom is not at square 1
    if (ladderBottoms[q] == 1){
         ladderBottoms[q] =2;
     }
     //Make sure ladder does not go to or above the final square
     if (ladderTops[q]>=size-1){
         ladderTops[q]=size -2;
     }
     if (ladderBottoms[q]>=size){
         ladderBottoms[q]=ladderBottoms-3;
     }
    //Make sure ladder tops and bottoms are different
    if (ladderBottoms[q] == ladderTops[q] || ladderBottoms[q] == ladderTops[q+1] ||ladderBottoms[q] == ladderTops[q-1]|| ladderBottoms[q] == ladderBottoms[q+1] ||ladderBottoms[q] == ladderBottoms[q-1])
    {

      ladderTops[q]= ladderTops[q]+2; 
      ladderBottoms[q] = ladderBottoms[q]+1;
    }
    //Make sure ladder bottoms differ from snake heads
      if (ladderBottoms[q] == snakeHeads[q] || ladderBottoms[q] == snakeHeads[q+1] ||ladderBottoms[q] == snakeHeads[q-1]|| ladderBottoms[q] == snakeHeads[q+2] ||ladderBottoms[q] == snakeHeads[q-2]|| ladderTops[q] == snakeHeads[q+1] ||ladderTops[q] == snakeHeads[q-1] || ladderTops[q] == snakeHeads[q])
    {

      ladderTops[q]= ladderTops[q]+2; 
      ladderBottoms[q] = ladderBottoms[q]-1;
      snakeHeads[q] = snakeHeads[q]+1;
    }
     
    
    printf("\nBottom of ladder %d added = %d \n",q+1, ladderBottoms[q]+1);
    printf("Top of ladder %d added = %d \n",q+1, ladderTops[q]+1);
    
}

//Order the snakes in ascending order // needed for creation 
for (k = 0; k < numSnakes; ++k) 
        {
 
            for (j = k + 1; j < numSnakes; ++j)
            {
 
                if (snakeHeads[k] > snakeHeads[j]) 
                {

                    a =  snakeHeads[k];
                    snakeHeads[k] = snakeHeads[j];
                    snakeHeads[j] = a;
                    b =  snakeTails[k];
                    snakeTails[k] = snakeTails[j];
                    snakeTails[j] = b;
 
                }
 
            }
 
        }
        
//Order the ladders in ascending order // needed for creation 
for (n = 0; n < numLadders; ++n) 
        {
 
            for (m = n + 1; m < numLadders; ++m)
            {
 
                if (ladderBottoms[n] > ladderBottoms[m]) 
                {

                    c =  ladderBottoms[n];
                    ladderBottoms[n] = ladderBottoms[m];
                    ladderBottoms[m] = c;
                    d =  ladderTops[n];
                    ladderTops[n] = ladderTops[m];
                    ladderTops[m] = d;
 
                }
 
            }
 
        }
        

//Create all the squares 
  for (row=0; row<size; row++)
{
// if row equals a snake head create a snake at that square
    if (snakeHeads[scounter]==row) {
        head = add(i+1, head, snakeHeads[scounter], snakeTails[scounter], 0,0);
        
       scounter++;
       i++;
    }
    //if row equals a ladder bottom create a ladder at that square
     else if (ladderBottoms[lcounter]==row) {
        head = add(i+1, head, 0, 0, ladderBottoms[lcounter],ladderTops[lcounter]);
        
       lcounter++;
       i++;
    }
// else create normal square
    else{
         head = add(i+1, head,0,0,0,0);
        

       i++;
    }
}


final_square.x = i;


//open file to print to
FILE *f;

if ((f = fopen("game_report_file", "w")) == NULL){
 printf("Error opening file\n");
 return;
}


printf("\n");
printf("Start point = %d \n", start.x);
printf("End point = %d\n", final_square.x);


printf("*P* represents the current board position!\n");
printf("\n");

fprintf(f, "%s  %d\n", "Start point: ",  start.x);
fprintf(f, "%s  %d\n", "End point: ",  final_square.x);

//While not exit
while(option!=9){

//if the game is not over print the board
    if (check_position(position.x, final_square.x)!=1){
        print(head, position.x);
  }
  
//menu
    printf("\n***********Snakes and Ladder Game***********\n");
    printf("\n");
    printf("1. Press 1 to roll the dice.\n");
    printf("9. Press 9 to exit.\n");
    scanf("%d",&option);
    printf("*P* represents the current board position!\n");
    printf("\n");

//roll dice 
	if (option==1) {       
            int dice_value=roll_dice();
            fprintf(f, "\n%s  %d %s %d\n", "Roll Number: ",  rolls, " Start position: ", position.x);
            position.x=position.x+dice_value;// new position 
        
            printf("Number rolled = %d \n",dice_value);
            printf("New position = %d  \n", position.x);
            printf("\n");
            fprintf(f, "%s  %d %s %d\n", "Number rolled: ",  dice_value, " New position: ", position.x);
  
  //check if square landed on is a snake or ladder if so set position snake details or ladder details          
    square *current_square = head;
            
    while ( current_square != NULL) {
  
   	   if (current_square->x == position.x){
           
           position.snakeHead = current_square->snakeHead ;
           position.snakeTail = current_square->snakeTail ;
           position.ladderBottom = current_square->ladderBottom ;
           position.ladderTop = current_square->ladderTop ;
           break;
          
       

        }
       else if(current_square->x != position.x)
  
        current_square = current_square->next;
      }
       
      //if position square is a snake go back       
            if(position.snakeHead > 1){
            snakes++;
            snakesLost= snakesLost +(position.x - position.snakeTail);
            printf("Landed on a Snake! :( ");
            printf("Move back to square number:  %d  \n", position.snakeTail);
            position.x = position.snakeTail;
            fprintf(f, "%s  %d \n", "Snake landed on, went back to square: ",  position.x);
            printf("New position = %d  \n", position.x);
            printf("\n");
        
            }
            // if position square is a ladder go forward
              if(position.ladderBottom > 1){
 
            ladders++;
            laddersGained= laddersGained +(position.ladderTop - position.x);
            printf("Landed on a Ladder! :) ");
            printf("Move up to square number:  %d  \n", position.ladderTop);
            position.x = position.ladderTop;
            fprintf(f, "%s  %d \n", "Ladder landed on, went up to square: ",  position.x);
            printf("New position = %d  \n", position.x);
            printf("\n");
            
            //fprintf(f, "%s  %d %s %d", "Snake landed on, went back to square: ",  position.x, "Fr");

                
            }
           
      rolls++;     
	}
	//exit
	else if (option==9) {       
            printf("Thank you for playing. Goodbye :) ");
            fprintf(f, "Game left early. ");
            fclose(f);
     
	}
	//incorrect input
else{
    printf("Incorrect selection\n");
    printf("Please roll again.\n");
    
    
}
//If position past or equal to final square game over 
    if (check_position(position.x, final_square.x)==1){

    printf("You made it to the end! You Win! :) \nThanks for playing, check out your game report in the game_report_file :)\n");
    //print details to file
    fprintf(f, "%s\n", "You completed the Snakes and Ladders Game! :) Some details of your game are shown below! ");
    rolls= rolls-1;
    fprintf(f, "%s  %d \n", "Total number of rolls:",  rolls);
    fprintf(f, "%s  %d %s %d\n", "Total number of snakes landed on:",  snakes, "Total places lost: ", snakesLost);
    fprintf(f, "%s  %d %s %d\n", "Total number of ladders taken:",  snakes, "Total places gained: ", laddersGained);

        fclose(f);// close file
        break;
        
    }

    }
  
    fclose(f);//close file 
    
	  }
	  