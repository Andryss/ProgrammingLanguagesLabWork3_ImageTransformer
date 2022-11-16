#include "files_executor.h"

enum open_status file_open(FILE** target, const char* filename, const char* mode) {
    *target = fopen(filename, mode);
    if (*target != NULL) return OPEN_OK;
    return OPEN_ERR;
}

enum close_status file_close(FILE* target) {
    int result = fclose(target);
    if (result == 0) return CLOSE_OK;
    else return CLOSE_ERR;
}
