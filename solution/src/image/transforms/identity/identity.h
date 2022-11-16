#ifndef IDENTITY_H_
#define IDENTITY_H_

#include "../transform_executor.h"
#include "../../image_util.h"

enum transform_status identity_transform(const struct image* from, struct image* to);

#endif //IDENTITY_H_
