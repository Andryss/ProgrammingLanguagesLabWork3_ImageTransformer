
#include "identity.h"

enum transform_status identity_transform(const struct image* from, struct image* to) {

    *to = image_allocate(from->width, from->height);

    // Identity cycle
    for (uint64_t row = 0; row < from->height; row++) {
        for (uint64_t col = 0; col < from->width; col++) {
            image_set_pixel(to, row, col, image_get_pixel(from, row, col));
        }
    }

    return TRANSFORM_OK;
}
