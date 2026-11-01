#include <stdio.h>
#include <string.h>

typedef struct Task{
    int id;
    char name[20];
    struct Task *next;  
}Task;

typedef struct{
    Task *front;
    Task *rear;
}Queue;