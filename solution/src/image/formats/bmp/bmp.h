#ifndef BMP_H_
#define BMP_H_

#include <stdio.h>
#include "../formats_executor.h"

enum read_status bmp_read_image(FILE* from, struct image* to);

enum write_status bmp_write_image(FILE* to, struct image* from);

#endif //BMP_H_
