#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define delim " \n\t"

int execmd(char **argc);
char *location(char *command);
char **stringTokenizer(char *input);

#endif
