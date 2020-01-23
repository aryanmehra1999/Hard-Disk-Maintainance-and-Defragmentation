#include<stdlib.h>
#include<stdio.h>

#include "memory.h"

void defrag()
{
	if(freehead==0)
	{
		printf("\n SUCCESSFUL DEFRAGMENTATION! THERE ARE NO FREE ELEMENTS. RAM IS ALREADY DEFRAGMENTED!\n");
		return;
	}
	
	//START FROM WHERE THE FREE LIST SHOULD BEGIN AFTER DEFRAGMENTATION
	int i = SIZE - (elementcount(freehead) * 3);
	
	//INITIALISE THE TRAVERSAL FOR FREE LIST
	int temp = freehead;
		
	//TRAVEL ACCROSS THE RAM STARTING FROM i
	while(i!=SIZE)
	{
	
		
		int t1,t2,t3;
		
		//SWAP THE TWO DATA BLOCKS
		t1=ram[temp];
		t2=ram[temp+1];
		t3=ram[temp+2];
		ram[temp]=ram[i];
		ram[temp+1]=ram[i+1];
		ram[temp+2]=ram[i+2];
		ram[i]=t1;
		ram[i+1]=t2;
		ram[i+2]=t3;
		
		
		//MAKE SURE ALL OBJECTS POINTING TO iTH OBJECT NOW POINT TO tempTH OBJECT
		//AND VICE VERSA TOO
		for(int j=1;j<SIZE;j++)
		{
			if(ram[j]==temp)
				ram[j]=i;
				
			else if(ram[j]==i)
				ram[j]=temp;
		}
		
		//MAKE SURE THAT THE HEADS OF THE LISTS ARE ALSO SWAPED IF NEED BE
		if(freehead==temp)
			freehead=i;
		else if(freehead==i)
			freehead=temp;
		
		for(int j=1;j<MAXX;j++)
		{
			if(lists[j]==temp)
				lists[j]=i;
			else if(lists[j]==i)
				lists[j]=temp;
		}
		
		//NOW SEE WHERE TO GO NEXT IN THE FREE LIST
		if(t2==i)
			temp=temp; //WHERE YOU WANTED TO GO IS NOW WHERE YOU ARE
		else 
			temp=t2;//WHERE YOU WANTED TO GO IS WHERE IT WAS BEFORE
		
		//TRAVEL TO THE NEXT SLOT IN MEMORY SIMPLY
		i=i+3;
		
		
		
		
	}
	
	printf("\n SUCCESSFUL DEFRAGMENTATION! \n"); 
	printf("ALL THE ELEMENTS OF THE FREE LIST HAVE BEEN PUSHED TO THE RIGHT");

}

