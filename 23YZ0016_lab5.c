#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    int priority;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int get_priority(char *caller) {
    if (strcmp(caller, "Annem") == 0 || strcmp(caller, "Babam") == 0 || strcmp(caller, "Kardesim") == 0)
        return 1;
    else if (strcmp(caller, "Amcam") == 0 ||strcmp(caller, "Dayim") == 0 || strcmp(caller, "Halam") == 0||strcmp(caller, "Teyzem") == 0)
        return 2;
    else if (strcmp(caller, "Isyeri") == 0 || strcmp(caller, "Okul") == 0)
        return 3;
    else if (strcmp(caller, "Arkadasim1") == 0 || strcmp(caller, "Arkadasim2") == 0 || strcmp(caller, "Arkadasim3") == 0 || 
             strcmp(caller, "Arkadasim4") == 0 || strcmp(caller, "Arkadasim5") == 0)
        return 4;
    else if (strcmp(caller, "Banka") == 0 || strcmp(caller, "Kargo") == 0)
        return 5;
    else if (strcmp(caller, "Reklam") == 0)
        return 6;
    else
        return 7; //Bilinmeyen girdi
}

struct node *insert_priority(struct node *start) {
    char callers[50];
    struct node *ptr, *ptr2;
    int priority_;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        return start;
    }
    fgets(callers, sizeof(callers), stdin);
    callers[strcspn(callers, "\n")] = 0; 

	if (strcmp(callers, "-1") == 0) {
        return NULL;
    }

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        return start;
    }

    priority_ = get_priority(callers);

    strcpy(ptr->data, callers);
    ptr->priority = priority_;
    ptr->next = NULL;

    if (start == NULL || priority_ < start->priority || 
       (priority_ == start->priority && strcmp(callers, start->data) < 0)) {
        ptr->next = start;
        start = ptr;
    } else {
        ptr2 = start;
        while (ptr2->next != NULL && 
              (ptr2->next->priority < priority_ || 
              (ptr2->next->priority == priority_ && strcmp(ptr2->next->data, callers) < 0))) {
            ptr2 = ptr2->next;
        }
        ptr->next = ptr2->next;
        ptr2->next = ptr;
    }

    return start;
}


void display(struct node *start) {
    struct node *ptr;
    ptr = start;
    if (start == NULL) {
        printf("Queue is empty.\n");
    } else {
    	//printf("\n"); 
        while (ptr != NULL) {
            printf("%s\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    struct node *start = NULL;
	while (1) {
        struct node *new_start = insert_priority(start);
        if (new_start == NULL) { 
            break;
        }
        start = new_start;
    }
    
    display(start);
    
    return 0;
}

