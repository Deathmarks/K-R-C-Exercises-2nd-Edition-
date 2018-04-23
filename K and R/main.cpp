/*
   This is a main routine meant to run all the Exercises from The C Programming Language by K&R
   Author: Zachary Lowery
   Date: 1/8/2018 - 4/19/2018
*/

#include<ctime>
#include"Chapter 2.h"

int main(void){

   //Start time for a series of procedures.
   time_t startTime;
   time_t endTime;
   time_t *p_startTime = &startTime;
   time_t *p_endTime = &endTime;

   time(p_startTime);

/* 
   * A set of functions meant to make testing more manageable.
   * Might later be used in a rudimentary GUI. 
   *
*/
	
	//exercise2_2();
	//exercise2_3();
	exercise2_4();
	
	//exercise2_5();
   //exercise2_6();
   //exercise2_7();
   //exercise2_8();
   //exercise2_9();
   //exercise2_10();
   time(p_endTime);

   fprintf(stdout, "The time the main procedure took to execute was %f seconds.\r\n", difftime(endTime, startTime));
   getchar();
	
	return 0;
}