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
	char* pDestination = (char*)malloc(MAX_CHARS);
	char* pDate = (char*)malloc(MAX_CHARS);

}FlightInfo;

int fillFlightInfo(FlightInfo*, char*, char*);
int printFlightInfo(FlightInfo[]);

int main()
{
	//INPUT
	//prompt user to get input (printf "enter destination #[%d]", i+1) and then (printf "enter
	// date of flight #[%d], i+1)
    //stdin 10 pairs of c-style string
	//the two strings are entered on two separate lines (20 inputs total?)
	//remove newline and replace with null terminated?
	//input string less than 30 characters long

	FlightInfo singleFlight[SIZEOF_ARRAY];


	//must free ALL memory allocated from using malloc() here at the end of main

	return 0;
}

//FUNCTION: fillFlightInfo()
//DESCRIPTION: fills the fields of the struct. must allocate two blocks of memory to 
// contain the destination string and date string. called once for each flight (dest/date pair)
//PARAMETERS: pointer to struct, pointer to char (struct field for destination), pointer to char
// (struct field for date)
//RETURNS: TBD
int fillFlightInfo(FlightInfo* pFlightData, char* pFlightDest, char* pFlightDate)
{
	//MUST allocate two blocks of memory to contain the destination string and date string
	//parse the flight info here?

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