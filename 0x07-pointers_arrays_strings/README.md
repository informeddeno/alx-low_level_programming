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

6. a function that prints the chessboard.
Prototype: void print_chessboard(char (*a)[8]);

7. a function that prints the sum of the two diagonals of a square matrix of integers.
Prototype: void print_diagsums(int *a, int size);

8. a function that sets the value of a pointer to a char.
Prototype: void set_string(char **s, char *to);

9. a file that contains the password for the crackme2 executable.
Your file should contain the exact password, no new line, no extra space