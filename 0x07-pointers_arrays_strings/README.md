0x07. C - Even more pointers, arrays and strings

0. a function that fills memory with a constant byte.
Prototype: char *_memset(char *s, char b, unsigned int n);

1. a function that copies memory area.
Prototype: char *_memcpy(char *dest, char *src, unsigned int n);

2. a function that locates a character in a string.
Prototype: char *_strchr(char *s, char c);

3. a function that gets the length of a prefix substring.
Prototype: unsigned int _strspn(char *s, char *accept);

4. a function that searches a string for any of a set of bytes.
Prototype: char *_strpbrk(char *s, char *accept);

5. function that locates a substring.
Prototype: char *_strstr(char *haystack, char *needle);