#include <stdio.h>
#include <string.h>
#include "utilities.h"

void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
}
