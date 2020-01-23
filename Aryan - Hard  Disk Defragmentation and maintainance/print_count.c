#include<stdlib.h>
#include<stdio.h>

#include "memory.h"

//FUNCTION FOR PRINTING THE FREE LIST
void printfreelist()
{
	// TAKE CARE OF EMPTY LIST
	if(freehead==0)
		printf("\n SORRY THE FREE LIST IS EMPTY, THERE ARE NO FREE OBJECTS. \n");
		
		
	else 
	{
		printf("\n ELEMENTS OF THE FREE LIST ARE: \n ");
		printf("[");
	   		
	   	//PRINTING THE FREE LIST TILL WE ENCOUNTER NULL POINTER
	   	for(int temp=freehead;temp!=0;temp=ram[temp+1])
	   	{
	   	     printf("%d ",temp);
	   	     
	   	     if(ram[temp+1]!=0)
	   	     	printf(",");
	   	}
	   	
	   	printf("]");
	}
}


//FUNCTION FOR PRINTING ANY ONE LIST
void printlist(int head)
{
    	//IF THE LIST IS EMPTY
    	if(head==0)
    		printf("\n THIS LIST IS EMPTY! \n");
    	
    	if(head!=0)
    	{
		printf("\nKey \t Next \t Prev \n");
		for(int temp=head;temp!=0;temp=ram[temp+1])
		{
		    printf("%d \t ",ram[temp]);
		    
		    if(ram[temp+1]==0)
		    	printf("NIL\t");
		    else
		    	printf("%d\t",ram[temp+1]);
		    	
		    if(ram[temp+2]==0)
		    	printf("NIL\n");
		    else
		    	printf("%d\n",ram[temp+2]);	
		}
    	}
}


//FUNCTION FOR PRINTING ALL THE LISTS
void printall()
{
	for(int i=1;i<MAXX;i++)
	{
		//PRINTING ALL LISTS
		printf("\n THE ELEMENTS OF LIST %d ARE: \n ",i);
		printlist(lists[i]);
					
	}
}




//FUNCTION FOR COUNTING ELEMENTS IN A LIST
int elementcount(int head)
{
   	int count=0;
    	for(int temp=head;temp!=0;temp=ram[temp+1])
        	count++;
    	
    	return count;
}







//FUNCTION FOR COUNTING ELEMENTS IN ALL THE LISTS
int allcount()
{
	int sum=0;
	  	
  	//SUMMING UP FOR ALL THE LISTS
  	for(int i=1;i<MAXX;i++)
      	sum= sum + elementcount(lists[i]);
    	
    	return sum;
}



