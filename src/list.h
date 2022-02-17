#ifndef LIST_H
#define LIST_H
struct node* add_dors(struct node* door, int nunber);
struct node* init(struct node* door);
struct node* add_door(struct node* elem, struct node* door);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
struct node {
    int id;
    struct node *next;
};

#endif  // LIST_H
