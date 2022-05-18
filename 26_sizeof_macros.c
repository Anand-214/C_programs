/*Documentation
Name: Anand Arvind Kulkarni
Date: 19/12/2021
Description: Program to define a macro SIZEOF(x) without using sizeof operator.
Size of integer: 4 bytes
Size of character: 1 bytes
Size of float: 4 bytes
Size of double: 8 bytes
Size of unsigned int: 4 bytes
Size of long int: 8 bytes
 */

#include<stdio.h>

//Defining the MACRO
#define SIZE_OF(x) (char *)(&x + 1) - (char *) &x

int main()
{	
    //Declaring the variables according to the data type for which the size is to be printed.
    int a;
    char ch;
    float f;
    double d;
    unsigned int ui;
    long int li;
    //The following printf statements will display the size occupied by each variable.
    printf("Size of integer: %zu bytes\n", SIZE_OF(a)); 
    printf("Size of character: %zu bytes\n", SIZE_OF(ch));
    printf("Size of float: %zu bytes\n", SIZE_OF(f));
    printf("Size of double: %zu bytes\n", SIZE_OF(d));
    printf("Size of unsigned int: %zu bytes\n", SIZE_OF(ui));
    printf("Size of long int: %zu bytes\n", SIZE_OF(li));

    return 0;
}
