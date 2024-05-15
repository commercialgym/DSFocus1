/*
* FILE : f1.cpp
* PROJECT : SENG1050 - Focus Assignment #1
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 05/17/2024
* DESCRIPTION : Take info about flights and stores the destination and date in an array
* of structs which are later displayed. Use dynamic memory allocation to store the 
* strings in the struct.
	*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)

#define MAX_CHARS 31
#define SIZEOF_ARRAY 10
//STRUCT
typedef struct
{
	//ensure this is proper way to "know how long each string is" struct requirements
	//since error checking is required i may have to use malloc elsewhere for these pointers?
	//error that compiler was giving me made me realize that i must use malloc elsewhere so that i can also
	//error check for them
	char* pFlightDest;
	char* pFlightDate;

}FlightInfo;

int fillFlightInfo(FlightInfo*, char*, char*);
int printFlightInfo(FlightInfo[]);
int removeNewline(char[]);

int main()
{

	FlightInfo singleFlight[SIZEOF_ARRAY];

	//INPUT
	//prompt user to get input (printf "enter destination #[%d]", i+1) and then (printf "enter
	// date of flight #[%d], i+1)
    //stdin 10 pairs of c-style string
	//the two strings are entered on two separate lines (20 inputs total?)
	//remove newline and replace with null terminated?
	//input string less than 30 characters long

	//use for loop to take in input using the SIZEOF_ARR in condition
	//within one iteration of the for loop:
	// prompt user
	// take stdin for destination and store in a temporary char pointer
	// prompt user again 
	// take stdin for date and store in a temporary char pointer
	// create a pointer of flightInfo which I THINK should point to the current index of flightInfo variable array
	// call fillFlightInfo(flightInfo* pointAtArr, temp dest, temp date)


	for (int i = 0; i < SIZEOF_ARRAY; i++)
	{
		char destinationBuffer[MAX_CHARS] = { 0 };
		char dateBuffer[MAX_CHARS] = { 0 };
		char* pInputDest = NULL;
		char* pDateInput = NULL;

		printf("Please enter the destination of flight #%d: ", i + 1);
		pInputDest = fgets(destinationBuffer, MAX_CHARS, stdin);

		removeNewline(destinationBuffer);

		printf("Please enter the date of flight #%d: ", i + 1);
		pDateInput = fgets(dateBuffer, MAX_CHARS, stdin);

		removeNewline(dateBuffer);

		FlightInfo* pCurrentFlight = &singleFlight[i];

		//could also put in the pointers used after fgets
		fillFlightInfo(pCurrentFlight, destinationBuffer, dateBuffer);

		//removeNewline(pInputDest);

		//printf("%s and %s", destinationBuffer, dateBuffer);

		//printf("%s", pInputDest);

		printf("%s working and %s", singleFlight[i].pFlightDest, singleFlight[i].pFlightDate);

		printf("hello");

	}



	//must free ALL memory allocated from using malloc() here at the end of main

	return 0;
}

//FUNCTION: fillFlightInfo()
//DESCRIPTION: fills the fields of the struct. must allocate two blocks of memory to 
// contain the destination string and date string. called once for each flight (dest/date pair)
//PARAMETERS: pointer to struct, pointer to char (struct field for destination), pointer to char
// (struct field for date)
//RETURNS: TBD
int fillFlightInfo(FlightInfo* pCurrentFlight, char* pInputDest, char* pInputDate)
{
	//MUST allocate two blocks of memory to contain the destination string and date string
	//think about creating a variable to get rid of magic numbers
	if (( pCurrentFlight->pFlightDest = (char*)malloc(MAX_CHARS + 1)) == NULL)
	{
		printf("Error alloting space for flight destination field\n");
		return -1;
	}

	if ((pCurrentFlight->pFlightDate = (char*)malloc(MAX_CHARS + 1)) == NULL)
	{
		printf("Error alloting space for flight date field\n");
		return -1;
	}
	//parse the flight info here?/remove newline
	//note to self: dereference the pFlightData here?

	strcpy(pCurrentFlight->pFlightDest, pInputDest);
	
	strcpy(pCurrentFlight->pFlightDate, pInputDate);

	//printf("%s and %s", pFlightData->pFlightDest, pFlightData->pFlightDate);
	

	return 0;
}


//FUNCTION: printFlightInfo()
//DESCRIPTION: Called only once from main and prints all the info within the array of struct in a nicely-
// formatted way, one flight per line. 
//PARAMETERS: array of (struct) datatype FlightInfo
//RETURNS: TBD
int printFlightInfo(FlightInfo[])
{
	//destination displayed in the first 35 characters of the line (left justified)
	//date displayed in next 35 characters of the line (left justified)
	//so this means that there may be a gap between these two?^^
	//use printf width specifiers

	//use a for loop to iterate through the array
	//use SIZEOF_ARRAY in condition

	return 0;
}


// FUNCTION: removeNewline()
// DESCRIPTION: accesses the last index of the inputted char array 
// and checks for newline and replaces it will null terminator. 
// PARAMETERS: char inputBuffer[], the char array of user's input
// RETURNS: TBD / 0 upon success
int removeNewline(char inputBuffer[])
{
	size_t length = strlen(inputBuffer);

	//use the length (of string) - 1 to index the last element of the string
	if (inputBuffer[length - 1] == '\n')
	{
		inputBuffer[length - 1] = '\0';
	}
	return 0;
}