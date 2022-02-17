#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#ifndef LIST_C
#define LIST_C

struct node* init(struct node* door) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node -> id = 0;
    node -> next = NULL;
    return node;
}

// struct node* add_dors(struct node* door, int nunber) {
//     if (door == NULL) return NULL;
//     struct node* p = door;
//     for (int i =0; i < nunber; i++) {
//         struct node* tmp = (struct node*) malloc(sizeof(struct node));
//         p -> next = tmp;
//         tmp -> id = 0;
//         tmp -> next = NULL;
//         p = p -> next;
//     }
//     return door;
// }

// struct node* add_door(struct node* elem, struct node* door) {
//     struct node *tmp = door, *p = NULL, *new = (struct node*) malloc(sizeof(struct node));
//     if (door == NULL) return NULL;
//     int count = 0;
//     while (tmp && tmp -> id != elem -> id){
//         p = tmp;
//         tmp = tmp -> next;
//         count++;
//     }
//     if (count) {
//         p = tmp;
//         tmp = tmp -> next;
//     }
//     if (!tmp) return door;
//     // p -> next = new;
//     new -> next = tmp;
//     new -> id = -1;
//     return new;
// }

struct node* add_door(struct node* elem, struct node* door) {
    struct node *current = init(door);
    if (elem != NULL) {
        current -> next = NULL;
        elem -> next = current;
    }
    return current;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = NULL;
    while ( root != NULL ) {
        if (root -> id == door_id) {
            current = root;
            break;
        } else {
            root = root -> next;
        }
    }
    return current;
}

// struct node* find_door(int door_id, struct node* root) {
//     struct node *tmp = root, *p = NULL;
//     if (root == NULL) return NULL;
//     while (tmp && tmp -> id != door_id) {
//         p = tmp;
//         tmp = tmp -> next;
//     }
//     if (!tmp) return root;
//     return tmp;
// }

struct node* remove_door(struct node* elem, struct node* root) {
    struct node *tmp = root, *p = NULL;
    if (root == NULL) return NULL;
    while (tmp && tmp -> id != elem -> id) {
        p = tmp;
        tmp = tmp -> next;
    }
    if (elem == root) {
        free(root);
        return tmp -> next;
    }
    if (!tmp) return root;
    p -> next = tmp -> next;
    free(tmp);
    return root;
}

// void destroy(struct node* root) {
//     while (root != NULL) {
//         struct node *p = root;
//         root = root -> next;
//         free(p); 
//     }
// }
void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next; 
        free(temp);
    }
}

#endif  // LIST_C
