#ifndef UTIL_H_
#define UTIL_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>

/**
 * Prints message in stdout (level INFO)
 * @param message - message to print
 */
void info(const char* message);

/**
 * Prints message in stderr (level ERROR)
 * @param message - message to print
 */
void error(const char* message);

/**
 * Prints file error in stderr (level ERROR)
 * @param filename - file name
 * @param message - error message
 */
void error_file(const char* filename, const char* message);

/**
 * Prints file error message associated with code placed in ERRNO
 * @param filename - file name
 */
void error_errno(const char* filename);

#endif //UTIL_H_
