#include <stdio.h>
#include <stdlib.h>

int *ptr = NULL;
int size = 0;

void allocate_malloc() {
    printf("enter size: ");
    scanf("%d", &size);
    ptr = (int*) malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("allocation failed\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("enter value %d: ", i);
        scanf("%d", (ptr + i));
    }
    printf("memory allocated at: %p\n", ptr);
}

void allocate_calloc() {
    printf("enter size: ");
    scanf("%d", &size);
    ptr = (int*) calloc(size, sizeof(int));
    if (ptr == NULL) {
        printf("allocation failed\n");
        return;
    }
    printf("memory allocated at: %p\n", ptr);
}

void resize_realloc() {
    int new_size;
    printf("enter new size: ");
    scanf("%d", &new_size);

    int *temp = (int*) realloc(ptr, new_size * sizeof(int));
    if (temp == NULL) {
        printf("realloc failed\n");
        return;
    }

    ptr = temp;
    size = new_size;
    printf("memory resized, new address: %p\n", ptr);
}

void display_values() {
    if (ptr == NULL) {
        printf("no memory allocated\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("value: %d address: %p\n", *(ptr + i), (ptr + i));
    }
}

void free_memory() {
    free(ptr);
    ptr = NULL;
    size = 0;
    printf("memory freed\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1.malloc 2.calloc 3.realloc 4.display 5.free 6.exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                allocate_malloc();
                break;
            case 2:
                allocate_calloc();
                break;
            case 3:
                resize_realloc();
                break;
            case 4:
                display_values();
                break;
            case 5:
                free_memory();
                break;
            case 6:
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
}