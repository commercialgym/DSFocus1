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
//STRUCT
typedef struct
{
	//ensure this is proper way to "know how long each string is" struct requirements
	char* pDestination = (char*)malloc(MAX_CHARS);
	char* pDate = (char*)malloc(MAX_CHARS);

}FightInfo;

int main()
{
	//INPUT
	//prompt user to get input (printf "enter destination #[%d]", i+1) and then (printf "enter
	// date of flight #[%d], i+1)
    //stdin 10 pairs of c-style string
	//the two strings are entered on two separate lines (20 inputs total?)
	//remove newline and replace with null terminated?
	//input string less than 30 characters long


	return 0;
}


