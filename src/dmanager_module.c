#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000
// #define DMANAGER_MODULE_C

void initialize_doors(struct door* doors);
void quick_sort(struct door *a, int first, int last);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    #ifdef DMANAGER_MODULE_C
    initialize_doors(doors);
    quick_sort(doors, 0, DOORS_COUNT - 1 );
    output(doors);
    #endif  // DMANAGER_MODULE_C
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors)
{
    srand(time(0)); 
    
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void quick_sort(struct door *a, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = a[(left + right) / 2].id;
        do {
            while (a[left].id < middle)
                left++;
            while (a[right].id > middle)
                right--;
            if (left <= right) {
                int time = a[left].id; a[left].id = a[right].id; a[right].id = time;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i ++)
        doors[i].status = 0;
    for (int i = 0; i < DOORS_COUNT; i ++) {
        if (i == DOORS_COUNT - 1) {
            printf("%d, %d", doors[i].id, doors[i].status);
            break;
        }
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
