#ifndef MAIN_H
#define MAIN_H                      

int _putchar(char c);
void print_error(const char *message);
int copy_file(const char *source_file, const char *dest_file);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void exit_error(int exit_code, char *message);

#endif
