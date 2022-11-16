#ifndef ROTATE_H_
#define ROTATE_H_

#include "../../image_util.h"
#include "../transform_executor.h"

enum transform_status rotate_transform(const struct image* from, struct image *to);

#endif //ROTATE_H_
