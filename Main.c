#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;
Node *head = NULL, *current = NULL;


void visitWebsite(char url[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    newNode->prev = current;
    
    if (current) current->next = newNode;
    else head = newNode;
    
    current = newNode;
    printf("Visited: %s\n", url);
}
