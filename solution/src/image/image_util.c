#include "image_util.h"

struct image image_allocate(const uint64_t width, const uint64_t height) {
    return ((struct image) {
        .width = width,
        .height = height,
        .data = malloc(sizeof(struct pixel) * width * height)
    });
}

void image_free(const struct image* image) {
    free(image->data);
}

struct pixel* image_get_pixel(const struct image* from, const uint64_t row, const uint64_t col) {
    return from->data + (from->width * row + col);
}

void image_set_pixel(const struct image* from, const uint64_t row, const uint64_t col, const struct pixel* new_pixel) {
    from->data[from->width * row + col] = *new_pixel;
}


