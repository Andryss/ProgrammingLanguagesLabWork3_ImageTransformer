#ifndef FILES_EXECUTOR_H_
#define FILES_EXECUTOR_H_

#include <stdio.h>

enum open_status {
	OPEN_OK,
	OPEN_ERR
};

enum close_status {
	CLOSE_OK,
	CLOSE_ERR
};

enum open_status file_open(FILE** target, char* filename, char* mode);

enum close_status file_close(FILE* target);

#endif // FILES_EXECUTOR_H_
