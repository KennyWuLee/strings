#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "new_string.h"

int test_strcpy(char* src, int log)
{
	char *return1, *return2;
	char dest1[20], dest2[20];

	return1 = strcpy(dest1, src);
	return2 = new_strcpy(dest2, src);

	if(log)
	{
		printf("strcpy:     src: %s dest: %s rtrn: %s\n", src, dest1, return1);
		printf("new_strcpy: src: %s dest: %s rtrn: %s\n", src, dest2, return2);
	}

	return strcmp(dest1, dest2)==0 && strcmp(return2, return2)==0;
}

int test_strncpy(char* src, int size, int log)
{
	char *return1, *return2;
	char dest2[20], dest1[20];

	return1 = strncpy(dest1, src, size);
	return2 = new_strncpy(dest2, src, size);

	if(log)
	{
		printf("strncpy:     src: %s dest: %s size: %d rtrn: %s\n",
				src, dest1, size, return1);
		printf("new_strncpy: src: %s dest: %s size: %d rtrn: %s\n",
				src, dest2, size, return2);
	}

	return  strncmp(dest1, dest2, size)==0 && strncmp(return2, return2, size)==0;
}

int test_strcmp(char* str1, char* str2, int log)
{
	char *src1, *src2, *dest1, *dest2;
	int return1, return2;

	src1 = src2 = str1;
	dest1 = dest2 = str2;

	return1 = strcmp(src1, dest1);
	return2 = new_strcmp(src2, dest2);

	if(log)
	{
		printf("strcmp:     str1: %s str2: %s rtrn: %d\n", src1, dest1, return1);
		printf("new_strcmp: str1: %s str2: %s rtrn: %d\n", src2, dest2, return2);
	}

	return strcmp(src1, src2)==0 && strcmp(dest1, dest2)==0 && (return1 == return2);
}

int test_strncmp(char* str1, char* str2, int size, int log)
{
	int return1, return2;

	return1 = strncmp(str1, str2, size);
	return2 = new_strncmp(str1, str2, size);

	if(log)
	{
		printf("strncmp:     str1: %s str2: %s size: %d rtrn: %d\n",
				str1, str2, size, return1);
		printf("new_strncmp: str1: %s str2: %s size: %d rtrn: %d\n",
				str1, str2, size, return2);
	}

	return (return1 == return2);
}

int test_strcat(char* src, char* dest, int log)
{
	char *return1, *return2;
	char dest1[20], dest2[20];

	strcpy(dest1, dest);
	strcpy(dest2, dest);

	return1 = strcat(dest1, src);
	return2 = new_strcat(dest2, src);

	if(log)
	{
		printf("strcat:     src: %s  dest: %s  return: %s\n", 
				src, dest1, return1);
		printf("new_strcat: src: %s  dest: %s  return: %s\n", 
				src, dest2, return2);
	}

	return strcmp(dest1, dest2)==0 && strcmp(return1, return2)==0;
}

int test_strlen(char* str, int log)
{
	int return1, return2;

	return1 = strlen(str);
	return2 = new_strlen(str);

	if(log)
	{
		printf("strlen:     str: %s  return: %d\n", 
				str, return1);
		printf("new_strlen: str: %s  return: %d\n", 
				str, return2);
	}

	return return1==return2;
}

int test_strncat(char* src, char* dest, int size, int log)
{
	char *return1, *return2;
	char dest1[20], dest2[20];

	strcpy(dest1, dest);
	strcpy(dest2, dest);

	return1 = strncat(dest1, src, size);
	return2 = new_strncat(dest2, src, size);

	if(log)
	{
		printf("strcat:     src: %s  dest: %s  size: %d return: %s\n", 
				src, dest1, size, return1);
		printf("new_strcat: src: %s  dest: %s  size: %d return: %s\n", 
				src, dest2, size, return2);
	}

	return strcmp(dest1, dest2)==0 && strcmp(return1, return2)==0;
}

int test_strchr(char* str, char c, int log)
{
	char *return1, *return2;

	return1 = strchr(str, c);
	return2 = new_strchr(str, c);

	if(log)
	{
		printf("strchr:     str: %s  c: %c  return: %p\n", 
				str, c, return1);
		printf("new_strchr: str: %s  c: %c  return: %p\n", 
				str, c, return2);
	}

	return return1==return2;
}

int test_strstr(char* str, char* needle, int log)
{
	char *return1, *return2;

	return1 = strstr(str, needle);
	return2 = new_strstr(str, needle);

	if(log)
	{
		printf("strstr:     str: %s  needle: %s  return: %p\n", 
				str, needle, return1);
		printf("new_strstr: str: %s  needle: %s  return: %p\n", 
				str, needle, return2);
	}

	return return1==return2;
}

int main()
{
	//strcpy
	printf("%d\n", test_strcpy("hello", 0));

	//strncpy
	printf("%d\n", test_strncpy("hellohellohello", 7, 0));
	printf("%d\n", test_strncpy("hello", 7, 0));
	printf("%d\n", test_strncpy("hellohello", 10, 0));

	//strcmp
	printf("%d\n", test_strcmp("aaa", "arc", 0));
	printf("%d\n", test_strcmp("abc", "abc", 0));
	printf("%d\n", test_strcmp("ccc", "abc", 0));

	//strncmp
	printf("%d\n", test_strncmp("aaaddd", "alcccc", 3, 0));
	printf("%d\n", test_strncmp("abcddd", "abcccc", 3, 0));
	printf("%d\n", test_strncmp("cccddd", "abcccc", 3, 0));

	//strcat
	printf("%d\n", test_strcat("world", "hello", 0));
	printf("%d\n", test_strcat("fg", "", 0));
	printf("%d\n", test_strcat("", "hello", 0));

	//strncat
	printf("%d\n", test_strncat("world", "hello", 3, 0));
	printf("%d\n", test_strncat("world", "hello", 10, 0));
	printf("%d\n", test_strncat("", "hello", 10, 0));

	//strlen
	printf("%d\n", test_strlen("", 0));
	printf("%d\n", test_strlen("hello", 0));

	//strchr
	printf("%d\n", test_strchr("world", 'r', 0));
	printf("%d\n", test_strchr("world", 'a', 0));
	printf("%d\n", test_strchr("", 'a', 0));

	//strstr
	printf("%d\n", test_strstr("world", "rl", 0));
	printf("%d\n", test_strstr("needle", "nee", 0));
	printf("%d\n", test_strstr("world", "hello", 0));


	return 0;
}
