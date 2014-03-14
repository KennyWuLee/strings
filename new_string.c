 /*******************************/
 /*
 /*  Project Name: String 'Em Up
 /*  Description: implementations of string library functions
 /*  File names: new_string.c new_sring.h makefile
 /*  Date: March, 14, 2014 
 /*  Authors: Timothy Miranda, Till Krischer
 /*
 /*******************************/

#include <stddef.h>
#include <stdio.h>
#include "new_string.h"

/* 
       Description: Copies the characters from source into destination.  
					
       Parameters:  destination  -  as a char pointer
                    source       -  as a char pointer
					
       Returns:	    pointer to destination
*/ 
char* new_strcpy(char* destination, const char* source)
{
	int i;
	//loop through the souce
	for(i = 0; source[i]; ++i)
		//copy char from source to destination
		destination[i] = source[i]; 
	//append null character to destination
	destination[i] = '\0';
	return destination;
}

/* 
       Description: Copies the first n characters from source into destination. If the function hits a null character in source before it has copied n characters, the remaining characters are filled with null characters. 
					
       Parameters:  destination  -  as a char pointer
                    source       -  as a char pointer
					n            -  character-limit as int
					
       Returns:	    pointer to destination
*/ 
char* new_strncpy(char* destination, const char* source, size_t n)
{
	size_t i;
	//loop through source until end of source or until n-th character.
	for (i = 0; i < n && source[i] != '\0'; i++)
		//copy char from source to destination
		destination[i] = source[i];
	// if source length < n loop until n	
	for ( ; i < n; i++) 
		//fill rest of destination with null-characters
		destination[i] = '\0'; 
	return destination;
}

/* 
       Description: Compares two strings.
					
       Parameters:  string1  - as a char pointer
					string2  - as a char pointer
					
       Returns:	    The return value is positive if string1 comes after string2 alphabetically, negative if string1 comes before string2 alphabetically, and 0 if the two strings are equal. 
*/ 
int new_strcmp(const char* string1, const char* string2)
{
	int i = 0;
	int check = 1;
	while(check != 0)
	{
		if(string1[i] == '\0' && string2[i] == '\0') // if both strings finish here then they must be equal
		{
			return 0;
		}
		else if(string1[i] == '\0') // if string 1 finishes before string 2 than it is less than it 
		{
			return -1;
		}
		else if(string2[i] == '\0')// if string 2 finishes before string 1 than it is greater than it 
		{
			return 1;
		}
		else if(string1[i] - string2[i] < 0) //if the difference between characters is negative then string1 is less than string 2
		{
			return string1[i] - string2[i]; // returns a negative number
		}
		else if(string1[i] - string2[i] > 0)//if the difference between characters is positive then string1 is greater than string 2
		{
			return string1[i] - string2[i]; // returns a positive number
		}
		else // when string1[i] == string2[i]
		{
			i++; // increments i 
		}
		
	}
}

/* 
       Description: Compares two strings exactly like new_strcmp(), except comparing at most the first n characters. 
					
       Parameters:  string1  - as a char pointer
					string2  - as a char pointer
					n        - charater limit as int
					
       Returns:	   The return value is positive if string1 comes after string2 alphabetically, negative if string1 comes before string2 alphabetically, and 0 if the two strings are equal. 
*/ 
int new_strncmp(const char* string1, const char* string2, size_t n)
{
	int i = 0;
	while(i < n) // loops n times 
	{	
		if(string1[i] == '\0' && string2[i] == '\0') // if both strings finish here then they must be equal
		{
			return 0;
		}
		else if(string1[i] == '\0') // if string 1 finishes before string 2 than it is less than it 
		{
			return -1;
		}
		else if(string2[i] == '\0')// if string 2 finishes before string 1 than it is greater than it 
		{
			return 1;
		}
		else if(string1[i] - string2[i] < 0) //if the difference between characters is negative then string1 is less than string 2
		{
			return string1[i] - string2[i]; // returns a negative number
		}
		else if(string1[i] - string2[i] > 0)//if the difference between characters is positive then string1 is greater than string 2
		{
			return string1[i] - string2[i]; // returns a positive number
		}
		else // when string1[i] == string2[i]
		{
			i++; // increments i 
		}
	}
	return 0;
}

