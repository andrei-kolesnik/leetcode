/*
LeetCode 28. Implement strStr()
https://leetcode.com/problems/implement-strstr/

Input1: haystack = "hello", needle = "ll"
Output: 2

Input 2: haystack = "aaaaa", needle = "bba"
Output 2: -1
*/
#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
	if (*needle == 0) return 0;
	int result = 0;
	while (haystack[result])
	{
		char *h = haystack + result, *n = needle;
		while (true)
		{
			if (*n == 0) return result; //if there is no more needle left, we found the match
			if (*h == 0) break; //there is no more haystack left
			if (*(h++) != *(n++)) break; //character mismatch
		}
		result++; //we need to start with the next haystack character
	}
	return -1; //we tried every haystack character and failed
}

void check(const char* haystack, const char* needle, int expected) {
	int actual = strStr((char*)haystack, (char*)needle);
	printf("%s (%d / %d)\n", actual == expected ? "PASS" : "FAIL", expected, actual);
}

int main()
{
	check("hello", "ll", 2);
	check("hello", "lo", 3);
	check("hello", "hello", 0);
	check("hell", "hello", -1);
	check("aaaa", "bba", -1);
	check("aaaa", "aaa", 0);
	check("aaaa", "", 0);
	check("", "", 0);
	getchar();
	return 0;
}
