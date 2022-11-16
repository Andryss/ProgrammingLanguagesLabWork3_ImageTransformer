
#include "formats_executor.h"

const char* const open_errors[] = {
        [OPEN_ERR] = "Some error occurred while opening file\n"
};

const char* const read_errors[] = {
        [READ_ERR] = "Some error occurred while reading from file\n",
        [READ_INVALID_HEADER] = "Invalid header found\n",
        [READ_INVALID_PADDING] = "Invalid padding found\n",
        [READ_INVALID_SIGNATURE] = "Invalid file signature\n"
};

const char* const write_errors[] = {
        [WRITE_ERR] = "Some error occurred while writing into file\n",
        [WRITE_INVALID_HEADER] = "Can't write header\n",
        [WRITE_INVALID_PADDING] = "Can't write padding\n",
        [WRITE_INVALID_SIGNATURE] = "Can't resolve signature\n"
};

const char* const close_errors[] = {
        [CLOSE_ERR] = "Some error occurred while closing file\n"
};

enum convert_status read_image(const char* filename, read_image_func converter, struct image* to) {
    FILE* file = NULL;
    enum open_status open_file_status = file_open(&file, filename, "rb");
    if (open_file_status != OPEN_OK) {
        error_errno(filename);
        error_file(filename, open_errors[open_file_status]);
        return CONVERT_ERR;
    }

    enum read_status read_image_status = converter(file, to);
    if (read_image_status != READ_OK) {
        error_file(filename, read_errors[read_image_status]);
        return CONVERT_ERR;
    }

    enum close_status close_file_status = file_close(file);
    if (close_file_status != CLOSE_OK) {
        error_errno(filename);
        error_file(filename, close_errors[close_file_status]);
        return CONVERT_ERR;
    }

    return CONVERT_OK;
}

enum convert_status write_image(const char* filename, write_image_func converter, const struct image* from) {
    FILE* file = NULL;
    enum open_status open_file_status = file_open(&file, filename, "wb");
    if (open_file_status != OPEN_OK) {
        error_errno(filename);
        error_file(filename, open_errors[open_file_status]);
        return CONVERT_ERR;
    }

    enum write_status write_image_status = converter(file, from);
    if (write_image_status != WRITE_OK) {
        error_file(filename, write_errors[write_image_status]);
        return CONVERT_ERR;
    }

    enum close_status close_file_status = file_close(file);
    if (close_file_status != CLOSE_OK) {
        error_errno(filename);
        error_file(filename, close_errors[close_file_status]);
        return CONVERT_ERR;
    }

    return CONVERT_OK;
}
