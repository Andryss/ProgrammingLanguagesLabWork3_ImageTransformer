#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <errno.h>
#include <string.h>

void info(char* message);

void error(char* message);

void error_file(char* filename, char* message);

void error_errno(char* filename);

#endif //UTIL_H_
