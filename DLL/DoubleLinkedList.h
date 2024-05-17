#pragma once

typedef struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void displayList(Node*);
void generateRandomList(Node **, int);