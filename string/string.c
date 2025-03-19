// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	while (*source != '\0') {
		*destination = *source;
		++destination;
		++source;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;
	for (i = 0; i < len; ++i) {
		destination[i] = source[i];
		if (source[i] == '\0') {
			break;
		}
	}
	while (i < len) {
		destination[i] = '\0';
		i++;
	}
	return destination;
}

char *strcat (char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	while (*destination != '\0') {
		destination++;
	}
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i;
    while (*destination != '\0') {
		destination++;
	}
    for (i = 0; i < len; ++i) {
	    destination[i] = source[i];	
		if (source[i] == '\0') {
			break;
		}
    }
    destination[i] = '\0';
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	size_t i = 0;
    while(str1[i] == str2[i]) {
        if(str1[i] == '\0')
            return (str1[i] - str2[i]);
        ++i;
    }
    return (str1[i] - str2[i]);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	// /* TODO: Implement strncmp(). */
	size_t i = 0;
	while (i < len && str1[i] == str2[i]) {
		if (str1[i] == '\0') {
			return 0;
		}
		++i;
	}
	if (i == len) {
		return 0;
	}
	return (str1[i] - str2[i]);
}

size_t strlen(const char *str)
{
	size_t len = 0;
    while (*str++) {
        ++len;
    }
    return len;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	do {
		if (*str == c) {
			return (char *)str;
		}
		++str;
	} while (*str != '\0');
	return NULL;
}

char *strrchr(const char *str, int c)
{	
	/* TODO: Implement strrchr(). */
	char *ptr = NULL;
	do {
		if (*str == c) {
			ptr = (char *)str;
		}
		++str;
	} while (*str != '\0');
	return ptr;
}

char *strstr(const char *haystack, const char *needle) 
{
	/* TODO: Implement strstr(). */
	if (strlen(needle) == 0) {
		return (char*)haystack;
	}
	if (strlen(needle) > strlen(haystack)) {
		return NULL;
	}
	while (haystack <= haystack + strlen(haystack) - strlen(needle)) {
		if (*haystack == *needle && strncmp(haystack, needle, strlen(needle)) == 0) {
			return (char*)haystack;
		}
		++haystack;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle) 
{
	/* TODO: Implement strrstr(). */
	if (strlen(needle) == 0) {
			return (char*)haystack + strlen(haystack);
	}
    if (strlen(needle) > strlen(haystack)) {
        return NULL;
    }
    const char* end = haystack + strlen(haystack);
	for (; end >= haystack; --end) {
		if (*end == *needle && strncmp(end, needle, strlen(needle)) == 0) {
			return (char*)end;
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) 
{
	/* TODO: Implement memcpy(). */
	if ((const char *)source < (char *)destination) {
		for (size_t i = num; i > 0; --i) {
			((char *)destination)[i - 1] = ((const char *)source)[i - 1];
		}
	}
	else {
		for (size_t i = 0; i < num; ++i) {
			((char *)destination)[i] = ((const char *)source)[i];
		}
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return memcpy(destination, source, num);
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
    for (size_t i = 0; i < num; ++i) {
        if (((const unsigned char *)ptr1)[i] != ((const unsigned char *)ptr2)[i]) {
            return (((const unsigned char *)ptr1)[i] - ((const unsigned char *)ptr2)[i]);
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
    for (size_t i = 0; i < num; ++i) {
        ((unsigned char *)source)[i] = (unsigned char)value;
    }
	return source;
}