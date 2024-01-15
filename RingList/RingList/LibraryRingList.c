#include "HeadRingList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("...\n");
}

void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("Список пуст.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->data != data) {
        if (current->next == head) {
            printf("Элемент с указанным значением не найден.\n");
            return head;
        }
        prev = current;
        current = current->next;
    }

    if (current == head) {

        if (head->next == head) {
            free(head);
            return NULL;
        }
        else {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
            free(current);
        }
    }
    else {
        prev->next = current->next;
        free(current);
    }

    return head;
}