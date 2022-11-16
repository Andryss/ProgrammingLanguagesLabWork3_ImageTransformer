#ifndef MAIN_EXECUTOR_H_
#define MAIN_EXECUTOR_H_

#include "formats/formats_executor.h"
#include "transforms/transform_executor.h"

enum executor_status {
	EXECUTE_OK,
	EXECUTE_ERR
};

enum executor_status file_execute(char* filename_src, char* filename_dest, read_image_func read_func, transformer transform, write_image_func write_func);

extern char* convert_errors[];
extern char* transform_errors[];

#endif // MAIN_EXECUTOR_H_
