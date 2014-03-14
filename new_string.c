#include <stddef.h>
#include <stdio.h>

#include "new_string.h"

char* new_strcpy(char* destination, const char* source)
{
	int i;
	for(i = 0; source[i]; ++i)
		destination[i] = source[i];
	destination[i] = '\0';
	return destination;
}

char* new_strncpy(char* destination, const char* source, size_t n)
{
	size_t i;
	for (i = 0; i < n && source[i] != '\0'; i++)
		destination[i] = source[i];
	for ( ; i < n; i++)
		destination[i] = '\0';
	return destination;
}

int new_strcmp(const char* string1, const char* string2)
{
	return 0;
}

int new_strncmp(const char* string1, const char* string2, size_t n)
{
	return 0;
}

char* new_strcat(char* destination, const char* source)
{
	return 0;
}

char* new_strncat(char* destination, const char* source, size_t n)
{
	return 0;
}

size_t new_strlen(const char* string)
{
	return 0;
}

char* new_strchr(const char* string, int character)
{
	return 0;
}

char* new_strstr(const char* haystack, const char* needle)
{
	return 0;
}