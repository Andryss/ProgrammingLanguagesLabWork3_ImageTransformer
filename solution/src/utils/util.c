
#include "util.h"

void info(char* message) {
    fprintf(stdout, "%s", message);
}

void error(char* message) {
    fprintf(stderr, "%s", message);
}

void error_file(char* filename, char* message) {
    fprintf(stderr, "%s : %s", filename, message);
}

void error_errno(char* filename) {
    fprintf(stderr, "%s : %s\n", filename, strerror(errno));
}
