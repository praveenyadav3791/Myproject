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



int main() {
    int choice;
    char url[100];
    while (1) {
        printf("\nBrowser History Manager \n");
        printf("1. Visit new website\n2. Delete a website\n3. Display history\n");
        printf("4. Go Backward\n5. Go Forward\n6. Clear history\n");
        printf("7. Search website\n8. Sort history alphabetically\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter website URL: ");
                scanf("%s", url);
                visitWebsite(url);
                break;
            case 3:
                displayHistory();
                break;
            case 4:
                goBackward();
                break;
            case 5:
                goForward();
                break;
            case 6:
                clearHistory();
                break;
            case 7:
                printf("Enter website to search: ");
                scanf("%s", url);
                searchWebsite(url);
                break;
            case 8:
                sortHistory();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

