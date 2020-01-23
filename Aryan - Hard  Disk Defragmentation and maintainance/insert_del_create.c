#include<stdlib.h>
#include<stdio.h>

#include "memory.h"

//DELETES THE SPECIFIED ELEMENT FROM THE LIST 
void deleting(int seq,int key)
{
	int head = lists[seq];
	
	//CHECKING IF THE LIST IS EMPTY OR NOT CREATED YET
	if(head==0)
	{
		printf("\n FAILURE: SORRY, LIST IS EITHER EMPTY OR NOT CREATED! \n");
		return;
	}
	
	
	
	//THE VERY FIRST ELEMENT IS TO BE DELETED
	if(ram[head]==key)
	{
		
		//STORING THE VALUE OF THE NEW HEAD OF THE LIST
		int nexthead = ram[head+1];
		
		//PUSHING THE FREED OBJECT INTO THE FREE LIST
		ram[head+1]=freehead;
		//ram[head]=0; IN CASE YOU WANT TO FLUSH IT WITH ZEROES
		ram[head+2]=0;
		freehead=head;
	
		//ASSIGNING THE NEW LIST HEAD
		lists[seq]=nexthead;
		ram[nexthead+2]=0;
		
		printf("\n SUCCESSFUL DELETION !! \n");
		
		return;
	}
	
	int temp;
	
	//FINDING THE ELEMENT
	for(temp=ram[head+1];temp!=0;temp=ram[temp+1])
	{
		if(ram[temp]==key)
		{
			break;
		}
	
	}
	
	//ELEMENT DOES NOT EXIST
	if(temp==0)
	{
		printf("\n FAILURE: ELEMENT DOES NOT EXIST IN THE LIST! \n");
		return;
	}
	
	
	
	int next=ram[temp+1];
	int prev=ram[temp+2];
	
	//LAST ELEMENT IS TO BE DELETED
	if(next==0)
	{
		ram[prev+1]=0;
		//ram[temp]=0; IN CASE YOU WANT TO FLUSH IT WITH ZEROES
		ram[temp+1]=freehead;
		ram[temp+2]=0;
		freehead=temp;
		
		printf("\n SUCCESSFUL DELETION !! \n");
		return;
	}
	
	//SOME MIDDLE ELEMENT IS TO BE DELETED
	
	//CROSS SEWING THE DOUBLY LINKED LIST
	ram[prev+1]=next;
	ram[next+2]=prev;
	
	//PUSHING TO FREE LIST THE DELETED OBJECT 
	//ram[temp]=0; IN CASE YOU WANT TO FLUSH IT WITH ZEROES
	ram[temp+1]=freehead;
	ram[temp+2]=0;
	freehead=temp;
	
	printf("\n SUCCESSFUL DELETION !! \n");
	return;	
	
	
}


void createlist()
{
	//CHECKING FOR LIST CONSTRAINT
	if(listcount==MAXX-1)
	{
		printf("\n Sorry, Maximum limit on lists reached! \n");
		return;
	}
	
	listcount++;
	printf("\n Creating list number %d ........ \n",listcount);
	
	//ACCEPTING VALUE FROM USER BEFORE CHECKING MEMORY CONSTRAINT
	int value;
	printf("\n Enter the value to be inserted: ");
	scanf("%d",&value);
	printf("\n");
	
	//CHECKING FOR MEMORY CONSTRAINT
	if(freehead==0)
	{
		printf("\n Sorry not enough memory! \n");
		return; 
	}
	
	

	//CREATION OF NEW LIST IF ALL CONDITIONS ARE MET	

	//POPPING FREE MEMORY FROM FREE LIST
	lists[listcount]=freehead;
	freehead=ram[freehead+1];
	ram[lists[listcount]+1]=0;
	ram[lists[listcount]+2]=0;
	ram[lists[listcount]]=value;
	
	printf("\n SUCCESSFUL CREATION !! \n");
	
	
	
}

void insert(int seq,int key)
{
	
	//CHECKING WHETHER LIST IS CREATED OR NOT
	if(seq>listcount)
	{
		printf("\n FAILURE: SORRY THIS LIST HAS NOT YET BEEN CREATED! \n");
		printf("\n NOTE: PLEASE CREATE THE LIST BEFORE INSERTING INTO IT. \n");
		return;
	}
	
	//CHECKING FOR CONSISTANCY
	if(seq<=0)
	{
		printf("\n FAILURE: PLEASE ENTER A VALID POSITIVE LIST NUMBER! \n");
		return; 
	}
	
	
	
	//CHECKING FOR MEMORY
	if(freehead==0)
	{
		printf("\n FAILURE: MEMORY NOT AVAILABLE! \n");
		return;
	}
	
	//POPPING MEMORY FROM FREE LIST AFTER SEEING THAT IT HAS THE 
	//ABILITY TO GIVE SOME
	int head = lists[seq];
	int temp = freehead;
	freehead = ram[freehead+1];
	
	//INSERTING THE VALUE INTO THE BLOCK
	ram[temp]=key;
	
	
	
	//IF THE LIST IS EMPTY
	if(head==0)
	{
		lists[seq]=temp;
		ram[temp+1]=0;
		ram[temp+2]=0;
		printf("\n SUCCESSFUL INSERTION !! \n");
		return;
	}
	
	
	
	//IF THE INSERTION NEEDS TO BE DONE IN THE 
	//BEGINNING OF THE LIST ITSELF
	if(ram[head]<=key)
	{
		ram[temp+1]=head;
		ram[temp+2]=0;
		ram[head+2]=temp;
		lists[seq]=temp;
		printf("\n SUCCESSFUL INSERTION !! \n");
		return;
	}
	
	
	head = lists[seq];
	
	//CHECKING TILL THE END OF LIST
	for(;head!=0;head=ram[head+1])
	{
		if(ram[head]<=key)
			break;
	}
	
	
	
	//THE ELEMENT IS TO BE INSERTED IN THE END OF THE LIST
	if(head==0)
	{
		for(head=lists[seq];ram[head+1]!=0;head=ram[head+1]);
		
		ram[head+1]=temp;
		ram[temp+1]=0;
		ram[temp+2]=head;
		printf("\n SUCCESSFUL INSERTION !! \n");
		return;
	}
	
	

	//THE ELEMENT NEEDS TO BE INSERTED SOMEWHERE IN BETWEEN 
	//THAT TOO BEFORE THE CURRENT POSITION OF HEAD
	ram[ram[head+2]+1]=temp;
	ram[temp+2]=ram[head+2];
	ram[head+2]=temp;
	ram[temp+1]=head;
	
	printf("\n SUCCESSFUL INSERTION !! \n");
	return;

	
}
