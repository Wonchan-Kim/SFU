#include <stdio.h>
#include "helpers.h"
#define WEIGHT 10

int main(int argc, char *argv[]) {
    int result = weighted_add(3, 2, WEIGHT);
    printf("The result is %d.\n", result);
    return 0;
}