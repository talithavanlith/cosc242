#include <stdio.h>
#include <stdlib.h>

int is_prime(int i){
    int n;
    for(n=2; n<i; n++){
        if(i%n ==0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int i =2;
    int np =0;
    int count =0;

    while(np<200){
        if(is_prime(i)==1){
            if(count<10){
                printf("%5d", i);
            }else{
                count=0;
                printf("\n%5d", i);
            }
            count++;
            np++;
        }
        i++;
    }
    printf("\n");
    return(EXIT_SUCCESS);
}