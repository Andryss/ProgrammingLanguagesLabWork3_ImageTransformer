#ifndef MAIN_EXECUTOR_H_
#define MAIN_EXECUTOR_H_

#include "formats/formats_executor.h"
#include "transforms/transform_executor.h"

/**
 * Enum of execute statuses
 */
enum executor_status {
	EXECUTE_OK,
	EXECUTE_ERR
};

/**
 * Wrapper for open-transform-write actions
 * @param filename_src - source filename
 * @param filename_dest - destination filename
 * @param read_func - function which define how to read source file (image type)
 * @param transform - function which define transformation we want to perform
 * @param write_func - function which define how to read destination file (image type)
 * @return execution status
 */
enum executor_status file_execute(
        const char* filename_src,
        const char* filename_dest,
        read_image_func read_func,
        transformer transform,
        write_image_func write_func
        );

/**
 * Array with messages about conversion (read src, write dest)
 */
extern char* convert_errors[];
/**
 * Array with messages about transformation
 */
extern char* transform_errors[];

#endif // MAIN_EXECUTOR_H_
