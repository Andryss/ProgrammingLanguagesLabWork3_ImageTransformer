#ifndef FILES_EXECUTOR_H_
#define FILES_EXECUTOR_H_

#include <stdio.h>

/**
 * Enum of file open statuses
 */
enum open_status {
	OPEN_OK,
	OPEN_ERR
};

/**
 * Enum of file close statuses
 */
enum close_status {
	CLOSE_OK,
	CLOSE_ERR
};

/**
 * Tries to open file with given filename and given mode
 * @param target - where to place opened file (stream)
 * @param filename - file name
 * @param mode - in which mode to open a file (r, w, etc.)
 * @return file open status
 */
enum open_status file_open(FILE** target, const char* filename, const char* mode);

/**
 * Tries to close given file
 * @param target - file to close
 * @return file close status
 */
enum close_status file_close(FILE* target);

#endif // FILES_EXECUTOR_H_
