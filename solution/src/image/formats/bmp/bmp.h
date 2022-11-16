#ifndef BMP_H_
#define BMP_H_

#include "../formats_executor.h"
#include <stdio.h>

/**
 * Implementation of read_image_func according to bmp format
 */
enum read_status bmp_read_image(FILE* from, struct image* to);

/**
 * Implementation of write_image_func according to bmp format
 */
enum write_status bmp_write_image(FILE* to, const struct image* from);

#endif //BMP_H_
