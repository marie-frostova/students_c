#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tests.h"

int main() {
    test_list();
    test_s_list();
    test_middle();
    test_reverse();
    test_intersection();
    test_remove_duplicates();
    test_cycle();
    test_remove_nth_from_end();
    test_merge();
    return 0;
}