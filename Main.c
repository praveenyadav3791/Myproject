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

void displayHistory() {
    Node *temp = head;
    if (!temp) {
        printf("History is empty.\n");
        return;
    }
    printf("Browser History:\n");
    while (temp) {
        if (temp == current) printf("-> %s (Current Page)\n", temp->url);
        else printf("   %s\n", temp->url);
        temp = temp->next;
    }
}

void goBackward() {
    if (current && current->prev) {
        current = current->prev;
        printf("Moved Backward. Current page: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}


void goForward() {
    if (current && current->next) {
        current = current->next;
        printf("Moved Forward. Current page: %s\n", current->url);
    } else {
        printf("No forward page.\n");
    }
}

void searchWebsite(char url[]) {
    Node *temp = head;
    int pos = 1;
    while (temp) {
        if (strcmp(temp->url, url) == 0) {
            printf("Website '%s' found at position %d.\n", url, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Website '%s' not found in history.\n", url);
}

void clearHistory() {
    Node *temp = head;
    while (temp) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    head = current = NULL;
    printf("History cleared.\n");
}

