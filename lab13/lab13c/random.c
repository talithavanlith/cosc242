#include <stdio.h>
#include <stdlib.h>

void repetitions(int *a, int size){
    int i;
    int *r;

    r = malloc(size * size_of r[0]);
    if(NULL =r){
        fprintf(stderr, "Memory allocation failed\n");
    }

    for(i=0; i<size; i++){
        r[i]=0;
    }

    for(i=0; i<size; i++){
        r[a[i]]+=1;

    }

    for(i=0; i<size; 1++){
        if(r[i]>1){
            printf("%d occurs %d times\n", i, r[i]);
        }
    }

    free(r);
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;

    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);

    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }

    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");

    repetitions(my_array, array_size);

    free(my_array);
    return EXIT_SUCCESS;
}
