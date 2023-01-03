#ifndef TRANSFORM_EXECUTOR_H_
#define TRANSFORM_EXECUTOR_H_

#include "../image_util.h"

/**
 * Enum of transform image statuses
 */
enum transform_status {
	TRANSFORM_OK = 0,
	TRANSFORM_ERR
};

/**
 * Define function which transforms image and allocate the result
 * @param from - src image
 * @param to - dest image
 * @return transform inage status
 */
typedef enum transform_status (*transformer)(const struct image* from, struct image* to);

#endif // TRANSFORM_EXECUTOR_H_
