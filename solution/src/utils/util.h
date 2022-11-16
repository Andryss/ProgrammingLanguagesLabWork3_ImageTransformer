#ifndef UTIL_H_
#define UTIL_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>

void info(const char* message);

void error(const char* message);

void error_file(const char* filename, const char* message);

void error_errno(const char* filename);

#endif //UTIL_H_
