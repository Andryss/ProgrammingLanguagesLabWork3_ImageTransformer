#ifndef IMAGE_UTIL_H_
#define IMAGE_UTIL_H_

#include <inttypes.h>
#include <malloc.h>

/**
 * Pixel structure
 */
#pragma pack(push, 1)
struct pixel {
	uint8_t g, b, r;
};
#pragma pack(pop)

/**
 * Image structure
 */
struct image {
	uint64_t width, height;
	struct pixel* data;
};

/**
 * Allocate memory in heap for the new image and return
 * @param width - width of image we want
 * @param height - height of image we want
 * @return allocated (in the heap) image
 */
struct image image_allocate(const uint64_t width, const uint64_t height);

/**
 * Free memory in the heap for the given image
 * @param image - image we want to dislocate
 */
void image_free(const struct image* image);

/**
 * Return a pointer to an image pixel by row and column
 * @param from - image we explore
 * @param row - row number
 * @param col - column number
 * @return pointer to a pixel with current coordinates
 */
struct pixel* image_get_pixel(const struct image* from, const uint64_t row, const uint64_t col);

/**
 * Set a new value of image pixel by row and column
 * @param from - image we change
 * @param row - row number
 * @param col - column number
 * @param new_pixel - pointer to a source pixel
 */
void image_set_pixel(const struct image* from, const uint64_t row, const uint64_t col, const struct pixel* new_pixel);

#endif // IMAGE_UTIL_H_
