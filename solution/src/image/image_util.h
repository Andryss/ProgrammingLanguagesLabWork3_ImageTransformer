#ifndef IMAGE_UTIL_H_
#define IMAGE_UTIL_H_

#include <inttypes.h>
#include <malloc.h>

#pragma pack(push, 1)
struct pixel {
	uint8_t g, b, r;
};
#pragma pack(pop)

struct image {
	uint64_t width, height;
	struct pixel* data;
};

struct image image_allocate(uint64_t width, uint64_t height);

void image_free(struct image* image);

struct pixel* image_get_pixel(struct image* from, uint64_t row, uint64_t col);

void image_set_pixel(struct image* from, uint64_t row, uint64_t col, struct pixel* new_pixel);

#endif // IMAGE_UTIL_H_
