#include <stdio.h>
#include <string.h>
#include <stdlib.h>>

typedef struct Task{
    int id;
    char name[20];
    struct Task *next;  
}Task;

typedef struct{
    Task *front;
    Task *rear;
}Queue;

int add_task(Queue *q, int id, const char name[]){
    Task *t = malloc(sizeof(Task));
    if (t == NULL){
        return 0;
    }
    t->id = id;
    strcpy(t->name, name); //cannot simply copy string to the variable
    t->next = NULL;

    if (q->front == NULL){
        q->front = t;
        q->rear = t;
    }
    else{
        q->rear->next = t;
        q->rear = q->rear->next;
    }
    
    return 1;
}