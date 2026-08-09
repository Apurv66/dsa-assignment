#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

void display(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}

int insert(int a[], int n, int index, int x){
    if(n>=MAX_SIZE){
        printf("array is full!");
        return -1;
    }
    if(index < 0 || index > n){
        printf("Invalid index!");
        return n;
    }
    for(int i=n-1; i>=index; i--){
        a[i+1]=a[i];
    }
    a[index]=x;
    return n+1;
}

int delete(int a[], int n, int index){
    for(int i=index; i<n-1; i++){
        a[i]=a[i+1];
    }
    return n-1;
}

int search(int a[], int n, int x){
    for(int i=0; i<n; i++){
        if(a[i]==x){
            return i;
        }
    }
    return -1;
}

int max_element(int a[], int n){
    int max=a[0];
    if(n == 0){
        printf("array is empty!");
        return -1;
    }
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

int min_element(int a[], int n){
    int min=a[0];
    if(n == 0){
        printf("array is empty!");
        return -1;
    }
    for(int i=0; i<n; i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}

void menu(){
    printf("\n1. display\n2. insert\n3. delete\n4. search\n5. max\n6. min\n7. exit");
}

int main(){
    int a[MAX_SIZE];
    int n=0;
    int index;
    int x;
    int ans;
    while (1)
    {
        menu();
        int choice;
        printf("\nenter choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("\nelements: ");
                display(a,n);
                break;
            case 2:
                printf("\nenter index: ");
                scanf("%d",&index);
                printf("\nenter x: ");
                scanf("%d",&x);
                n = insert(a, n, index, x);
                break;
            case 3:
                printf("\nenter index: ");
                scanf("%d",&index);
                n = delete(a,n,index);
                break;
            case 4:
                printf("\nenter x: ");
                scanf("%d",&x);
                ans = search(a, n, x);
                printf("\n%d found at index %d",x,ans);
                break;
            case 5:
                ans = max_element(a,n);
                printf("\nmaximum element: %d", ans);
                break;
            case 6:
                ans = min_element(a,n);
                printf("\nminimum element: %d", ans);
                break;

            case 7:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}