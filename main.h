#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>

size_t _strlen(char *string);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *string);
char *_strcpy(char *dest, char *src);
char *_strtok(char *string, const char *delimit);
char *trim(char *string);
int _putchar(int c);
int _puts(char *string);

int _atoi(char *string);

void exiting(int status);
void _env(char **environ);
void excmd(char **argv, int *child_status);
char *locate(char *cmd);

#endif
