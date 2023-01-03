
#include "bmp.h"

/**
 * Structure of bmp file header
 */
#pragma pack(push, 1)
struct bmp_header
{
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)

/**
 * Reads bmp header from file
 * @param from - file to read header
 * @param to - header to fill
 * @return read header status
 */
static enum read_status bmp_read_header(FILE* from, struct bmp_header* to) {
    size_t read_count = fread(to, sizeof(struct bmp_header), 1, from);
    if (read_count != 1) return READ_INVALID_HEADER;
    else return READ_OK;
}

/**
 * Calculates padding according to width
 * @param width - just width (really???)
 * @return padding value
 */
uint8_t get_bmp_row_padding(uint64_t width) {
    uint8_t remains = width * sizeof(struct pixel) % 4;
    if (remains == 0) return remains;
    else return 4 - remains;
}

/**
 * Reads bmp data (pixels) from file
 * @param from  - file to read data
 * @param to - image to fill
 * @return read data status
 */
static enum read_status bmp_read_data(FILE* from, struct image* to) {
    uint64_t width = to->width;
    uint8_t padding = get_bmp_row_padding(width);

    for (size_t i = 0; i < to->height; i++) {
        size_t read_count = fread(to->data + i * width, sizeof(struct pixel), width, from);
        if (read_count != width) return READ_INVALID_SIGNATURE;

        int is_skipped = fseek(from, padding, SEEK_CUR);
        if (is_skipped != 0) return READ_INVALID_PADDING;
    }

    return READ_OK;
}

enum read_status bmp_read_image(FILE* from, struct image* to) {
    struct bmp_header header = {0};
    enum read_status read_header_status = bmp_read_header(from, &header);
    if (read_header_status != READ_OK) return read_header_status;

    *to = image_allocate(header.biWidth, header.biHeight);
    return bmp_read_data(from, to);
}

/**
 * Some define-enum to not get "MAGIC CONSTANTS" comment
 */
enum BMP_DEFAULTS {
    BF_TYPE = 19778,
    B_OFF_BITS = sizeof(struct bmp_header),
    BI_SIZE = 40,
    BI_PLANES = 1,
    BI_BIT_COUNT = 24,
    BI_COMPRESSION = 0,
    BI_X_PELS_PER_METER = 2835,
    BI_Y_PELS_PER_METER = 2835,
    BI_CLR_USED = 0
};
/**
 * Somehow a magic number enters the bar, and the bartender says "OBJECTION! there are no define"
 */

/**
 * Define template for bmp files
 */
static const struct bmp_header SIMPLE_HEADER = {
        .bfType = BF_TYPE,
        //.bfileSize = ...,
        .bfReserved = 0,
        .bOffBits = B_OFF_BITS,
        .biSize = BI_SIZE,
        //.biWidth = ...,
        //.biHeight = ...,
        .biPlanes = BI_PLANES,
        .biBitCount = BI_BIT_COUNT,
        .biCompression = BI_COMPRESSION,
        //.biSizeImage = ...,
        .biXPelsPerMeter = BI_X_PELS_PER_METER,
        .biYPelsPerMeter = BI_Y_PELS_PER_METER,
        .biClrUsed = BI_CLR_USED,
        .biClrImportant = 0
};

/**
 * Creates header according to the given image
 * @param image - image to use
 * @return generated header
 */
static struct bmp_header create_header(const struct image* image) {
    struct bmp_header header = SIMPLE_HEADER;
    header.biWidth = image->width;
    header.biHeight = image->height;
    header.biSizeImage = sizeof(struct pixel) * (image->width + get_bmp_row_padding(image->width)) * image->height;
    header.bfileSize = header.bOffBits + header.biSizeImage;

    return header;
}

/**
 * Writes bmp header to file
 * @param to - file to write header
 * @param from - image to generate header
 * @return write header status
 */
static enum write_status bmp_write_header(FILE* to, const struct image* from) {
    struct bmp_header header = create_header(from);
    size_t write_count = fwrite(&header, sizeof(struct bmp_header), 1, to);
    if (write_count != 1) return WRITE_INVALID_HEADER;
    return WRITE_OK;
}

/**
 * Writes bmp data (pixels) to file
 * @param to - file to write data
 * @param from - image to write
 * @return write data status
 */
static enum write_status bmp_write_data(FILE* to, const struct image* from) {
    uint64_t width = from->width;
    uint8_t padding = get_bmp_row_padding(width);

    for (size_t i = 0; i < from->height; i++) {
        size_t write_count = fwrite(from->data + i * width, sizeof(struct pixel), width, to);
        if (write_count != width) return WRITE_INVALID_SIGNATURE;

        size_t is_skipped = fseek(to, padding, SEEK_CUR);
        if (is_skipped != 0) return WRITE_INVALID_PADDING;
    }
    return WRITE_OK;
}

enum write_status bmp_write_image(FILE* to, const struct image* from) {
    enum write_status write_header_status = bmp_write_header(to, from);
    if (write_header_status != WRITE_OK) return write_header_status;

    return bmp_write_data(to, from);
}
