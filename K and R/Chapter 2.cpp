/*This is a set of functions to accomplish the Exercises established in Chapter 2 of:
    
	The C Programming Language
       by K&R

Author: Zachary Lowery
Date: 1/8/2018 - 4/18/2018
*/

#include"Chapter 2.h"

//TODO: Add exercise2_1, which currently resides on another HDD in a seperate machine.

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_2()
   * Description: A simple exercise from K&R page 42.
   *
   * Problem Statement(s): Write a loop equivalent to the for loop above without using && or ||.
   *
   * Problem Statement Code: for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
   *                            s[i] = c;
   *
   * Observation(s): Most exercise2_x() calls involved exercises that were too complicated to solve using just
   *               one function (not including I/O functions), but this exercise is an exception.
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_2(void){
	
	//Local Variable Declarations
	int i;
	char c;
	char stringBuffer[BUFFER_LIMIT];

	//We are initializing a constant pointer to our stringBuffer so we may print the contents.
	char const *readBuffer = stringBuffer;
	
	//We need to make sure the last element in the stringBuffer array had a '\0' assigned to it.
	//The '\0' character is used as a sentinel for many functions in C, ensuring that buffer overflows are not caused
	//and that string routines within the language function appropriately.
	stringBuffer[254] = '\0';

	 
	for(i = 0; i < BUFFER_WRITE_LIMIT, c = getchar(), c != '\n', c != EOF; i++){
		
		stringBuffer[i] = c;

		//This is not a normal part of the Exercise, but we are printing what the string buffer contains.
		fprintf(stdout, "%c", readBuffer[i]);
	}
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_3() 
   * Description: A (not so) simple exercise from K&R page 46.
   *
   * Problem Statement(s): Write the function htoi(s), which vonverts a string of hexadecimal digits (including
   *                       an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
   *                       through 9, a through f, and A through F.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A
   *
   * Precondition(s): N/A
   *              
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_3(void){
	
	//Creating buffers for a console to use.
	unsigned char numberField[BUFFER_LIMIT];
	numberField[BUFFER_WRITE_LIMIT] = '\0';

	//Put a null-terminator character here so we don't read garbage during the message.
	numberField[0] = '\0';

	//Creating local variables to store the characters given by the user.
	unsigned char temp;
	unsigned char index = 0;
    
	fprintf(stdout, "Please enter the hex number you would like to convert into an integer (Press Return to Submit): ");
	while(index < BUFFER_WRITE_LIMIT, (temp = getchar()) != EOF, temp != '\n'){
		if((temp == BACKSPACE) && index > 0){
			numberField[index--] = '\0';
			continue;
		}
		numberField[index++] = temp;
		numberField[index] = '\0';
		fprintf(stdout, "%s", numberField);
	}

	fprintf(stdout, "NumberField is: %s\r\n", numberField);
	fprintf(stdout, "\r\n\n\tThe result is: %i\r\n", htoi(numberField));
	getchar();
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_4()
   * Description: A (not so) simple exercise from K&R page 48.
   *
   * Problem Statement(s): Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that 
   *                       matches any character in the string s2.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): ERROR: A function used in this function doesn't perform correctly on some inputs, 
   *                      i.e. squeeze(Porta-Still, Kill) produces Porta instead of the expected Porta-St,
   *                      I suspect it has something to do with the hyphen. 
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_4(void){

	//Initialize buffers to store user-input.
	unsigned char originalBuffer[BUFFER_WRITE_LIMIT];
	unsigned char changeBuffer[BUFFER_WRITE_LIMIT];
	char oldString[BUFFER_WRITE_LIMIT];
	char tempStorage = '\0';
	char charIndex = 0;

	fprintf(stdout, "Enter a string to be used as the reference string.\r\n");

	while(charIndex < BUFFER_WRITE_LIMIT, (tempStorage = getchar()) != EOF, tempStorage != '\n'){
	    originalBuffer[charIndex++] = tempStorage; 
	}
	originalBuffer[charIndex] = '\0';
	charIndex = 0;

	fprintf(stdout, "Enter a string to be changed: \r\n");
	
	while(charIndex < BUFFER_WRITE_LIMIT, (tempStorage = getchar()) != EOF, tempStorage != '\n'){
	    oldString[charIndex] = changeBuffer[charIndex] = tempStorage;
		charIndex++;
	}
	oldString[charIndex] = changeBuffer[charIndex] = '\0';


	ASSESS_FUNCTION_RUNTIME_CLOCK(squeeze(changeBuffer, originalBuffer));

	fprintf(stdout, "The reference string is: %s\r\n\tThe original string was: %s\r\n\tThe changed string is: %s\r\n", originalBuffer, oldString, changeBuffer);
	getchar();
	
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_5()
   * Description: A (not so) simple exercise from K&R page 48.
   *
   * Problem Statement(s): Write the function any(s1,s2), which returns the first location in the string s1 where
   *                       any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (...)
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_5(void){

	//Initialize buffers to store user-input.
	unsigned char originalBuffer[BUFFER_WRITE_LIMIT];
	unsigned char searchBuffer[BUFFER_WRITE_LIMIT];
	char tempStorage = '\0';
	char charIndex = 0;

	fprintf(stdout, "Enter a string to be used as the reference string.\r\n");

	while(charIndex < BUFFER_WRITE_LIMIT, (tempStorage = getchar()) != EOF, tempStorage != '\n'){
	    originalBuffer[charIndex++] = tempStorage; 
	}
	originalBuffer[charIndex] = '\0';
	charIndex = 0;

	fprintf(stdout, "Enter a string to search: \r\n");
	
	while(charIndex < BUFFER_WRITE_LIMIT, (tempStorage = getchar()) != EOF, tempStorage != '\n'){
	    searchBuffer[charIndex] = tempStorage;
		charIndex++;
	}
	searchBuffer[charIndex] = '\0';

	int stringPosition;
   ASSESS_FUNCTION_RUNTIME_CLOCK(any(originalBuffer, searchBuffer), stringPosition);

	fprintf(stdout, "The reference string is: %s\r\n\tThe string to search was: %s\r\n\tThe position in the string is: %d\r\n", originalBuffer, searchBuffer, stringPosition);
	getchar();
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_6()
   * Description: A (not so) simple exercise from K&R page 49. This was easily one of the harder functions 
   *              present in the work so far.
   *
   * Problem Statement(s): Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position
   *                    p set to the rightmost n bits of y, leaving the other bits unchanged.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_6(void){

   int sourceNumberParameter = 0;
   char positionParameter = 0;
   char bitFieldWidthParameter = 0;
   int targetNumberParameter = 0;
   
   //Creating buffers for a console to use.
   char numberField[BUFFER_LIMIT];
	numberField[BUFFER_WRITE_LIMIT] = '\0';

   initializeBuffer(numberField, BUFFER_LIMIT);

   //Choose what base you'd like to use.
   //int referenceBase = chooseBase();

   /*
	USER_PROMPT("Please enter the source number (Press Return to Submit): ");
   waitForValidInput(numberField, 0, sizeof(int) * 8);
   sourceNumberParameter = strtol(numberField, NULL, referenceBase);

   USER_PROMPT("Please enter the position where you want the bits to be edited (Press Return to Submit): ");
   waitForValidInput(numberField, 0, sizeof(int) * 8);
   positionParameter = strtol(numberField, NULL, referenceBase);

   USER_PROMPT("Please enter the bit field width parameter (Press Return to Submit): ");
   waitForValidInput(numberField, 0, sizeof(int) * 8);
   bitFieldWidthParameter = strtol(numberField, NULL, referenceBase);

   USER_PROMPT("Please enter the target number (Press Return to Submit): ");
   waitForValidInput(numberField, 0, sizeof(int) * 8);
   targetNumberParameter = strtol(numberField, NULL, referenceBase);

   int result = setbits(targetNumberParameter, positionParameter, bitFieldWidthParameter, sourceNumberParameter);
   */

   int result;
   ASSESS_FUNCTION_RUNTIME_CLOCK(setbits(7, 0, 4, 0), result);
   fprintf(stdout, "Here is the result of the setbits procedure: %d\r\n", result); 
   getchar();
	
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_7()
   * Description: A simple exercise from K&R page 49.
   *
   * Problem Statement(s): Write a function invert(x,p,n) which returns x with the n bits that begin at 
   *                       position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others 
   *                       unchanged.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_7(void){

   int result;
   ASSESS_FUNCTION_RUNTIME_CLOCK(invert(4, 0, 3), result);
   fprintf(stdout, "Here is the result of the invert procedure: %d\r\n", result); 
   getchar();
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_8()
   * Description: A simple exercise from K&R page 49.
   *
   * Problem Statement(s): Write a function rightrot(x,n) that returns the value of the integer x rotated to 
   *                       the right by n bit positions.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_8(void){

   int result;
   ASSESS_FUNCTION_RUNTIME_CLOCK(rightrot(55, 0), result);
   fprintf(stdout, "Here is the result of the rightrot procedure: %d\r\n", result); 
   getchar();
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_9()
   * Description: A simple exercise from K&R page 51.
   *
   * Problem Statement(s): In a two;s complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
   *                    Explain why. Use this observation to write a faster version of bitcount.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): The most interesting thing about this exercise is having to use the system clock in order
   *               to determine which is faster, for some reason the first function called for the purposes
   *               of comparison was always much slower than the second, even if they happened to be the same
   *               functions with the same input. Ex. bitOriginal(-1) compared with itself yielded times that
   *               were roughly three times larger for the first call than for the second. Using this information
   *               I was able to determine intuitively that my replacement function was much more efficient.
   *               
   *                
   *               Credits: StackOverflow
   *                  -User: Mysticial
   *                  -URL: https://stackoverflow.com/questions/13772567/get-cpu-cycle-count
   *
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/

void exercise2_9(void){

   volatile int result = 0;

   ASSESS_FUNCTION_RUNTIME_CLOCK(bitcount(-1), result);
   fprintf(stdout, "Here is the result of the bitCount procedure: %d\r\n", result);
   
   ASSESS_FUNCTION_RUNTIME_CLOCK(bitCountOriginal(-1), result);
   fprintf(stdout, "Here is the result of the bitCountOriginal procedure: %d\r\n", result);
   
   getchar();
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: exercise2_10()
   * Description: A simple exercise from K&R page 52.
   *
   * Problem Statement(s): Rewrite the function lower, which converts upper case letters to lower case, with 
   *                       a conditional expression instead of if-else.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): N/A 
   * 
   * Precondition(s): N/A
   *
   * Return type: void
   *
   * Parameter List: void
   -----------------------------------------------------------------------------------------------------------------
*/
void exercise2_10(void){

   char character;

   ASSESS_FUNCTION_RUNTIME_CLOCK(newLower('G'), character);
   fprintf(stdout, "Here is the result of newLower: %c\r\n", character);
}


/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: squeeze(changeString, baseString)
   * Description:  This function is designed to take a pointer to an unsigned char and sequentially delete
   *               any characters found in changeString that are in baseString. 
   *               A function implemented for Exercise 2-4 on page 48 of K&R.
   *
   * Problem Statement Code: N/A
   *                          
   * Observation(s): This function is known to fail on certain inputs, i.e. changeString := Porta-Still, 
   *               baseString := Kill causes the incorrect output of Porta, rather than the expected 
   *               Porta-St. I suspect it has something to do with the hyphen.
   *             
   * Precondition(s): Both char sequences (array or otherwise) MUST be terminated by a '\0' or this function 
   *               will produce undefined behavior. (Notice me SEG-PAI!)
   *
   * Return type: void
   *
   * Parameter List:   unsigned char* - changeString
   *                   const unsigned char const* - baseString 
   -----------------------------------------------------------------------------------------------------------------
*/
void squeeze(unsigned char *changeString, const unsigned char const *baseString){
	int changeStringSize = 0;
	int baseStringSize = 0;

    //Get the sizes for each string respectively.
	getStringSize(&changeStringSize, &baseStringSize, changeString, baseString);

	//Store the size of the larger string.
	const int largestIndex = LARGEST_STR_SIZE(changeStringSize, baseStringSize);

    
    #if DEBUG
	   fprintf(stderr, "The size of largestIndex is: %d\r\n", largestIndex);
    #endif

	//Build a character legend.
	//Our legend has to hold the number of characters in our character set, in this case, ASCII.
	unsigned char legend[ASCII_CHAR_NUM];

	//We don't need to use all that space, so we "cut off" a portion of our legend so certain functions
	//can't see it.
	legend[largestIndex] = '\0';

	//Populate our legend with unique characters from the base String.
	buildLegend(legend, largestIndex, baseString, baseStringSize);

	//Use the legend to delete all characters found within in the string to be changed.
	transformString(legend, largestIndex, changeString, changeStringSize);
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: any(referenceString, searchString)
   * Description: A function that returns the position (index) of any character in referenceString found in 
   *              searchString. Or -1 if no character from referenceString is found in searchString. 
   *              A function implemented for Exercise 2-5 on page 48 of K&R.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): N/A
   *
   * Precondition(s): Both referenceString and searchString must be a valid sequence of characters that is terminated
   *                  by a '\0', or undefined behavior will result.
   *             
   * Return type: int
   *
   * Parameter List:   const unsigned char* - referenceString
   *                   const unsigned char* - searchString 
   -----------------------------------------------------------------------------------------------------------------
*/
int any(const unsigned char* referenceString, const unsigned char* searchString){
	int searchStringSize = 0;
	int referenceStringSize = 0;

	//Figure out the sizes of each string.
    getStringSize(&referenceStringSize, &searchStringSize, referenceString, searchString);

	const int largestIndex = LARGEST_STR_SIZE(searchStringSize, referenceStringSize);

	//Declare a legend mapping.
	char unsigned legend[ASCII_CHAR_NUM];

	//Make sure the legend mapping has an end to it (for string functions)
	legend[largestIndex] = '\0';

	//Populate our legend with useful values.
	buildLegend(legend, largestIndex, referenceString, referenceStringSize);

	//Search the string using our legend and return the position of the first character we see.
	return reportStringPos(legend, largestIndex, searchString, searchStringSize);

}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/3/2018
   *
   * Function Name: htoi(s)
   * Description: This function takes a sequence of characters as an argument (array or otherwise), interprets that
   *              sequence as hexadecimal and converts them into an integer.
   *              A function implemented for Exercise 2-3 on page 46 of K&R.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): N/A
   *
   * Precondition(s): s must be a valid sequence of characters that is terminated by a '\0', or undefined behavior 
   *                  will result.
   *             
   * Return type: const int
   *
   * Parameter List:   unsigned const char const* - s 
   -----------------------------------------------------------------------------------------------------------------
*/
const int htoi(unsigned const char const* s){

	//Initialize local variables
	unsigned char stringSize = 0;
	unsigned char stringIndex = 0;
	unsigned char searchStringOffset = 0;
	int intConversion = 0;
	bool negativeFlag = false;

	//Check to see if the string denotes a negative number.
	if(s[0] == '-'){
		negativeFlag = true;
	   
	   //We need to compensate for the additional '-' character in the string.
	   searchStringOffset = 1;
	   stringSize--;
	}

	//Check to see if they used the optional "0x" or "0X" prefix and make changes accordingly.
	while(s[stringIndex] != '\0'){
	   if(tolower(s[stringIndex++]) == 'x'){
		   searchStringOffset += 2;
		   stringSize = 0;
		   continue;
	   }

      //Gather information regarding the relative size of the string. (Not including the optional components)
	   stringSize++;
	}

   //TODO: Debate with oneself on whether to add a sentinal check for stringSize <= (sizeof(int)*2 - 1) (number of hexadecimal places allowed on signed int before overflow)

	for(stringIndex = searchStringOffset; (stringIndex - searchStringOffset) < stringSize; stringIndex++){
		intConversion += (exp16((stringSize - 1) - (stringIndex - searchStringOffset)) * hexCharToIntVal(s[stringIndex]));
		fprintf(stderr, "Here is the value for intConversion: %d\r\n", intConversion);
	}

	//If the string denotes a negative, make the result reflect it.
	if(negativeFlag){
      
      //Check for signed integer overflow.
      if(intConversion < 0){
         USER_PROMPT("ERROR: htoi(s) computed a result that was too large and caused the number to overflow. Disregard result.\r\n");
      }
		intConversion *= -1;
	}

	return intConversion;
}


/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/4/2018
   *
   * Function Name: exp16(power)
   * Description: This function takes an unsigned char and returns an integer corresponding to 16 raised to the power
   *              of the provided parameter.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): To make this function safer, I probably need to calculate the max power that may be safely calculated
   *                  using an int return type. One obvious improvement would be to change the return type to unsigned const
   *                  int. But a more sophisticated sentinel check would be preferred. Another improvement would be to remove
   *                  the engine variable as it is redundant.
   *
   * Precondition(s): power must be a positive number, as negative numbers will most likely cause the function to
   *                  produce an arithmetic overflows.
   *             
   * Return type: const int
   *
   * Parameter List:   unsigned char - power 
   -----------------------------------------------------------------------------------------------------------------
*/
const int exp16(unsigned char power){
   
   //Local variable
   int result = 1;
   char engine = power;

   while(engine-- != 0){
	   result *= 16;
   }

   //TODO: Move this to the top of the function. . .
   if(power == 0) return 1;
   return result;
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/4/2018
   *
   * Function Name: hexCharToIntVal(key)
   * Description: This function takes a single character as an input and returns its numerical equivalent as an integer.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function returns a const int, I plan on including a case for dealing with invalid input, in
   *                  which case it will return -1. This function was implemented for use in the htoi(s) function.
   *
   * Precondition(s): key must be a valid character in hex notation, in the event it is not the function produces undefined
   *                  behavior. (Compiler will probably barf because there is no value returned).
   *             
   * Return type: const int
   *
   * Parameter List:   const unsigned char - key 
   -----------------------------------------------------------------------------------------------------------------
*/
const int hexCharToIntVal(const unsigned char key){
	switch(key){
	   case '0': return ZERO;
	   case '1': return ONE;
	   case '2': return TWO;
	   case '3': return THREE;
	   case '4': return FOUR;
	   case '5': return FIVE;
	   case '6': return SIX;
	   case '7': return SEVEN;
	   case '8': return EIGHT;
	   case '9': return NINE;
	   case 'a':
	   case 'A': return HEX_A;
	   case 'b':
	   case 'B': return HEX_B;
	   case 'c':
	   case 'C': return HEX_C;
	   case 'd':
	   case 'D': return HEX_D;
	   case 'e':
	   case 'E': return HEX_E;
	   case 'f':
	   case 'F': return HEX_F;
      //TODO: Need to add and test default case.
	}
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/4/2018
   *
   * Function Name: getStringSize(stringSizeOne, stringSizeTwo, metamorphicString, originalString)
   * Description: This function takes two pointers to char sequences and increments pointers to ints for internal use
   *              in another function.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): The use of all these pointers isn't very elegent, I would have preferred to keep the argument list
   *                  down to two arguments, but doing so would have required that I pass an array (or multiple arrayes) 
   *                  with the parameters in it (cheating) or make the character sequences as members of a struct that 
   *                  internally kept track of the size of the character sequence, which I think would have introduced too 
   *                  much bloat into the function. It may be (objectively) better to assign 0 to the variables referenced
   *                  by stringSizeOne and stringSizeTwo, more research should be conducted on this.
   *
   * Precondition(s): For an accurate size, the variables referenced by stringSizeOne and stringSizeTwo must be initialized
   *                  or assigned the value 0 before this function is called, or the caller cannot expect accurate results to
   *                  be stored in the referenced variables. This quirk may be made use of in a more meaningful way in the
   *                  future.
   *                  
   *                  Both metamorphicString and originalString must reference valid character sequences which are eventually
   *                  terminated by a '\0'.
   *             
   * Return type: void
   *
   * Parameter List:   int* - stringSizeOne
   *                   int* - stringSizeTwo
   *                   const unsigned char* - metamorphicString
   *                   const unsigned char* - originalString
   -----------------------------------------------------------------------------------------------------------------
*/
void getStringSize(int* stringSizeOne, int* stringSizeTwo, const unsigned char* metamorphicString, const unsigned char* originalString){
	bool baseProgress = true, changeProgress = true;

   //Make sure either the original or changing string has not reached the null terminator character, and increment the 
   //appropriate counter.
	while((baseProgress != false) || (changeProgress != false)){
		(metamorphicString[*stringSizeOne] != '\0') ? (*stringSizeOne)++ : changeProgress = false; 
		(originalString[*stringSizeTwo] != '\0') ?  (*stringSizeTwo)++ : baseProgress = false;
        
        //Obviously for debugging purposes, report the size each string as the loop continues.
        #if DEBUG
		   fprintf(stderr, "The size of baseStringSize is: %d\r\n", *stringSizeTwo);
		   fprintf(stderr, "The size of changeStringSize is: %d\r\n", *stringSizeOne);
        #endif
	}

   //Get user confirmation.
    #if DEBUG
	   PROVE_CONFIRMATION();
    #endif
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/18/2018
   *
   * Function Name: buildLegend(legendMap, legendSize, originalString, originalStringSize)
   * Description: This function takes a string and a 'legend map' (which is really just a pointer to an unsigned char) and
   *              assigns whatever memory that pointer points to with characters pointed to by another unsigned char*
   *              (original string). It ensures that no duplicate characters transferred from the originalString character
   *              sequence are included in the map. (i.e. The map contains exactly one instance of each character found in
   *              originalString)
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function really strikes home how much more organized things would be if I were to attach sizes to 
   *                  unsigned char*'s using structs. This function could be reduced by two parameters. I'll have to do testing
   *                  on that approach later.
   *                     -DESIGN FLAW: Even if the legend is completely full, it continues to pointlessly execute. This causes 
   *                                   crippling runtimes for very large character sequences (~20+ hours given the maximum sized
   *                                   input buffer and a fully loaded legend on my 3.9GHz CPU, assuming no other cores are used.)
   *                        -If a sequence of characters in memory is mostly redundant, the function may still exhibit the behavior described
   *                         above, as the legend never gets full rather than being pointlessly full. One such solution would be to use an algorithm
   *                         to scan the string for a unique number of characters in originalString, but then one might ask why we wouldn't solve the 
   *                         problem there instead of here?
   *                     -This function is used in the implementation of squeeze() and any().
   *
   * Precondition(s): originalString must point to a valid sequence of characters, terminated by the '\0', or undefined
   *                  behavior will result. originalStringSize must accurately reflect the size of originalString (total size of
   *                  memory sequence, in sizeof(char)-sized chunks. legendMap must be as large as legendSize dictates, and terminated
   *                  by a '\0', or undefined behavior will occur.
   *
   * Return type: void
   *
   * Parameter List:   unsigned char* - legendMap
   *                   const int - legendSize
   *                   const unsigned char* - originalString
   *                   const int - originalStringSize
   -----------------------------------------------------------------------------------------------------------------
*/
void buildLegend(unsigned char* legendMap, const int legendSize, const unsigned char* originalString, const int originalStringSize){

	int legendIndex = 0;
	int stringIndex = 0;

	//Populate our legend with unique characters from the base String.
	for(; (legendIndex < legendSize) && (stringIndex < originalStringSize); stringIndex++, legendIndex++){
		 
        #if DEBUG
		   fprintf(stderr, "The character in the legend at index %d is: '%c'\r\n", legendIndex, legendMap[legendIndex]);
		   fprintf(stderr, "The character in the original string at index %d is: '%c'\r\n", stringIndex, originalString[stringIndex]);
        #endif
		legendMap[legendIndex] = originalString[stringIndex];

        #if DEBUG
		   fprintf(stderr, "The character in the legend at index %d after transfer is: '%c'\r\n", legendIndex, legendMap[legendIndex]);
        #endif


      //TODO: Test the following sentinel check using max parameters for legend and originalStringSize, do it in such a way that it 
      //      doesn't cause a segmentation fault.

      //if(!(~legendSize)) return;
		int sentinelIndex = 0;

      //Check to make sure the newest addition isn't already in the array, if it is, overwrite it with a '\0'.
		for(; sentinelIndex < legendIndex; sentinelIndex++){
			if(legendMap[sentinelIndex] == legendMap[legendIndex]){
				legendMap[legendIndex] = '\0';

				//Copmensate for the loop incrementing this variable when we don't want it to increment.
				legendIndex--;
			}  
		}
	}

    #if DEBUG
	   fprintf(stderr, "The legend array's contents are: %s\r\n", legendMap);
	   PROVE_CONFIRMATION();
    #endif
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/18/2018
   *
   * Function Name: transformString(legendMap, legendSize, metamorphicString, metamorphicStringSize)
   * Description: This function takes a legend and uses it as a reference to find characters contained mutually in legendMap
   *              and metamorphicString. Upon finding such a match, the offending character is overwritten with a '\0' character
   *              in metamorphicString. Secondly, the function takes characters in metamorphicString that are not found in the
   *              legend and places them in a consecutive fashion nearest to the beginning of metamorphicString as possible. It 
   *              inserts a trailing '\0' for good measure.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function may be bugged, as squeeze() does not give correct output if a '-' character is used in the metamorphic string.
   *                  (it is missing when it should be present). More testing of all functions used in that exercise may be necessary. As noted previously,
   *                  this function would benefit from using a simple struct to keep track of the stringSize using a counter.
   *                     -This function is used in the implementation of squeeze().
   *
   * Precondition(s): metamorphicString must point to a valid sequence of characters, or undefined behavior will result. 
   *                  metamorphicStringSize must accurately reflect the size of metamorphicString (total size of
   *                  memory sequence, in sizeof(char)-sized chunks. legendMap must be as large as legendSize dictates, and terminated
   *                  by a '\0', or undefined behavior will occur.
   *
   * Return type: void
   *
   * Parameter List:   const unsigned char* - legendMap
   *                   const int - legendSize
   *                   unsigned char* - metamorphicString
   *                   const int - metamorphicStringSize
   -----------------------------------------------------------------------------------------------------------------
*/
void transformString(const unsigned char* legendMap, const int legendSize, unsigned char* metamorphicString, const int metamorphicStringSize){

	//Local Variables for use in the loop.
	int legendIndex = 0, stringIndex = 0;

	//Local variables for controlling array indicies.
    int changeOffset = 0, totalOffset = 0;

	//Delete characters found in the changeString that are also in the baseString.
	for(legendIndex = 0; legendIndex < legendSize; legendIndex++){
		for(stringIndex = 0; stringIndex < metamorphicStringSize;){

            #if DEBUG
			   fprintf(stderr, "The value of stringIndex + changeOffset is equal to: %d\r\n\tThe stringIndex is: %d\r\n", (stringIndex + changeOffset), stringIndex);
			   fprintf(stderr, "The contents of changeString are: %s\r\n", metamorphicString);
            #endif

			//If you find a character in the string to be changed that matches a character in the legend, assign '\0' to it and increment a counter.
			if(legendMap[legendIndex] == metamorphicString[stringIndex]){ 
				metamorphicString[stringIndex] = '\0';
				changeOffset++;
			}
			stringIndex++;
		}
	}

	//Reconstruct the string
	stringIndex = 0;
	int nullDelim = 0;

	while(stringIndex < metamorphicStringSize)
	{
	   if(metamorphicString[stringIndex] == '\0') nullDelim++;
	   else {
           #if DEBUG
		      fprintf(stderr, "Valid character found: %c\r\n", metamorphicString[stringIndex]);
           #endif
		   
		   //Transfer the valid character next to the other valid characters in the sequence.
		   //If it is the first, put it at the beginning of the string.
           metamorphicString[stringIndex - nullDelim] = metamorphicString[stringIndex];
		   if(nullDelim > 0)
		      metamorphicString[stringIndex] = '\0';

	   }
	   stringIndex++;
	}
    #if DEBUG
	   fprintf(stderr, "The character in changeString[changeStringSize - totalOffset] is: %c\r\n\tIf you see a relevant character, it has been overwritten, check contents.", metamorphicString[metamorphicStringSize - changeOffset]);
    #endif
	metamorphicString[metamorphicStringSize - changeOffset] = '\0';
    
    #if DEBUG
	   fprintf(stderr, "The contents of changeString are: %s\r\n", metamorphicString);
	   PROVE_CONFIRMATION();
    #endif

}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/18/2018
   *
   * Function Name: reportStringPos(legendMap, legendSize, searchString, searchStringSize)
   * Description: A simple helper function that reports the position of the first character found in searchString that is present in the legend.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function was used primarily to increase the simplicity of implementing the any() function, which otherwise would have looked
   *                  unnecessarily crowded.
   *                     -This function is used in the implementation of any().
   *
   * Precondition(s): searchString must point to a valid sequence of characters, or undefined behavior will result. 
   *                  searchStringSize must accurately reflect the size of searchString (total size of
   *                  memory sequence, in sizeof(char)-sized chunks). legendMap must be as large as legendSize dictates, and terminated
   *                  by a '\0', or undefined behavior will occur.
   *
   * Return type: void
   *
   * Parameter List:   const unsigned char* - legendMap
   *                   const unsigned char - legendSize
   *                   const unsigned char* - searchString
   *                   const unsigned char - searchSStringSize
   -----------------------------------------------------------------------------------------------------------------
*/
int reportStringPos(const unsigned char* legendMap, const unsigned char legendSize, const unsigned char* searchString, const unsigned char searchStringSize){

	//Local Variables for use in the loop.
	unsigned char legendIndex = 0, stringIndex = 0;

	//Local variables for controlling array indicies.
    unsigned char changeOffset = 0, totalOffset = 0;

	for(legendIndex = 0; legendIndex < legendSize; legendIndex++){
		for(stringIndex = 0; stringIndex < searchStringSize;){

			//If you find a character in the string to be searched that matches a character in the legend, return the position of that character.
			if(legendMap[legendIndex] == searchString[stringIndex]){ 
				return stringIndex;
			}
			stringIndex++;
		}
	}
	return -1;
}

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/18/2018
   *
   * Function Name: setbits(targetNumber, targetBitPosition, bitFieldWidth, sourceNumber)
   * Description: This function takes the nth bit defined by targetBitPosition, including the bits between n and n + i (exclusive) 
   *              of targetNumber (i being defined by bitFieldWidth), modifying their contents to match the rightmost i bits of 
   *              sourceNumber, leaving the other bits of targetNumber unchanged.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function was a major pain to implement, but rewarding in its own right.
   *                  I could probably tweak the function to use a const return type and certain const parameters.
   * 
   *
   * Precondition(s): Simply ensure any numbers entered as inputs do not cause arithmetic overflows.
   *
   * Return type: int
   *
   * Parameter List:   int - targetNumber
   *                   char - targetBitPosition
   *                   char - bitFieldWidth
   *                   int - sourceNumber
   -----------------------------------------------------------------------------------------------------------------
*/
 int setbits(int targetNumber, char targetBitPosition, char bitFieldWidth, int sourceNumber){

	 int sourceBitField;
    long int sourceBitFieldValue;
	 char targetBitPosIndex = 0;
	 {
	    //Make a bitmask that is 0bjjjjjjxxxx, where the number of x's corresonds to the bitFieldWidth. j's := 0 and x's := 1;
	    int bitFieldPlaceHolder = initializeBitField(&bitFieldWidth);

	    //Get the rightmost # of bits from our sourceNumber.
	    sourceBitField = (sourceNumber & bitFieldPlaceHolder);
	 }
  
	 int sourceBitAddition = sourceBitField << targetBitPosition;

    int targetNumberDeficit = targetNumber;
    targetNumberDeficit = (targetNumberDeficit >> targetBitPosition) & initializeBitField(&bitFieldWidth);
    targetNumberDeficit = targetNumberDeficit << targetBitPosition;

    return targetNumber - targetNumberDeficit + sourceBitAddition;
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name: invert(targetNumber, targetBitPosition, bitFieldWidth)
   * Description: This function takes the nth bit defined by targetBitPosition, including the bits between n and n + i (exclusive) 
   *              of targetNumber (i being defined by bitFieldWidth), and inverts their contents, leaving the other bits unchanged.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function was much easier to implement then setbits, and I discovered an elegant solution.
   * 
   *
   * Precondition(s): Simply ensure any numbers entered as inputs do not cause arithmetic overflows.
   *
   * Return type: int
   *
   * Parameter List:   int - targetNumber
   *                   const char - targetBitPosition
   *                   const char - bitFieldWidth
   -----------------------------------------------------------------------------------------------------------------
*/
 int invert(int targetNumber, const char targetBitPosition, const char bitFieldWidth){

    int targetNumberMask = initializeBitField(&bitFieldWidth) << targetBitPosition;
    return targetNumber ^ targetNumberMask;  
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  rightrot(targetValue, rotateNumber)
   * Description: This function takes the value designated by targetValue and performs n right-shifts, preserving 
   *              any values that are shifted from the least significant bit. This value in question is then
   *              transferred to the most significant bit.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): Code may have minor redundancies or inefficiencies, need to investigate.
   * 
   *
   * Precondition(s): Simply ensure any numbers entered as inputs do not cause arithmetic overflows.
   *
   * Return type: int
   *
   * Parameter List:   int - targetValue
   *                   const char - rotateNumber
   -----------------------------------------------------------------------------------------------------------------
*/
 int rightrot(int targetValue, const char rotateNumber){
    
    int index = 0;
    for(; index < rotateNumber; index++){
       if((targetValue & 1) == 1){
          targetValue = (targetValue >> 1) | (1 << ((sizeof(int) * 8) - 1));
          continue;
       } 
       //I think this is unnecessary, will test with alternative later.
       char bitField = (sizeof(int) * 8) - 1;
       targetValue = (targetValue >> 1) & initializeBitField(&bitField);

       //Potential Alternative:
          //targetValue = targetValue >> 1;
    }
    return targetValue;
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  bitcount(targetValue)
   * Description: This function takes a value specified by targetValue and counts the number of bits that are equal
   *              to 1.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function was used in an exercise that challenged the programmer to create a more efficient 
   *                  version of bitcount than the one provided by K&R. As a result, I threw around inline and volatile
   *                  as much as possible so I could disable compiler optimization for arguments but squeeze as much
   *                  performance as I could out of the function. All this came about because of some (as of yet) 
   *                  misunderstood behavior that the VS compiler exhibits (the first function called of the two is 3 to 4
   *                  times more inefficient than it normally would be than if it was the second function called). I noted
   *                  this behavior in both functions.
   *
   * Precondition(s): Simply ensure that any the value passed for targetValue is within the range specified by
   *                  unsigned int.
   *
   * Return type: inline volatile int
   *
   * Parameter List:   volatile unsigned int - targetValue
   -----------------------------------------------------------------------------------------------------------------
*/
inline volatile int bitcount(volatile unsigned int targetValue){
    volatile int numberOfBits = (targetValue | 0) ? 1 : 0; 
    
    for(; targetValue &= (targetValue - 1); ++numberOfBits);

    return numberOfBits;
 }


/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  bitCountOriginal(x)
   * Description: This function takes a value specified by targetValue and counts the number of bits that are equal
   *              to 1.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function is provided in K&R, page 50.
   *
   * Precondition(s): Simply ensure that any the value passed for 'targetValue' is within the range specified by
   *                  unsigned int.
   *
   * Return type: volatile int
   *
   * Parameter List:   volatile unsigned int - x
   -----------------------------------------------------------------------------------------------------------------
*/
 //Ripped straight from K & R, page 50.
 volatile int bitCountOriginal(volatile unsigned int x){
    volatile int b;

    for(b = 0; x != 0; x >>= 1)
       if (x & 01)
          b++;
    return b;
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  newLower(letter)
   * Description: This function is an alternate take on the function lower(), which takes any upper-case letter of the
   *              ASCII character set and converts it to a lower-case letter.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function ONLY works with the ASCII character set or character sets that just happen to have
   *                  the same offsets between upper and lower case letters of the English alphabet. The alternate 
   *                  character set in question must also only have 2^(sizeof(char)) unique values that are mapped to
   *                  those bits.
   *
   * Precondition(s): Simply ensure that any the value passed for targetValue is within the range specified by
   *                  char.
   *
   * Return type: const char
   *
   * Parameter List:   const char - letter
   -----------------------------------------------------------------------------------------------------------------
*/
 const char newLower(const char letter){
    if(letter < 'A' || letter > 'z' || (letter > 'Z' && letter < 'a')){
       USER_PROMPT("Letter provided to newLower function is not a valid character in the alphabet.");
       return '\0';
    }
    return (letter >= 'A' && letter <= 'Z') ? letter + ('a' - 'A') : letter;

/* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  initializeBitField(bitFieldWidth)
   * Description: This is a helper function which initializes an n number of bits to 1 (where n is the value denoted by 
   *              bitFieldWidth), starting from the least significant bit and terminating at the most significant bit. 
   *              If the number specified is less than the number of bits present in an int type, the remaining bits are 0.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): This function returns 1 even if a non-positive number is specified: [-128, 0], which is obviously
   *                  undesired behavior. The const char* should probably be changed to a const unsigned char*.
   *
   * Precondition(s): Simply ensure that any the value passed for targetValue is within the range specified by
   *                  char.
   *
   * Return type: int
   *
   * Parameter List:   const char const* - bitFieldWidth
   -----------------------------------------------------------------------------------------------------------------
*/
 }
 int initializeBitField(const char const *bitFieldWidth){

	 char bitFieldIndex = 1;
	 int bitFieldPlaceHolder = 1;

	 for(bitFieldIndex; bitFieldIndex < *bitFieldWidth; bitFieldIndex++){
		 
          bitFieldPlaceHolder = bitFieldPlaceHolder << 1;
          bitFieldPlaceHolder |= 1;
	 }

	 return bitFieldPlaceHolder;
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  waitForValidInput(userInputField, minInputWidth, maxInputWidth)
   * Description: A helper function meant to handle some of the text-based UI details, and to simplify the look of my code.
   *              In reality, an unpleasant waste of disk space.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): For unknown reasons, this function doesn't work correctly, although countless others just like it work fine.
   *                  Probably due to an oversight caused by a lethal combination of sleep deprivation and a caffeine overdose.  
   *
   * Precondition(s): userInputField[] must point to a valid consecutive sequence of characters, terminated by the '\0' character.
   *                  minInputWidth must specify the minimum number of characters to be entered, if this number is not accurate the 
   *                  function will initiate a recursive call to reprompt the user for correct input. If however, this number is faulty,
   *                  the recursive call will pass the faulty number to its parameter list, and the user will be left in a frustrated state.
   *                  maxInputWidth must specify a number that is big enough to handle the largest valid input a user can pass in any given
   *                  context + 1 (for the null terminator character) failure to specify a large enough value means the user will not have 
   *                  enough room in the buffer to store input.
   *
   * Return type: void
   *
   * Parameter List:   char[] - userInputField
   *                   const char - minInputWidth
   *                   const char - maxInputWidth
   -----------------------------------------------------------------------------------------------------------------
*/
 void waitForValidInput(char userInputField[], const char minInputWidth, const char maxInputWidth){

    if((maxInputWidth < minInputWidth) || maxInputWidth < 1){
       USER_PROMPT("waitForValidInput recieved an error!\r\n\tEither:\r\n\t\t-maxInputWidth was 0 or a negative number.\r\n\t\t-maxInputWidth was smaller than minInputWidth.\r\n");
       return;
    }
	
    userInputField[maxInputWidth] = '\0';

	//Put a null-terminator character here so we don't read garbage during the message.
	userInputField[0] = '\0';

	//Creating local variables to store the characters given by the user.
	unsigned char temp;
	unsigned char index = 0;
    
	while(index < maxInputWidth, (temp = getchar()) != '\n'){
		if((temp == BACKSPACE) && index > 0){
			userInputField[index--] = '\0';
         if(DEBUG)
            USER_PROMPT("You pressed backspace.");
			continue;
		}
		userInputField[index++] = temp;
		userInputField[index] = '\0';

      if(DEBUG){
         USER_PROMPT(userInputField);
         USER_PROMPT("You pressed a key, dude.");
      }
	}

   if(index < minInputWidth){
      USER_PROMPT("Your entry did not include enough characters. Please retry.")
      waitForValidInput(userInputField, minInputWidth, maxInputWidth);
   }
   

 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  chooseBase()
   * Description: A helper function meant to determine the reference base system to used as a means to interpret user input.
   *              Unfortunately, this function isn't utilized anywhere, due to its association with the waitForValidInput() function.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): While I believe this function works correctly, the code this function is associated with does not. So I can't 
   *                  properly test it.
   *
   * Precondition(s): This function forces the user to input text, so be ready to halt everything else until the interaction required
   *                  by this function is satisfied.
   *
   * Return type: int
   *
   * Parameter List:   N/A
   -----------------------------------------------------------------------------------------------------------------
*/
 int chooseBase(void){

    USER_PROMPT("Choose which base you would like to use:\r\n");
    USER_PROMPT("\t1) Binary\r\n");
    USER_PROMPT("\t2) Decimal\r\n");
    USER_PROMPT("\t3) Hexadecimal\r\n");

    USER_PROMPT("Simply select a number on your keyboard.\r\n");
    char c;
    while(c = getchar(), (c >= '1') && (c <= '3'), c != '\n'){ 

       switch(c){
          case '1': return BINARY;
          case '2': return DECIMAL;
          case '3': return HEXIDECIMAL;
          default : USER_PROMPT("You entered an invalid input, please try again.\r\n\r\n")
                    chooseBase();
       }
    }
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   *
   * Function Name:  initializeBuffer()
   * Description: Takes a given buffer pointed to by a constant char pointer, incrementing an offset size number of times.
   *              Before the offset is incremented, the memory dereferenced by the offset is assigned to '\0'.
   *
   * Problem Statement Code: N/A
   *                          
   * Observations(s): N/A
   *
   * Precondition(s): One must make sure that size accurately reflects the size of the buffer that the programmer wants to
   *                  use for any purpose (as one could imagine, this function was designed with user input in mind). Or the
   *                  buffer will still contain garbage.
   *
   * Return type: void
   *
   * Parameter List:   char* const - buffer
   *                   const int - size
   -----------------------------------------------------------------------------------------------------------------
*/
 void initializeBuffer(char *const buffer, const int size){
    int index = 0;

    while(index < size) buffer[index++] = '\0';
 }

 /* -----------------------------------------------------------------------------------------------------------------
   * Date: 4/19/2018
   * Credits: StackOverflow
   *                  -User: Mysticial
   *                  -URL: https://stackoverflow.com/questions/13772567/get-cpu-cycle-count
   *
   * Function Name: returnProcessorClock()
   * Description: A function graciously provided by Mystical, which returns the value of the system clock at any given time.
   * 
   * Problem Statement Code: N/A
   *                          
   * Observations(s): N/A
   *
   * Precondition(s): N/A
   *
   * Return type: uint64_t
   *
   * Parameter List:   N/A
    -----------------------------------------------------------------------------------------------------------------
 */
 uint64_t returnProcessorClock(void){
   return __rdtsc();
}