#ifndef TRANSFORM_EXECUTOR_H_
#define TRANSFORM_EXECUTOR_H_

#include "../image_util.h"

enum transform_status {
	TRANSFORM_OK,
	TRANSFORM_ERR
};

typedef enum transform_status (*transformer)(struct image* from, struct image* to);

#endif // TRANSFORM_EXECUTOR_H_
