#include<stdio.h>
#include<stdlib.h>
#include "threads.h"


typedef struct sem
{
int i;
struct TCB_t *h;
}Semaphore_t;

 
Semaphore_t* CreateSem(int InputValue)
{
Semaphore_t *S = (Semaphore_t*)malloc(sizeof(Semaphore_t));
S->i=InputValue;
return S;
}

void P(Semaphore_t *sem)
{
sem->i--;
struct TCB_t *temp;
if(sem->i<0)
{
//yield();
	temp = DelQ(&head);
	AddQ(&(sem->h),temp);
	swapcontext(&(temp->data),&(head->data));
}
}

void V(Semaphore_t *sem)
{
sem->i++;
struct TCB_t *temp;
if((sem->i)<=0)
{
temp=DelQ(&(sem->h));
AddQ(&head,temp);
//Rotate
}
Yield();
}
