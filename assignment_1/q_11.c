#include<stdio.h>
#include<stdlib.h>

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    return a/b;
}

int modulus(int a, int b){
    return a%b;
}

void menu(){
    printf("\n1. add\n2. subtract\n3. multiply\n4. divide\n5. modulus\n6. exit");
}

int main(){
    int a;
    int b;
    int ans;
    printf("\na: ");
    scanf("%d",&a);
    printf("\nb: ");
    scanf("%d",&b);
    while(1){
        menu();
        int choice;
        printf("\nenter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("a + b = %d",add(a,b));
                break;
            case 2:
                printf("a - b = %d",subtract(a,b));
                break;
            case 3:
                printf("a * b = %d",multiply(a,b));
                break;
            case 4:
                printf("a / b = %d",divide(a,b));
                break;
            case 5:
                printf("a mod b = %d",modulus(a,b));
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}