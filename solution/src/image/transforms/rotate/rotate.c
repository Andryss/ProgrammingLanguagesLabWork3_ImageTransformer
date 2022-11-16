
#include "rotate.h"

enum transform_status rotate_transform(const struct image* from, struct image *to) {

    *to = image_allocate(from->height, from->width);

    // Rotate cycle
    for (uint64_t row = 0; row < from->height; row++) {
        for (uint64_t col = 0; col < from->width; col++) {
            image_set_pixel(to, col, from->height - row - 1, image_get_pixel(from, row, col));
        }
    }

    return TRANSFORM_OK;
}
