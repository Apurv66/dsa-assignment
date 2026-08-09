#include <stdio.h>

int length(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void reverse(char str[], char rev[]) {
    int len = length(str);
    for (int i = 0; i < len; i++){
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
}

int palindrome(char str[]) {
    int i = 0, j = length(str) - 1;
    while (i < j) {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int count_vowels(char str[]) {
    int i = 0, count = 0;
    while (str[i] != '\0') {
        char c = str[i];
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            count++;
        i++;
    }
    return count;
}

int compare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0'){
        return 0;
    }
    else{
        return 1;
    }
}

int main() {
    char str[100];
    char rev[100];
    char str2[100];

    printf("enter a string: ");
    scanf("%s", str);

    printf("length: %d\n", length(str));

    reverse(str, rev);
    printf("reverse: %s\n", rev);

    if (palindrome(str))
        printf("palindrome\n");
    else
        printf("not palindrome\n");

    printf("vowel count: %d\n", count_vowels(str));

    printf("enter another string to compare: ");
    scanf("%s", str2);

    if (compare(str, str2) == 0)
        printf("strings are equal\n");
    else
        printf("strings are not equal\n");

    return 0;
}