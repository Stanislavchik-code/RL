#ifndef HEADRINGLIST_H
#define HEADRINGLIST_H

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
struct Node* insertNode(struct Node* head, int data);
void displayList(struct Node* head);
void freeList(struct Node* head);
struct Node* appendNode(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int data);

#endif
