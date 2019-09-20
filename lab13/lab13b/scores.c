#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int winner = 0;
    double highest_score =0.0;
    int p, sc;
    double s1, s2, s3, score;

    while((sc = scanf("%d%lg%lg%lg", &p, &s1, &s2, &s3)) == 4){

        if (s1 <= s2 && s1 <= s3) {
            score = ((s2 + s3) / 2);
        } else if (s2 <= s1 && s2 <= s3) {
            score = ((s1 + s3) / 2);
        } else {
            score = ((s1 + s2) / 2);
        }

        if(score >= highest_score){
            highest_score = score;
            winner = p;
        }
    }

    printf("%d\n", winner);
    return EXIT_SUCCESS;
}