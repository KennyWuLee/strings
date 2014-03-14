#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "new_string.h"

int test_strcpy(char* src)
{
	char *src1, *src2, *return1, *return2;
	char dest1[20], dest2[20];

	src1 = src2 = src;

	return1 = strcpy(dest1, src1);
	return2 = new_strcpy(dest2, src2);

	// printf("strcpy:     src: %s dest: %s rtrn: %s\n", src1, dest1, return1);
	// printf("new_strcpy: src: %s dest: %s rtrn: %s\n", src2, dest2, return2);

	return strcmp(src1, src2)==0 && strcmp(dest1, dest2)==0 &&
			strcmp(return2, return2)==0;
}

int test_strncpy(char* src, int size)
{
	char *src1, *src2, *return1, *return2;
	char dest2[20], dest1[20];
	int size1, size2;
	size1 = size2 = size;
	src1 = src2 = src;

	return1 = strncpy(dest1, src1, size1);
	return2 = new_strncpy(dest2, src2, size2);

	printf("strncpy:     src: %s dest: %s size: %d rtrn: %s\n",
			src1, dest1, size1, return1);
	printf("new_strncpy: src: %s dest: %s size: %d rtrn: %s\n",
			src2, dest2, size2, return2);

	return strcmp(src1, src2)==0 && strcmp(dest1, dest2)==0 && (size1 == size2) &&
			strcmp(return2, return2)==0;
}

int test_strcmp(char* str1, char* str2)
{
	char *src1, *src2, *dest1, *dest2;
	int return1, return2;

	src1 = src2 = str1;
	dest1 = dest2 = str2;

	return1 = strcmp(src1, dest1);
	return2 = new_strcmp(src2, dest2);

	// printf("strcmp:     str1: %s str2: %s rtrn: %d\n", src1, dest1, return1);
	// printf("new_strcmp: str1: %s str2: %s rtrn: %d\n", src2, dest2, return2);

	return strcmp(src1, src2)==0 && strcmp(dest1, dest2)==0 && (return1 == return2);
}

int test_strncmp(char* str1, char* str2, int size)
{
	char *src1, *src2, *dest1, *dest2;
	int size1, size2, return1, return2;

	src1 = src2 = str1;
	dest1 = dest2 = str2;
	size1 = size2 = size;

	return1 = strcmp(src1, dest1);
	return2 = new_strcmp(src2, dest2);

	// printf("strncmp:     str1: %s str2: %s size: %d rtrn: %d\n",
	// 		src1, dest1, size1, ret1);
	// printf("new_strncmp: str1: %s str2: %s size: %d rtrn: %d\n",
	// 		src2, dest2, size2, ret2);

	return strcmp(src1, src2)==0 && strcmp(dest1, dest2)==0 &&
			(size1 == size2) && (return1 == return2);
}

int main()
{
	//strcpy
	printf("%d\n", test_strcpy((char*)"hello"));

	//strncpy
	printf("%d\n", test_strncpy((char*)"hellohellohello", 7));
	printf("%d\n", test_strncpy((char*)"hello", 7));
	printf("%d\n", test_strncpy((char*)"hellohello", 10));

	//strcmp
	printf("%d\n", test_strcmp((char*)"aaa", (char*)"abc"));
	printf("%d\n", test_strcmp((char*)"abc", (char*)"abc"));
	printf("%d\n", test_strcmp((char*)"ccc", (char*)"abc"));

	//strncmp
	printf("%d\n", test_strncmp((char*)"aaaddd", (char*)"abcccc", 3));
	printf("%d\n", test_strncmp((char*)"abcddd", (char*)"abcccc", 3));
	printf("%d\n", test_strncmp((char*)"cccddd", (char*)"abcccc", 3));

	return 0;
}