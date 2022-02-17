#include "list.h"
#include "list.c"
#include <stdio.h>
// void init_test(struct node* door); 
// void add_door_test(struct node* door);
// void find_door_test(struct node* door);
// void remove_door_test(struct node* door);
// void destroy_test(struct node* door);

int main() {

    struct node *doors;

    init(doors);
    add_door(doors, doors);
    add_door(doors, doors);
    

    
    // for (int i = 0; i< 2; i++)
    //     printf(" %d", doors[i].id);

    struct node *tmp = doors;
    while (tmp -> next != NULL) {
        printf(" %d", tmp -> id);
        // if (tmp -> next != NULL)
        tmp = tmp -> next;
    }
    destroy(doors);

    return 0;
}
// void init_test(struct node* door); {

// }
// void add_door_test(struct node* door) {}
// void find_door_test(struct node* door) {}
// void remove_door_test(struct node* door) {}
// void destroy_test(struct node* door) {}

void assect(int flag) {
    if (flag == 0)
        printf("\nSUCCESS\n");
    else
        printf("\nFAIL\n");
}
