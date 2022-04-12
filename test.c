#include <stdio.h>
#include <stdlib.h>

#include "ht.h"

int main() {
    ht_t tbl;
    ht_alloc(&tbl, 10);

    for (int i = 0; i < 1000; i++) {
        ht_put(&tbl, i, i);
    }

    for (int i = 0; i < 100; i++) {
        ht_key_t key = rand() % 1000;
        ht_val_t val = ht_get(&tbl, key, NULL);
        if (val != key) {
            printf("ERROR: %d != %d\n", val, key);
            exit(1);
        }
    }

    printf("pass\n");

    return 0;
}
