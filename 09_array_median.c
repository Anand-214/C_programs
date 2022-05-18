/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 15/11/2021.
Description: Program to find the median of two unsorted arrays.
Sample Execution: ./median_arrays.out
Enter the 'n' value of Array A:5
Enter the elements one by one for Array A:3 2 8 5 4
After sorting:2 3 4 5 8
Median of Array1:4
Enter the 'n' value of Array B:5
Enter the elements one by one for Array B:12 3 7 8 5
After sorting:3 5 7 8 12
Median of Array2:7
Median of both arrays:5.5
 */

#include<stdio.h>
int main()
{
    int size1, size2, temp;       //variables with integer datatype are declared here.
    float median1, median2, res;  //variables with float data type are declared here.
    char choice;                  //variables with character data types are declared here.  
    do                     //do-while loop initiated.If the user wish to continue then below program executes again.
    {
	printf("Enter the 'n' value of Array A:"); //user asked to enter the size of first array.
	scanf("%d", &size1);             //the size is read using %d format specifier as it is an integer value.
	if ( size1 > 0 && size1 < 11)   //we check if the array size is within the desired limits (0 < size < 11).
	{
	    printf("Enter the elements one by one for Array A:");   //user asked to enter the elements of first array.
	    int arr1[size1];        //the array with integer data type is declared here.
	    for (int i=0; i<size1; i++)   //for loop to read each element of first array.
	    {
		scanf("%d", &arr1[i]);    //here for each iteration one element will be read, resulting the complete array.
	    }    
	    //sorting the elements of array in ascending order.
	    for (int i=0; i<size1; i++)   //here we start the loop from the 0th element of first array.
	    {
		for (int j=i+1; j<size1; j++) //here we skip the 0th element and start loop from the 1st element.
		{
		    if ( arr1[j] < arr1[i]) //condition to compare the the value of iterating 'j' with iterating 'i'.
		    {                       //The condition is true if iterating 'j' is less than 'i'.
			temp = arr1[i];  //value of 'i' transfered to variable temp.
			arr1[i] = arr1[j];  //value of 'j' is stored as value of 'i'.
			arr1[j] = temp;   //value of the temp is stored as value of 'j'.
		    }     //This operation results in sorting of the complete array elements in ascending order.
		}
	    }
	    printf("After sorting:");
	    for (int l=0; l<size1; l++)   //loop to print the array till elements equal to its size.
	    {
		printf("%d ", arr1[l]);   //The sorted array elements are printed one by one while loop iterates.   
	    }
	    printf("\n");    
	    printf("Median of Array1:");  //printing the median of array1.
	    if ( size1%2 )                //condition to check if the size of array1 is odd.
	    {                            //if the size is odd then the middle element is the median of the array.
		median1= arr1[size1/2];  //calculating the middle element of the array.
		printf("%g", median1);   //printing the median if the array size is odd.
	    }
	    else                        //condition true if the array size is even.
	    {         //if the size of array is even we need two centre elements to calculate the median.
		int element1 = arr1[size1/2];  //this gives the second of the two required elements. 
		int element2 = arr1[(size1/2)-1];  //this gives the first of the two required elements.
		median1 = ((float)element1 + element2)/2;  //we use explicit declaration to get the value in float form.
		printf("%g", median1);      //printing the median of the array if the size is even.
	    }
	    printf("\n");
	    printf("Enter the 'n' value of Array B:"); //user asked to enter the size of second array.
	    scanf("%d", &size2);             //the size is read using %d format specifier as the value is integer.
	    if ( size2 > 0 && size2 < 11)    //to check if the array size is within desired limits.
	    {
		printf("Enter the elements one by one for Array B:");  //user asked to enter the elements of second array.
		int arr2[size2];  //the array2 with integer data type is declared here.
		for (int i=0; i<size2; i++)  //for loop to read each element of second array.
		{
		    scanf("%d", &arr2[i]); //for each iteration one element will be read giving the complete array.
		}
		for (int i=0; i<size2; i++)  //loop started from the 0th element.
		{
		    for (int j=i+1; j<size2; j++)  //loop started from the 1st element as we need not want the 0th value.
		    {
			if ( arr2[j] < arr2[i]) //after comparing condition true if iterating 'j' is smaller than 'i'.
			{
			    temp = arr2[i];  //value of i stored in a variable temp.
			    arr2[i] = arr2[j]; //value is 'j' is stored in value of 'i'.
			    arr2[j] = temp;   //the value which was stored in temp is now stored in 'j'
			}    //this operation sorts the elements of second array in ascending order.
		    }
		}
		printf("After sorting:");
		for (int l=0; l<size2; l++)   //loop to print the sorted array.
		{
		    printf("%d ", arr2[l]);   //each sorted element will be printed for each iteration.
		}
		printf("\n");   
		printf("Median of Array2:"); //printing the median of array2.
		if ( size2 % 2 )             //condition true is the size is odd.
		{
		    median2= arr2[size2 / 2];  //to get the middle element of the array.
		    printf("%g", median2);  //printing the middle element as it is the median if the size is odd. 
		}
		else                      //condition true if the size of array is even.
		{              //if the size of array is even we need two elements from the centre to get the median.
		    int element1 = arr2[size2 / 2];  //this gives the second of the two centre elements.
		    int element2 = arr2[(size2/2) - 1]; //this gives the first of the two centre elements.
		    median2 = ((float)element1 + element2) / 2; //we use explicit declaration to get o/p as a float value.
		    printf("%g", median2);    //the addition of these two elements divided by 2 gives the median.
		}
		printf("\n");    //new line for the final median.
		printf("Median of both the arrays:");  //combined median of both the arrays.
		res = ((median1 + median2) / 2); //addition of the obtained two median when divided by 2 gives final median.
		printf("%g\n", res);  //the final median is a float value  hence used %g to print the o/p.
	    }
	    else    //condition executes if the size of array2 exceeds the desired limit. (0<size<11). 
	    {
		printf("Error:Max array size exceeded.\n"); //error message. 
	    }
	}
	else       //condition executes if the size of array1 is beyond the desired limits.
	{
	    printf("Error:Max Array size exceeded.\n");  //error message.
	}
	printf("Do you want to continue?(y/Y):");  //user asked if they want to continue with new array inputs.
	scanf(" %c", &choice);   //the i/p is character value hence %c format specifier is used.
    }while (choice == 'y' || choice == 'Y'); //do-while loop executes when the i/p is either 'y' or 'Y' else end program.
    return 0;
}     
