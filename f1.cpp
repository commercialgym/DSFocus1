/*
* FILE : f1.cpp
* PROJECT : SENG1050 - Focus Assignment #1
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 05/17/2024
* DESCRIPTION : Takes info from stdin about 10 flights and stores the destination and 
* date in an array of structs which are later displayed in a properly formatted manor. 
* Uses dynamic memory allocation to store the strings in the struct.
	*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable: 4996)

#define MAX_CHARS 31
#define SIZEOF_ARRAY 10

typedef struct
{
	char* pFlightDest;
	char* pFlightDate;

}FlightInfo;

//functions that deal with struct
int fillFlightInfo(FlightInfo*, char*, char*);
void printFlightInfo(FlightInfo[]);
//function that improves syntax
void removeNewline(char[]);

int main()
{
	//will hold user's input
	FlightInfo flightList[SIZEOF_ARRAY] = {0};

	for (int i = 0; i < SIZEOF_ARRAY; i++)
	{
		char destinationBuffer[MAX_CHARS] = { 0 };
		char dateBuffer[MAX_CHARS] = { 0 };

		printf("Please enter the destination of flight #%d: ", i + 1);
		fgets(destinationBuffer, MAX_CHARS, stdin);
		removeNewline(destinationBuffer);

		printf("Please enter the date of flight #%d: ", i + 1);
		fgets(dateBuffer, MAX_CHARS, stdin);
		removeNewline(dateBuffer);

		FlightInfo* pCurrentFlight = &flightList[i];

		//could also put in the pointers used after fgets
		fillFlightInfo(pCurrentFlight, destinationBuffer, dateBuffer);
	}

	printFlightInfo(flightList);

	//have to iterate through entire array to free the memory
	for (int i = 0; i < SIZEOF_ARRAY; i++)
	{
		free(flightList[i].pFlightDest);
		free(flightList[i].pFlightDate);
	}

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
	//+1 is for allocating one more byte of space for null terminator
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
	//add the data to the struct field
	strcpy(pCurrentFlight->pFlightDest, pInputDest);
	strcpy(pCurrentFlight->pFlightDate, pInputDate);

	return 0;
}


//FUNCTION: printFlightInfo()
//DESCRIPTION: Called only once from main and prints all the info within the array of struct in a nicely-
// formatted way, one flight per line. 
//PARAMETERS: flightPairs[], array of (struct) datatype FlightInfo
//RETURNS: void
void printFlightInfo(FlightInfo flightPairs[])
{
	//destination displayed in the first 35 characters of the line (left justified)
	//date displayed in next 35 characters of the line (left justified)
	//so this means that there may be a gap between these two?^^
	//use printf width specifiers


	printf("Here is a list of all %d flight datasets you entered\n", SIZEOF_ARRAY);

	for (int i = 0; i < SIZEOF_ARRAY; i++)
	{
		printf("%-35s %-35s\n", flightPairs->pFlightDest, flightPairs->pFlightDate);
	}
}


// FUNCTION: removeNewline()
// DESCRIPTION: accesses the last index of the inputted char array 
// and checks for newline and replaces it will null terminator. 
// PARAMETERS: char inputBuffer[], the char array of user's input
// RETURNS: void
void removeNewline(char inputBuffer[])
{
	size_t length = strlen(inputBuffer);

	//use the length (of string) - 1 to index the last element of the string
	if (inputBuffer[length - 1] == '\n')
	{
		inputBuffer[length - 1] = '\0';
	}
}