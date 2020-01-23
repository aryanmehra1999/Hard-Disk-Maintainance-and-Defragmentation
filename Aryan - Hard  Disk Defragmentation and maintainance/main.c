#include "memory.h"
#include<stdio.h>

// GLOBAL VARIABLES 
int ram[SIZE]={0};
int freehead = 1;
int lists[MAXX]={0};
int listcount=0;

int main()
{
	
    	system("clear");
    	printf("\n ***********    HELLO USER! WELCOME TO ARYAN'S RAM    ********* \n");
    	printf("\n The size of your RAM is 900 integers" ); 
    	printf("\n This means you can have upto 300 objects/nodes in it,\n (around 50 for each list if you have 6 lists)");
    	printf("\n Initiallly all objects are free.  ");
    	printf("\n For convinience indices in RAM start from 1 to 900 ");
    	
    	printf("\n\n************************************************************");
    	printf("\n Press ENTER button to start/power ON your RAM......");
    	getchar();
    	system("clear");
    	
    	//START AND INITIALISE MEMORY 
    	initialise_memory();
    	
    	int option;
    	
    	printf("\n\n************************************************************");
    	printf("\n Please Enter one of the following options: \n");
    	printf("1. Press 1 to create a new list \n");
    	printf("2. Press 2 to insert a new element in a given list in sorted order \n");
    	printf("3. Press 3 to delete an element from a list \n");
    	printf("4. Press 4 to count total elements excluding free list \n");
    	printf("5. Press 5 to count total elements of a list \n");
    	printf("6. Press 6 to display all lists \n");
    	printf("7. Press 7 to display the free list \n");
    	printf("8. Press 8 to perform defragmentation \n");
    	printf("9. Press 0 to quit \n");
    	printf("************************************************************ \n Enter Option: ");
    	
    	scanf("%d",&option);
    	
    	int a,b;
    	
    	while(option!=0)
    	{
    		system("clear");
    		switch (option)
    		{
    			case 1: 
    				//createlist() WILL PERFORM CHECKS ON FREE MEMORY  
    				createlist();
    				break;
    			
    			case 2: 
    				
    				printf("\n Which list do you want to insert into (1,2,3,4 or 5)? : ");
    				scanf("%d",&a);
    				printf("\n Enter the key value: ");
    				scanf("%d",&b);
    				
    				//insert() FUNCTION WILL DO THE VALIDIDTY AND FREE MEMEORY CHECKS
    				insert(a,b);
    				
    				break;
    				
    			case 3: 
    				
    				
    				printf("\n Which list do you want to delete from (1,2,3,4 or 5)? : ");
    				scanf("%d",&a);
    				printf("\n Enter the key value: ");
    				scanf("%d",&b);
    				
    				//delete() WILL PERFORM ITS OWN CHECKS
    				deleting(a,b);
    				
    				break;
    			
    			case 4:
    			
    				printf("\n There are %d total elements excluding free list ",allcount());
    				
    				break;
    				
    			case 5:
    			
    				
    				printf("\n Enter the sequence number of the list (1,2,3,4 or 5)? : ");
    				scanf("%d",&a);
    				
    				printf("\n There are %d elements in List %d ",elementcount(lists[a]),a);
    				
    				break;
    				
    			case 6: 
    			
    				printall();
    				break;
    				
    			case 7:
    			
    				printfreelist();
    				break;
    				
    			case 8:
    				
    				defrag();
    				
    				break;
    				
    			default:
    			
    				printf("\n Please press a valid button \n");    				
    			
    		}
    		
    		
    		printf("\n\n************************************************************");
	    	printf("\n Please Enter one of the following options: \n");
	    	printf("1. Press 1 to create a new list \n");
	    	printf("2. Press 2 to insert a new element in a given list in sorted order \n");
	    	printf("3. Press 3 to delete an element from a list \n");
	    	printf("4. Press 4 to count total elements excluding free list \n");
	    	printf("5. Press 5 to count total elements of a list \n");
	    	printf("6. Press 6 to display all lists \n");
	    	printf("7. Press 7 to display the free list \n");
	    	printf("8. Press 8 to perform defragmentation \n");
	    	printf("9. Press 0 to quit \n");
	    	printf("************************************************************ \n Enter Option: ");
    	
    		scanf("%d",&option);
	    	
	    	
	    		
    	}
    	
	
	printf("\n  *************    THANK YOU FOR USING ARYAN'S RAM!    ********* \n\n");


}
