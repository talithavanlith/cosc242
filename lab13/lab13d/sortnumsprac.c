#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main(void){
    int i;
    flexarray array = flexarray_new();

    while((scanf("%d", i))==1){
        flexarray_append(array, i);
    }

    flexarray_sort(array);
    flexarray_print(array);
    flexarray_free(array);

    return EXIT_SUCCESS;
}