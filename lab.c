#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void printer() {
    printf("\nYou called print function\n");
    struct node *i = start;
    while (i != NULL) {
        printf("%d ", i->data);
        i = i->next;
    }
}

void createNode() {
    int d;
    printf("\nEnter Data part: ");
    scanf("%d", &d);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct node *i = start;
        while (i->next != NULL) {
            i = i->next;
        }
        i->next = newnode;
    }
}

void insertBegin() {
    printf("\nYou called Insert Begin function\n");

    int d;
    printf("Enter Data part: ");
    scanf("%d", &d);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = start;
    start = newnode;
}

void insertLast() {
    printf("\nYou call Insert Last function\n");

    int d;
    printf("Enter Data part: ");
    scanf("%d", &d);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct node *i = start;
        while (i->next != NULL) {
            i = i->next;
        }
        i->next = newnode;
    }
}

void insertAny() {
    printf("\nYou call Insert Any function\n");

    int d;
    printf("Enter data part: ");
    scanf("%d", &d);

    int val;
    printf("After which you want to insert: ");
    scanf("%d", &val);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;

    if (start == NULL) {
        printf("No element exist!! So insert first.\n");
        start = newnode;
    } else {
        struct node *i = start;
        while (i != NULL && i->data != val) {
            i = i->next;
        }

        if (i == NULL) {
            printf("Value %d not found in the list!!\n", val);
            free(newnode);
        } else {
            newnode->next = i->next;
            i->next = newnode;
        }
    }
}

void deleteFirst() {
    printf("\nYou called Delete First function\n");

    if (start == NULL) {
        printf("Under Flow\n");
    } else {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
}

void deleteLast() {
    printf("\nYou called Delete Last function\n");

    if (start == NULL) {
        printf("Under Flow\n");
        return;
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    } else {
        struct node *i = start;
        while (i->next->next != NULL) {
            i = i->next;
        }
        free(i->next);
        i->next = NULL;
    }
}

void deleteAny() {
    printf("\nYou called Delete Any function\n");
    int d;
    printf("Which element do you want to delete: ");
    scanf("%d", &d);

    if (start == NULL) {
        printf("Under flow\n");
    } else if (start->data == d) {
        struct node *temp = start;
        start = start->next;
        free(temp);
    } else {
        struct node *i = start;
        while (i->next != NULL && i->next->data != d) {
            i = i->next;
        }
        if (i->next == NULL) {
            printf("Element %d not found\n", d);
        } else {
            struct node *temp = i->next;
            i->next = i->next->next;
            free(temp);
        }
    }
}

int main() {
    insertBegin();
    insertLast();
    insertAny();
    deleteFirst();
    printer();

    return 0;
}
