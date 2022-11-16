#include "image_util.h"

struct image image_allocate(uint64_t width, uint64_t height) {
    return ((struct image) {
        .width = width,
        .height = height,
        .data = malloc(sizeof(struct pixel) * width * height)
    });
}

void image_free(struct image* image) {
    free(image->data);
}

struct pixel* image_get_pixel(struct image* from, uint64_t row, uint64_t col) {
    return from->data + (from->width * row + col);
}

void image_set_pixel(struct image* from, uint64_t row, uint64_t col, struct pixel* new_pixel) {
    from->data[from->width * row + col] = *new_pixel;
}


