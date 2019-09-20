#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
  int capacity;
  int itemcount;
  int *items;
};

flexarray flexarray_new() {
    flexarray f = malloc(sizeof *f);
    if(NULL == f){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    f->capacity = 2;
    f->itemcount =0;
    f->items = malloc(f->capacity * sizeof f->items[0]);
    if(NULL == f->items){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return f;   
}

void flexarray_append(flexarray f, int num) {
    if(f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = realloc(f->items, f->capacity * sizeof f->items[0]);
        if(NULL == f->items){
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;
    for(i=0; i<f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}

void flexarray_sort(flexarray f) {
    int i =1;
    int key, swapPoint, k;
    int size = f->itemcount;

    while(i<size){
        key = f->items[i];
        swapPoint = i;
        i--;

        if(i == (size/2)){
            for(k=0, k<size; k++){
                fprintf(stderr, "%d\n", f->items[k]);

            }

        }

        while(i>=0 && f->items[i]>key){
            f->items[i+1] = f->items[i];
            i--;
        }
        f->items[i+1] = key;
        i = swapPoint+1;
    }
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}