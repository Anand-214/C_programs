#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i, count = 0;
    char ch;
    printf("Enter the string:");
    scanf("%[^\n]s", str);
    count = strlen(str);
    /*    while ( str[i] != '\0')
    {
	count++;
	i++;
    }
*/    printf("Count : %d", count);
}


