//header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv, char **envp)
{
    int option, n, sum = 0;
    float avg;
    {
	//asks the user to select the choice
	printf("1.Scan from keyboard\n2.Proceed with provided command line arguments\n3.Proceed with environmental variable arguments\n");
	printf("enter your choice: ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		{
		    printf("enter the total number of integers: ");
		    scanf("%d", &n);
		    int arr[n];
		    //asks the user to enter the elements
		    printf("enter the elements: ");
		    for(int i = 0; i < n; i++)
		    {
			scanf("%d",&arr[i]);
		    }
		    //for loop to get the sum of elements user entered
		    for(int i = 0; i < n; i++)
		    {
			sum = sum + arr[i];
		    }
		    avg = (float)sum / n;
		    //prints the average of the elements of array
		    printf("average of entered numbers: %g",avg);
		}
		break;
	    case 2:
		   //if no command line argument is passed this message is displayed
		    if(argc <= 1)
		    {
			printf("enter arguments in order to calculate average\n");
		    }
		    else
		    {
                        //dor loop to get the sum of command line arguments passed by user
			for(int i = 1; i < argc; i++)
			{
			    sum = sum + atoi(argv[i]);
			}
			avg = (float)sum / (argc - 1);
			//prints the average of the  command line arguments passed
		        printf("average of entered numbers: %g",avg);
		    }
		break;
	    case 3:
		{
		    int count = 0, num[50];
		    char *arr; char *t;
		    //getenv searches for the env variable of the entered name
		    arr = getenv("ARR");
		    //strtok is used to get the data stored in ARR variable
		    t = strtok(arr, " ");
                    //while loop is used to get the each data in env var untill condition is true 
		    while(t != NULL)
		    {
			count++;
			//this stores the each data in num array at the count index
			num[count] = atoi(t);
			sum += num[count];
			t = strtok(NULL, " ");
		    }
		    avg = (float)sum / count;
		    //prints the average from the env var
		    printf("the average of entered numbers: %g",avg);
		}
		break;
	}

    }
}
