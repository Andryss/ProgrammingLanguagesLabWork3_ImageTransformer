#ifndef FORMATS_EXECUTOR_H_
#define FORMATS_EXECUTOR_H_

#include "../../files/files_executor.h"
#include "../../utils/util.h"
#include "../image_util.h"
#include <stdio.h>

enum read_status {
	READ_OK,
	READ_ERR,
    READ_INVALID_HEADER,
    READ_INVALID_SIGNATURE,
    READ_INVALID_PADDING
};

enum write_status {
	WRITE_OK,
	WRITE_ERR,
	WRITE_INVALID_HEADER,
	WRITE_INVALID_SIGNATURE,
	WRITE_INVALID_PADDING
};

typedef enum read_status (*read_image_func)(FILE* from, struct image* to);
typedef enum write_status (*write_image_func)(FILE* to, const struct image* from);

enum convert_status {
	CONVERT_OK,
	CONVERT_ERR
};

enum convert_status read_image(const char* filename, read_image_func converter, struct image* to);
enum convert_status write_image(const char* filename, write_image_func converter, const struct image* from);

extern const char* const open_errors[];
extern const char* const read_errors[];
extern const char* const write_errors[];
extern const char* const close_errors[];

#endif // FORMATS_EXECUTOR_H_
