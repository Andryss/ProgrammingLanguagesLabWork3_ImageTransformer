#ifndef IDENTITY_H_
#define IDENTITY_H_

#include "../../image_util.h"
#include "../transform_executor.h"

/**
 * Implementation of transformer according to identity transform
 */
enum transform_status identity_transform(const struct image* from, struct image* to);

#endif //IDENTITY_H_
