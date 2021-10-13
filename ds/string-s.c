#include<stdio.h>
#include<string.h>

/*
Perform the various string operations using built-in functions of it.
 Length of the string
 Copy one string to another
s Concate the string
 Find the substring
 Compare two strings

*/

int my_strlen(char str[]){
    int i;
    for (i = 0; str[i] != '\0'; i++);    
    return i;
}

void my_strcpy(char dest[], char src[]){
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return;
}

int main(int argc, char const *argv[])
{
    char str[10];
    char str1[10];

    //read string from user
    printf("Enter string : ");
    scanf("%s", str);

    printf("\nYou have entered %s ", str);

    int len;
    len = my_strlen(str);
    printf("\nLength of string is %d", len);

    my_strcpy(str1, str);
    printf("\n Copied string is %s", str1);

    printf("\n");
    return 0;
}
