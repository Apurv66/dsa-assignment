#include <stdio.h>
#include <string.h>

#define max 100

struct student {
    int roll;
    char name[50];
    char branch[50];
    float marks;
};

struct student s[max];
int count = 0;

void add_record() {
    printf("enter roll: ");
    scanf("%d", &s[count].roll);
    printf("enter name: ");
    scanf("%s", s[count].name);
    printf("enter branch: ");
    scanf("%s", s[count].branch);
    printf("enter marks: ");
    scanf("%f", &s[count].marks);
    count++;
}

int search_record(int roll) {
    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll)
            return i;
    }
    return -1;
}

void update_record() {
    int roll, i;
    printf("enter roll to update: ");
    scanf("%d", &roll);
    i = search_record(roll);
    if (i != -1) {
        printf("enter new name: ");
        scanf("%s", s[i].name);
        printf("enter new branch: ");
        scanf("%s", s[i].branch);
        printf("enter new marks: ");
        scanf("%f", &s[i].marks);
    } else {
        printf("record not found\n");
    }
}

void delete_record() {
    int roll, i;
    printf("enter roll to delete: ");
    scanf("%d", &roll);
    i = search_record(roll);
    if (i != -1) {
        for (int j = i; j < count - 1; j++) {
            s[j] = s[j + 1];
        }
        count--;
    } else {
        printf("record not found\n");
    }
}

void display_all() {
    for (int i = 0; i < count; i++) {
        printf("roll: %d name: %s branch: %s marks: %.2f\n",
               s[i].roll, s[i].name, s[i].branch, s[i].marks);
    }
}

int main() {
    int choice, roll;

    while (1) {
        printf("\n1.add 2.search 3.update 4.delete 5.display 6.exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                printf("enter roll to search: ");
                scanf("%d", &roll);
                int i = search_record(roll);
                if (i != -1)
                    printf("roll: %d name: %s branch: %s marks: %.2f\n",
                           s[i].roll, s[i].name, s[i].branch, s[i].marks);
                else
                    printf("record not found\n");
                break;
            case 3:
                update_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                display_all();
                break;
            case 6:
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
}