#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct{
    int key;
} element;

element queue[MAX_SIZE];
int rear = -1, front = -1;

void DONE(){
    #ifdef __linux__
        printf("\b\xE2\x9C\x93\n");
    #elif _WIN32
        printf("\bdone\n");
    #endif 
}

bool is_empty(){
    return front == rear; }

bool is_full(){
    return rear == MAX_SIZE; }
//if full then print that otherwise add to queue
void enqueue(int item){
    if (is_full(queue)){
        printf("queue is full\n"); }
    else{
        queue[++rear].key = item;
        DONE; } }

void dequeue() {
    if (is_empty(queue))
        printf("The queue is empty\n");
    else
        printf("%d\n", queue[++front].key);}

void show() {
    if (is_empty())
        printf("The Queue is empty\n");
    else
        for (int i = front+1; i <= rear; i++){
            printf("%d ", queue[i].key); } 
            printf("\n"); }

int main() {
    int op, temp;
start:
    printf("Enter the operations you want to perform on queue(1: enqueue, 2: dequeue 3: show 4: is_full 5: is_empty 6: exit): "); scanf("%d", &op);
    if ((op < 1 || op > 6)) {
        printf("Out of bound exception Please enter the correct opeartion!!\n");
    printf("---X---X---X---\n");
        goto start; }

    if(op ==1){
        printf("Enter the number to enqueue: ");
        scanf("%d", &temp);
        enqueue(temp);
        DONE(); }
    if(op ==2)
        dequeue();
    if(op ==3) 
        show();
    if(op ==4)
        if (is_empty())
            printf("The Queue is empty\n");
    if(op ==5)
        if (is_full())
            printf("The Queue is Full\n");
    if(op ==6)
        return -1;
    printf("---X---X---X---");
    goto start;
}
