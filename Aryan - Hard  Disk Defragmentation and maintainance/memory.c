#include<stdlib.h>
#include<stdio.h>

#include "memory.h"


void initialise_memory()
{
	//INITIALISING THE FREE LIST CONTAINING ALL THE OBJECTS IN RAM MEMORY
    	
    	for(int i=2;i<SIZE;i=i+3)
    	{
       		//THE LAST FREE NODE POINTS TO NULL
       		if(i==SIZE-2)
       			ram[i]=0;
       			
       		//ALL FREE NODES POINT TO THE NEXT
       		else 
       			ram[i]=i+2;
       	
	}
}









