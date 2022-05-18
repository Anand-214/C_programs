/*Documentation
Name:- Anand Arvind Kulkarni.
Date:- 28/10/2021
Description:- WAP to print sizes of all data types in C.
Sample Execution:- Size of int:    4bytes
                   Size of char:   1bytes
                   Size of float:  4bytes
                   Size of double: 8bytes
Documentation*/
//In The program the %zu format specifier and the operator "sizeof" is used to get the size of respective datatype.

#include<stdio.h>
int main()      //main function.
{                                          
    printf("The size of integer is:		   %zu bytes\n",sizeof(int));   //int data type for integers.
    printf("The size of unsigned integer is:   %zu bytes\n",sizeof(unsigned int)); //unsigned int for unsigned integers.
    printf("The size of long integer is:	   %zu bytes\n",sizeof(long int));  //long int data type for long integers.
    printf("The size of long long integer is:  %zu bytes\n",sizeof(long long int)); //long long int for long long integers.
    printf("The size of short integer is:	   %zu bytes\n",sizeof(short));  //short for short integers.
    printf("The size of float is:		   %zu bytes\n",sizeof(float));  //float data type for float (real integers)size.
    printf("The size of double is:		   %zu bytes\n",sizeof(double));  //double to get size of double data type.
    printf("The size of long double is:	   %zu bytes\n",sizeof(long double)); //size of long double data types.
    printf("The size of void is:		   %zu bytes\n",sizeof(void)); //size in bytes for void data types.
    printf("The size of character is:	   %zu bytes\n",sizeof(char));  //size in bytes for character data types.
    printf("The size of unsigned character is: %zu bytes\n",sizeof(unsigned char)); //size for usigned characters.
return 0;
}
