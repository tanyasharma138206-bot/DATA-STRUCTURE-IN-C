#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *start1, *start2, *temp;
    start1 = malloc(sizeof(struct Node));
    start1->data = 10;
    start1->next = malloc(sizeof(struct Node));
    start1->next->data = 20;
    start1->next->next = NULL;
    start2 = malloc(sizeof(struct Node));
    start2->data = 30;
    start2->next = malloc(sizeof(struct Node));
    start2->next->data = 40;
    start2->next->next = NULL;
    temp = start1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = start2;
    temp = start1;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
