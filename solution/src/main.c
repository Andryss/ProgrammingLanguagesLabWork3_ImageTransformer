#include "image/formats/bmp/bmp.h"
#include "image/main_executor.h"
#include "image/transforms/rotate/rotate.h"
#include "utils/util.h"
#include <sysexits.h>

/**
 * Array with messages about execution
 */
static const char* const execute_messages[] = {
        [EXECUTE_OK] = "Image transformer successfully finished\n",
        [EXECUTE_ERR] = "Some error occurred during transformer working\n"
};

/**
 * MAIN
 * @param argc - amount of console args
 * @param argv - console args list
 * @return execution code
 */
int main(const int argc, const char** const argv) {

    // Arg checking
    if (argc != 3) {
        error("Incorrect usage. Try this: image-transformer <source image> <destination image>\n");
        return EX_USAGE;
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
        return EX__BASE;
    } else {
        info(execute_messages[EXECUTE_OK]);
        return EX_OK;
    }
}
