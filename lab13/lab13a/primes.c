#include <stdio.h>
#include <stdlib.h>

/*
 * prints the first 200 primes
 */

int is_prime(int candidate) {
    int n;
    for (n = 2; n < candidate; n++) {
        if (candidate%n == 0){
            return 0;
        }
        
    }
    return 1;
    
}

int main(void) {
    int candidate = 2;
    int count =0;
    int num_printed = 0;

    while (num_printed < 200){
        if (is_prime(candidate) == 1){
            if(count<10){
                printf("%5i", candidate);
            }else {
                count =0;
                printf("\n");
                printf("%5i", candidate);
            }
            num_printed++;
            count++;
        }
        candidate++;
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}