#ifndef FORMATS_EXECUTOR_H_
#define FORMATS_EXECUTOR_H_

#include "../../files/files_executor.h"
#include "../../utils/util.h"
#include "../image_util.h"
#include <stdio.h>

/**
 * Enum of file read statuses
 */
enum read_status {
	READ_OK = 0,
	READ_ERR,
    READ_INVALID_HEADER,
    READ_INVALID_SIGNATURE,
    READ_INVALID_PADDING
};

/**
 * Enum of file write statuses
 */
enum write_status {
	WRITE_OK = 0,
	WRITE_ERR,
	WRITE_INVALID_HEADER,
	WRITE_INVALID_SIGNATURE,
	WRITE_INVALID_PADDING
};

/**
 * Define function which reads image from file depends of result file format
 * @param from - file to read
 * @param to - image to fill
 * @return read image status
 */
typedef enum read_status (*read_image_func)(FILE* from, struct image* to);
/**
 * Define function which write image to file depends of result file format
 * @param from - file to write
 * @param to - image to write
 * @return write image status
 */
typedef enum write_status (*write_image_func)(FILE* to, const struct image* from);

/**
 * Enum of file convert statuses (conversion is: file -> image, image -> file)
 */
enum convert_status {
	CONVERT_OK = 0,
	CONVERT_ERR
};

/**
 * Wrapper function, which consist of opening file, reading image from file, closing file
 * @param filename - file name
 * @param converter - function which reads image from file
 * @param to - image to fill
 * @return convert status
 */
enum convert_status read_image(const char* filename, read_image_func converter, struct image* to);
/**
 * Wrapper function, which consist of opening file, writing image to file, closing file
 * @param filename - file name
 * @param converter - function which write image to file
 * @param from - image to write
 * @return convert status
 */
enum convert_status write_image(const char* filename, write_image_func converter, const struct image* from);

/**
 * Array with messages about opening file
 */
extern const char* const open_errors[];
/**
 * Array with messages about reading from file
 */
extern const char* const read_errors[];
/**
 * Array with messages about writing to file
 */
extern const char* const write_errors[];
/**
 * Array with messages about opening file
 */
extern const char* const close_errors[];

#endif // FORMATS_EXECUTOR_H_
