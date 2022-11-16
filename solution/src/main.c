#include "utils/util.h"
#include "image/main_executor.h"
#include "image/formats/bmp/bmp.h"
#include "image/transforms/rotate/rotate.h"

static const char* const execute_messages[] = {
        [EXECUTE_OK] = "Image transformer successfully finished\n",
        [EXECUTE_ERR] = "Some error occurred during transformer working\n"
};

int main(const int argc, const char** const argv) {

    // Arg checking
    if (argc != 3) {
        error("Incorrect usage. Try this: image-transformer <source image> <destination image>\n");
        return 0;
    }

    // Invoke main function
    enum executor_status image_execute_status = file_execute
            (
            argv[1],
            argv[2],
            bmp_read_image,
            rotate_transform,
            bmp_write_image
            );

    // Print computation result
    if (image_execute_status != EXECUTE_OK) {
        error(execute_messages[image_execute_status]);
    } else {
        info(execute_messages[EXECUTE_OK]);
    }

    return 0;
}
