#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    int i;

    queue result = emalloc(sizeof *result);
    result->capacity = 5;
    result->num_items = 0;
    result->head = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);

    for(i=0; i<result->capacity; i++){
        result->items[i] = 0;
    }

    return result;
}

void enqueue(queue q, double item){
    int pos;
    if(q->num_items >= q->capacity){
        printf("Queue is full\n");
        return;
    }
    pos = (q->head + q->num_items) % q->capacity;
    q->items[pos] = item;
    q->num_items++;
    }

double dequeue(queue q){
    double old_head;
    if(q->num_items == 0){
        printf("Queue is empty\n");
        return 0.0;
    }
    old_head = q->items[q->head];
    q->items[q->head] = 0.0;
    q->head++;
    q->num_items--;
    return old_head;
}

void queue_print(queue q) {
    int i;
    for(i=0; i<q->capacity; i++){
        printf("%f\n", q->items[i]);
    }
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}