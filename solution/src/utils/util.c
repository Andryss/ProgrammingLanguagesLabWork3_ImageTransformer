
#include "util.h"

void info(const char* message) {
    fprintf(stdout, "%s", message);
}

void error(const char* message) {
    fprintf(stderr, "%s", message);
}

void error_file(const char* filename, const char* message) {
    fprintf(stderr, "%s : %s", filename, message);
}

void error_errno(const char* filename) {
    fprintf(stderr, "%s : %s\n", filename, strerror(errno));
}
