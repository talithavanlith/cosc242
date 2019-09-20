#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new() {

    flexarray result = malloc(sizeof *result);
    if (NULL == result) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    result->capacity = 2;
    result->itemcount = 0;
    result->items = malloc(result->capacity * sizeof result->items[0]);
    if (NULL == result->items) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void flexarray_append(flexarray f, int num) {

    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = realloc(f->items, f->capacity * sizeof f->items[0]);
        if (NULL == f->items) {
            fprintf(stderr, "memory reallocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}

static void selection_sort(int *a, int n) {
    int smallest;
    int swapPoint;
    int i;
    int j;

    for(i=0; i<(n-1); i++){

        if(i==n/2){
            int i;
            for (i = 0; i < n; i++) {
                fprintf(stderr, "%d\n", a[i]);
            }

        }

        smallest =a[i];
        swapPoint =i;

        for(j=(1+i); j<n; j++){

            if(a[j]<smallest){
                smallest=a[j];
                swapPoint=j;
            }

        }

        a[swapPoint] = a[i];
        a[i] = smallest;
    }

}

void flexarray_sort(flexarray f) {
    selection_sort(f->items, f->itemcount);
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}