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

struct image image_allocate(const uint64_t width, const uint64_t height);

void image_free(const struct image* image);

struct pixel* image_get_pixel(const struct image* from, const uint64_t row, const uint64_t col);

void image_set_pixel(const struct image* from, const uint64_t row, const uint64_t col, const struct pixel* new_pixel);

#endif // IMAGE_UTIL_H_
