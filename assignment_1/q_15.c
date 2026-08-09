#include <stdio.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    char branch[50];
    float marks;
};

void sort_student(struct Student s[], int n){
    struct Student temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if (s[j].marks < s[j + 1].marks){
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student s[MAX];
    int n;

    printf("enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("\nstudent %d\n", i + 1);

        printf("roll no: ");
        scanf("%d", &s[i].roll);

        printf("name: ");
        scanf("%s", s[i].name);

        printf("branch: ");
        scanf("%s", s[i].branch);

        printf("total marks: ");
        scanf("%f", &s[i].marks);
    }

    sort_student(s, n);

    printf("\nsorted student records:-");
    for(int i = 0; i < n; i++) {
        printf("\nroll: %d | name: %s | branch: %s | marks: %.2f\n", s[i].roll, s[i].name, s[i].branch, s[i].marks);
    }

    return 0;
}