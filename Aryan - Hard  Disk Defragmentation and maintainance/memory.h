#include<stdio.h>
#include<stdlib.h>

#define SIZE 901
#define MAXX 7

// GLOBAL VARIABLES
extern int ram[SIZE];
extern int freehead;
extern int lists[MAXX];
extern int listcount;

void printfreelist();
void printlist(int head);
void printall();
int elementcount(int head);
int allcount();
void deleting(int seq,int key);
void createlist();
void insert(int seq,int key);
void initialise_memory();
void defrag();

