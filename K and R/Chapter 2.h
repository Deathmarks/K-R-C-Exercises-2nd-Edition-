/*
   This is a set of function prototypes, type declarations, and preprocessor directives
   that allow the Chapter 2 function definitions to work appropriately.

   Author: Zachary Lowery
   Date: 1/8/2018 - 4/19/2018

*/

#ifndef CHAPTER_2_H
#define CHAPTER_2_H

//Importing necessary header files.
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdint>
#include<stdlib.h>
#include<intrin.h>

//Defining MACRO constants.
#define DEBUG 1
#define R_DEBUG 1
#define BUFFER_LIMIT 256
#define BUFFER_WRITE_LIMIT BUFFER_LIMIT-1
#define ASCII_CHAR_NUM 127
#define BACKSPACE '\x08'
#define DECIMAL 10
#define BINARY 2
#define HEXIDECIMAL 16

//Defining MACRO functions
#define USER_PROMPT(string) fprintf(stdout, "%s", string);
#define LARGEST_STR_SIZE(a , b) (a <= b) ? b : a;

#define PROVE_CONFIRMATION() fprintf(stderr, "If this looks correct. Press Enter.\r\n"); {char getKey; while((getKey = getchar()) != EOF, getKey != '\n');}
#define PURGE_STDIN(){while(getchar() != EOF);}

#define SET_START_CLOCK() startClock = returnProcessorClock();
#define SET_END_CLOCK() endClock = returnProcessorClock();
#define GET_CLOCK_DELTA() endClock - startClock

#define ASSESS_FUNCTION_RUNTIME_CLOCK(FUNCTION_NAME, FUNCTION_RETURN_VAR) SET_START_CLOCK(); FUNCTION_RETURN_VAR = FUNCTION_NAME; SET_END_CLOCK(); fprintf(stdout, "\r\n\t-Here is the number of clock cycles it took to execute: %llu\r\n", GET_CLOCK_DELTA()); 
#define ASSESS_FUNCTION_RUNTIME_CLOCK(FUNCTION_NAME) SET_START_CLOCK(); FUNCTION_NAME; SET_END_CLOCK(); fprintf(stdout, "\r\n\t-Here is the number of clock cycles it took to execute: %llu\r\n", GET_CLOCK_DELTA());


/* A botched attempt at making bitcount faster by turning it into a macro. . . 
*
#define BIT_COUNT(targetValue) numberOfBits = (targetValue | 0) ? 1 : 0; unsignedIntContainer = targetValue; for(; unsignedIntContainer &= (unsignedIntContainer - 1); ++numberOfBits);

static char numberOfBits = 0;
static int  unsignedIntContainer = 0;

*/

//Declaring function prototypes, functions associated with functions above them are indented by three spaces.
//   If a function is used in multiple unrelated functions, it is shown indented under the first procedure 
//   that makes use of it.
void exercise2_2(void);
void exercise2_3(void);
   const int htoi(unsigned const char const*);
   const int exp16(const unsigned char);
   const int hexCharToIntVal(const unsigned char);

void exercise2_4(void);
   void squeeze(unsigned char*, const unsigned char const*);
      void getStringSize(int*, int*, const unsigned char*, const unsigned char*);
	   void buildLegend(unsigned char*, const int, const unsigned char*, const int);
	   void transformString(const unsigned char*, const int, unsigned char*, const int);

void exercise2_5(void);
      int any(const unsigned char*, const unsigned char*);
      int reportStringPos(const unsigned char*, const unsigned char, const unsigned char*, const unsigned char);

void exercise2_6(void);
      int setbits(int, char, char, int);
	      int initializeBitField(const char const*);
      void waitForValidInput(char[], const char, const char);
      int chooseBase(void);

void exercise2_7(void);
   int invert(int, const char, const char);

void exercise2_8(void);
   int rightrot(int, const char);

void exercise2_9(void);
   inline volatile int bitcount(volatile unsigned int);
   volatile int bitCountOriginal(volatile unsigned int);

void exercise2_10(void);
   const char newLower(const char);

void initializeBuffer(char *const, const int);

uint64_t returnProcessorClock(void);

//ENUM Definition
enum HEX_ENUM{
	ZERO = 0,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	HEX_A,
	HEX_B,
	HEX_C,
	HEX_D,
	HEX_E,
	HEX_F,
};

//static variables declared below.
static size_t numOfBitsInByte;
static uint64_t startClock;
static uint64_t endClock;

#endif