/* 
       Description: Adds the string contained in source to the end of the string contained in destination. The values in destination are modified, but a pointer to destination is also returned. 
					
       Parameters:  destination - as a char pointer
					source      - as a char pointer
					
       Returns:	    pointer to destination
*/ 
char* new_strcat(char* destination, const char* source)
{
	//length of destination
	size_t dest_len = new_strlen(destination);
	size_t i;

	//loop through source
	for (i = 0 ; source[i] != '\0' ; ++i) 
		//append i-th character of souce to destination
		destination[dest_len + i] = source[i];
	//append null character to destination
	destination[dest_len + i] = '\0';  

	return destination;
}

/* 
       Description: Adds the string contained in source to the end of the string contained in destination, but adding a maximum of n characters. 
					
       Parameters:  destination  -  as a char pointer
                    source       -  as a char pointer
					n            -  character-limit as int
					
       Returns:	    pointer to destination
*/ 
char* new_strncat(char* destination, const char* source, size_t n)
{
	//length of destination
	size_t dest_len = new_strlen(destination);
	size_t i;

	 //loop through source until end of souce or until n
	for (i = 0 ; i < n && source[i] != '\0' ; ++i)
		//append i-th character of souce to destination
		destination[dest_len + i] = source[i]; 
	//append null character to destination
	destination[dest_len + i] = '\0';  

    return destination;
}

/* 
       Description:  Returns the number of characters in string before the null character. 
					
       Parameters:  string  -  string to measure as ca poiner
					
       Returns:	   length of string as an int
*/ 
size_t new_strlen(const char* string)
{
	size_t i;

	//loop through string and increment i per character
	for(i = 0; string[i]; ++i); 

	return i;
}

/* 
       Description: Returns a pointer to the first occurrence of character (converted to a char) in string or a NULL pointer if character cannot be found. 
					
       Parameters:  string     - string to search in as char pointer
					character  - char to look for as char
                    
					
       Returns:	    pointer to first occurence of "character" in string, or null if character cannot be found 
*/ 
char* new_strchr(const char* string, int character)
{
	int i;
	//default return is NULL pointer
	char* ret = NULL; 
	//loop through string
	for(i = 0; string[i]; ++i) 
		//if i-th character in string is equal to "character" set return to its address.
		if(string[i] == character) 
			ret = &string[i];
	return ret;
}

/* 
       Description: Returns a pointer to the first occurrence of the string contained in needle in haystack or a NULL pointer if needle cannot be found. 
					
       Parameters:  haystack - string to search in as char pointer
					needle   - string to search for as char pointer
					
       Returns:	    pointer to first character of first occurence of needle, null-pointer is needle is not found.
*/ 
char* new_strstr(const char* haystack, const char* needle)
{
	int i = 0;
	int j = 0;
	int check = 1; // creates an int that will act as a boolean
	char* ret = NULL; // creates a pointer to return
	while(haystack[i] != '\0') 
	{
		if(haystack[i] == needle[0]) // checks to see if the current character of haystack is the same as the first character of needle
		{
			while(needle[j] != '\0' && check !=0) // loops through characters in needle until it ends or if check is set to 0
			{
				if(needle[j] != haystack[i+j]) // checks to see if the characters aren't the same
				{
					check = 0; // sets check to 0, ending the loop
				}
				j++; //increments j
			}
			if(check) // if check was never changed, then haystack contained needle
			{
				ret = &haystack[i]; // sets the return value to the first occurance of the string contained in needle in haystack
				return ret; // returns that value
			}
		}
		j=0; // resets j to 0
		i++; // increments i
	}
	return ret; // returns null pointer if needle cannot be found
}
