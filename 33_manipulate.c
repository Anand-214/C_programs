/*Documentation
Name: Anand Arvind Kulkarni
Date: 31/12/2021
Description: Provide a menu to manipulate and display the value of variable of type t.
Sample Execution: /mem_manager
Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1
Enter the type you have to insert:
1. int
2. char
3. float
4. double
Choice ---> 2
Enter the char : k
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 2
0 -> k
1 -> 10
Enter the index value to be deleted : 0
index 0 successfully deleted.
1. Add element
2. Remove element
3. Display element
4. Exit from the program
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
    void* ptr = malloc(8);                    //void ptr to store any type of data to allocated memory               
    void* ptr1 = ptr;                         //base address of allocated memory stored in another pointer for reference
    int flag_1 = 0, flag_2 = 0, flag_4 = 0, flag_8 = 0, float_val = 0, choice, option;
    for(int i = 0; i <= 100; i++)
    {
	printf("Menu : \n1.Add elements \n2.Remove elements \n3.Display elements \n4.Exit from program \n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		{
		    printf("Menu:\n1.int \n2.char \n3.float \n4.double \n5.short\n");
		    printf("Enter the data type: ");
		    scanf("%d", &option);
		    switch(option)
		    {
			case 1:
			    {
				if((flag_4) == 0)   //flag_4 for integer as well as float (occupies 4 bytes)
				{
				    printf("Enter int : ");
				    ptr = ptr1;
				    //int is stored after the first 2 bytes as first 2 bytes are reserved for char.
				    ptr = ((char*) ptr + 2);     
				    scanf("%d", (int*)ptr);
				    flag_4 = 1;
				}
				else
				    printf("Out of Memory.\n");
			    }
			    break;
			case 2:
			    {
				if((flag_1) < 2)        //flag_1 for charactertype data.( occupies 1 byte.)
				{
				    printf("Enter char : ");
				    ptr = ptr1;
				    if(flag_1 == 1)
					scanf(" %c", ((char*)ptr + 1));
				    else
					scanf(" %c", ((char*)ptr));
				    flag_1++;
				}
				else
				    printf("Out of Memory.\n");
			    }
			    break;
			case 3:
			    {
				if((flag_4) == 0)
				{
				    printf("Enter float: ");
				    ptr = ptr1;
				    ptr = ((char*)ptr + 2);  //int and float allocated same 4 bytes memory therefore incrementing 2 bytes
				    scanf("%f", (float*)ptr);
				    flag_4 = 1;
				    float_val = 1;           //float_val represents if float value is present in memory or not
				}
				else
				    printf("Out of Memory.\n");
			    }
			    break;
			case 4:
			    {
				//flag_8 for double type data.(Occupies 8 bytes)
				if((flag_1 == 0 && flag_2 == 0 && flag_4 == 0 && flag_8 == 0)) 
				{
				    ptr = ptr1;
				    printf("Enter double: ");
				    scanf("%lf", ((double*)ptr)); //storing double value
				    flag_8 = 1;
				}
				else
				    printf("Out of Memory.\n");
			    }
			    break;
			case 5:
			    {
				if(flag_2 == 0)      //flag_2 for short int (occupies 2 bytes)
				{
				    printf("Enter short: ");
				    ptr = ptr1;
				    ptr = ((char*)ptr + 6); //increment by 6 as for short the memory reserved is after 6.
				    scanf("%hd", (short*)ptr);
				    flag_2 = 1;      //updating flag
				}
				else
				    printf("Out of Memory.\n");
			    }
			    break;
		    }
		    break;
		    case 2:
		    {
			int index;
			printf("Enter the index of number to be removed: ");
			scanf("%d", &index);
			if(index == 0 && flag_8 == 1)
			{
			    flag_8 = 0;
			}
			else
			{
			    if((index == 0 && flag_1 > 0) || (index == 1 && flag_1 > 0))
			    {
				flag_1--;  //decrementing the flag after data removal.
			    }
			    if((index == 2 && flag_4 == 1))
				flag_4 = 0;
			    if(index == 6 && flag_2 == 1)
				flag_2 = 0;
			}
			printf("Index %d successfully deleted\n", index);
		    }
		    break;
		    case 3:
		    {
			ptr = ptr1;
			int count = 0;
			if(flag_8 == 1)
			    printf("%lf\n", (*(double*)ptr));
			if(flag_1 > 1 && count == 0)
			{
			    while(count <= 1)
			    {
				printf("%c\n", *((char*)ptr + count));
				count++;
			    }
			}
			else if(flag_1 == 1 && count == 0)
			{
			    printf("%c\n",*((char*)ptr));       //displaying character data
			    count++;
			}
			ptr = ptr1;
			ptr= ((char*) ptr + 2);
			if(flag_4 == 1 && float_val == 0)
			    printf("%d\n", *((int*)ptr));            //displaying int data
			else if(flag_4 == 1 && float_val == 1)
			    printf("%f\n", *((float*)ptr));          //displaying float data
			ptr = ptr1;
			ptr = (char*)ptr+6;
			if(flag_2 == 1)
			    printf("%hd\n", *(short*)ptr);           //displaying short data
		    }
		    break;
		    case 4:
		    {
			return 0;                                     //exit from the program
		    }
		}
	}
    }
}
