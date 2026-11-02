#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    if (strlen(name) >= sizeof(t->name)){
        free(t);
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
        q->rear = t;
    }
    
    return 1;
}

int process_task(Queue *q, int *id, char name[]){
    if (q->front == NULL){
        return 0;
    }

    *id = q->front->id;
    strcpy(name, q->front->name);

    Task *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL){
        q->rear = NULL;
    }

    free(temp);

    return 1;
}

int peek_task(Queue *q, int *id, char name[]){
    if (q->front == NULL){
        return 0;
    }

    *id = q->front->id;
    strcpy(name, q->front->name);
    return 1;
}

int main(){
    //used to test task processing
    Queue q = {NULL, NULL};

    if (!add_task(&q, 101, "Print document")){
        printf("Failed to add task.\n");
    }

    if (!add_task(&q, 102, "Save file")){
        printf("Failed to add task.\n");
    }
    
    if(!add_task(&q, 103, "Send report")){
        printf("Failed to add task.\n");
    }

    

    int id;
    char name[20];

    if (peek_task(&q, &id, name)){
        printf("Next task: %d - %s\n", id, name);
    }
    else{
        printf("Queue is empty.\n");
    }

    if (process_task(&q, &id, name)){
        printf("Processed task: %d - %s\n", id, name);
    }
    else{
        printf("No tasks to process.\n");
    }

    if (process_task(&q, &id, name)){
        printf("Processed task: %d - %s\n", id, name);
    }
    else{
        printf("No tasks to process.\n");
    }

    if (process_task(&q, &id, name)){
        printf("Processed task: %d - %s\n", id, name);
    }
    else{
        printf("No tasks to process.\n");
    }

    if (process_task(&q, &id, name)){
        printf("Processed task: %d - %s\n", id, name);
    }
    else{
        printf("No tasks to process.\n");
    }
}
