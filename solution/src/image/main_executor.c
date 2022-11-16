
#include "main_executor.h"

char* convert_errors[] = {
        [CONVERT_ERR] = "Some error occurred while reading image\n"
};

char* transform_errors[] = {
        [TRANSFORM_ERR] = "Some error occurred while transforming image\n"
};

enum executor_status file_execute(const char* filename_src, const char* filename_dest, read_image_func read_func, transformer transform, write_image_func write_func) {

    struct image image_src = {0};

    enum convert_status read_image_status = read_image(filename_src, read_func, &image_src);
    if (read_image_status != CONVERT_OK) {
        error_file(filename_src, convert_errors[read_image_status]);
        return EXECUTE_ERR;
    }

    struct image image_dest = {0};

    enum transform_status image_transform_status = transform(&image_src, &image_dest);
    image_free(&image_src);
    if (image_transform_status != TRANSFORM_OK) {
        error_file(filename_src, transform_errors[image_transform_status]);
        return EXECUTE_ERR;
    }

    enum convert_status write_image_status = write_image(filename_dest, write_func, &image_dest);
    image_free(&image_dest);
    if (write_image_status != CONVERT_OK) {
        error_file(filename_dest, convert_errors[write_image_status]);
        return EXECUTE_ERR;
    }

    return EXECUTE_OK;
}
