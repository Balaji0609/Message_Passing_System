/**
*@file "thread_t.c"
*@brief The file which as the main function and which wil be executed.
*
*	This funtion consists of "threads.h" header file which inturn
* 	consists of all the other header files and methods that were 
*	created and consists of two funtion whose threads will be created 
* 	and run using the other methods defined.
*
*@authors "Balaji Chandrasekaran"-1208948451
*	  "Kandhan Sekar" - 
*	  "Vimal Kanna Vadivelu" -1209203043
*/

#include "threads.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int n=1;				// global variable.

/**
*@brief add function used for adding two numbers
*
*	This function is a add function which is used for
*	adding two numbers and printing the result.
*
*@param void.
*@return void.
*/

void add()
{
int num1=1;			//local variable.
while(1)
{
	printf("function1 -> addition of n=%d and n1=%d is %d \n",n,num1,n+num1);
	n++;
	num1++;
	sleep(1);
	Yield();				// This call yields to the next thread which is in the queue.
}
printf("********************end of add function**********************");
}

/**
*@brief mul function used for multiplying two numbers
*
*	This function is a multiply function which is used for
*	multiplying two numbers and printing the result.
*
*@param void.
*@return void.
*/

void mul()
{
int num2=1;				//local variable.
while(1)
{
	printf("function2 -> multiplication of n=%d and n2=%d is %d \n ",n,num2,num2*n);
	num2++;
	n++;
	sleep(1);
	Yield();				// This call yields to the next thread which is in the queue.
}
printf("********************end of add function**********************");
}

/**
*@brief main function which uses the methods those were created before.
*
*	In this function we call the two functions add and mul and create
*	threads for them, run them and see what happens when we call yield,
*	run and start_thread.These function will inturn call AddQ,DelQ and 
*	RotateQ functions in "q.h".
*
*@param void.
*@return void.
*/
void main()
{
Start_Thread(add);   	// starts the thread of add type.
Start_Thread(mul);	// starts the thread of mul type.
Run();			// calls the run method in "threads.h".
}
