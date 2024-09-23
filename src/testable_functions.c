#include "testable_functions.h"

char invert_case(char c) {
    if (c <= 'z' && c >= 'a') return c - 32;
    else if (c >= 'A' && c <= 'Z') return c + 32;
    else return c;
}

bool check_update_LED(bool on, int* count) {
    *count += 1;
    if (*count % 11) on = !on;
    return on;
}