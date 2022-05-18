/*
Name : Anand Arvind Kulkarni.
Date : 25/12/2021.
Description : WAP to implement the student record using array of structures.
Sample execution:
Enter number of students : 2
Enter number of subjects : 2
Enter name of the Subject 1 : Maths
Enter name of the Subject 2 : Science
-------------------------Enter students details--------------------
Enter the student 1 Roll Number : 1
Enter the student 1 name : Nandu
Enter the Maths mark : 99
Enter the Science mark : 91
-------------------------Enter students details--------------------
Enter the student 2 Roll Number : 2
Enter the student 2 name : Bindu
Enter the Maths mark : 88
Enter the Science mark : 78
-----------------------DISPLAY MENU-----------------------------
1. All Student Details
2. Particular Student Details
Enter your choice : 2
-----------------------Menu for particular student--------------------
1. Name
2. Roll no
Enter your choice: 1
Enter name of the student : Nandu
Roll No	Name	Maths	Science	Average		Grade
1	Nandu	99	91	95		A
Do you want to continue to display(y/Y) : n
Do you want to repeat the operation (y/Y) : n
 */

#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *str1, char *str2);     // function prototypes.
char grade(float avg);

struct student              // structure definition.
{
    int roll_num;
    char name[50];
    int *mark;
};

int main()
{
    char ch1, ch2;
    do
    {
	int no_of_students = 0, no_of_subjects = 0;
	char (*str)[30];
	int option, choice;
	float sum = 0, avg = 0;

	printf("Enter number of students : ");    // user prompt and read num of students and subject details.
	scanf("%d", &no_of_students);
	printf("Enter number of subjects : ");
	scanf("%d", &no_of_subjects);

	str = malloc (sizeof(*str) * no_of_subjects);    // Memory allocation to store subject

	struct student S[no_of_students];    // structure variable declaration

	for (int i = 0; i < no_of_subjects; i++)
	{
	    printf("Enter name of the Subject %d : ", i + 1 );                   
	    scanf("%s", str[i]);            // read subject name
	}

	for (int i = 0; i < no_of_students; i++)
	{
	    printf("-------------------------Enter students details--------------------\n");
	    printf("Enter the student %d Roll Number : ", i + 1);
	    fflush(stdin);
	    scanf("%d", &S[i].roll_num);                 // Read roll num from user
	    printf("Enter the student %d name : ", i + 1);
	    fflush(stdin);
	    scanf("%s",S[i].name);      // Read name from user

	    S[i].mark = (int *)malloc ( sizeof(int) * no_of_subjects); // Memory allocation to store mark of each student.

	    for (int j = 0; j < no_of_subjects; j++)
	    {
		printf("Enter the %s mark : ", str[j]);
		scanf("%d", &S[i].mark[j]);                               // read mark from user
	    }
	}
	do
	{
	    printf("-----------------------DISPLAY MENU-----------------------------\n");
	    printf("1. All Student Details\n2. Particular Student Details\nEnter your choice : ");
	    scanf("%d", &option);

	    switch (option)
	    {
		case 1 :
		    printf("Menu for All Student Details\n");
		    printf("Roll no\tName\t");

		    for(int j = 0; j < no_of_subjects; j++)
		    {
			printf("\t%s\t", str[j]);                // printing subjects 
		    }

		    printf("\tAverage\tGrade\n");

		    for (int i = 0; i < no_of_students; i++)
		    {
			sum = 0;
			for (int j = 0; j < no_of_subjects; j++)
			{
			    sum = sum + S[i].mark[j];                       // adding mark for each student
			}
			printf("%d\t%s\t", S[i].roll_num, S[i].name);   // display roll num and name

			for (int j = 0; j < no_of_subjects; j++)
			{
			    printf("\t%d\t", S[i].mark[j]);          // display mark of each subject
			}

			avg = sum / no_of_subjects;                       // finding avg for each student

			printf("\t%g\t%c\n", avg, grade(avg));        // display avg and grade
		    }

		    break;
		case 2 : 
		    {
			printf("-----------------------Menu for particular student--------------------\n");
			printf("1. Name\n2. Roll no\nEnter your choice: ");
			scanf("%d", &choice);

			if (choice == 1)
			{
			    char student_name[40];

			    printf("Enter name of the student : ");   // Prompt user and read student name.
			    scanf("%s", student_name);

			    sum = 0;
			    avg = 0;
			    int count = 0;

			    for (int i=0; i < no_of_students; i++)
			    {

				if ( my_strcmp (student_name, S[i].name) == 0)  // function call to check name in database.
				{
				    count++;
				    printf("Roll No\tName\t");

				    for(int j = 0; j < no_of_subjects; j++)
				    {
					printf("%s\t", str[j]);
					sum = sum + S[i].mark[j];
				    }

				    avg = sum / no_of_subjects;

				    printf("Average\t\tGrade\n");
				    printf("%d\t%s\t", S[i].roll_num, S[i].name);

				    for(int j = 0; j < no_of_subjects; j++)
				    {
					printf("%d\t", S[i].mark[j] );
				    }

				    printf("%g\t\t%c\n", avg, grade(avg));

				}
			    }
			    if (count == 0)
			    { 
				printf("%s student detail is not available\n", student_name);
			    }
			}
			else if ( choice == 2)
			{
			    int number;
			    sum = 0;
			    avg = 0;                                  
			    printf("Enter the Student Roll Number : ");
			    scanf("%d", &number);

			    for (int i=0; i < no_of_students; i++)
			    {
				if ( number == S[i].roll_num )           // comparing roll number to match with exisiting.
				{
				    printf("Roll No\tName\t");

				    for(int j=0; j < no_of_subjects; j++)
				    {
					printf("%s\t", str[j]);
					sum = sum + S[i].mark[j];
				    }
				    avg = (sum / no_of_subjects);

				    printf("Average\t\tGrade\n");

				    printf("%d\t%s\t", S[i].roll_num, S[i].name);

				    for(int j=0; j < no_of_subjects; j++)
				    {
					printf("%d\t", S[i].mark[j] );
				    }

				    printf("%g\t\t%c\n", avg, grade(avg));
				}

			    }
			}
			else if (choice != 1 && choice != 2)
			{
			    printf("Enter valid option\n");
			}

			break;
		    }

		default :
		    printf("Error : Invalid choice \n");
		    break;
	    }

	    printf("Do you want to continue to display(y/Y) : ");   //User prompt and read the i/p to continue or not.
	    scanf(" %c", &ch2);

	}while (ch2 == 'Y' || ch2 == 'y');        //do-while loop executed if condition true. 

	free(str);
	str = NULL;
	printf("Do you want to repeat the operation (y/Y) : ");     //ask user if they want to continue the operation.
	scanf(" %c", &ch1);

    }while (ch1 == 'Y' || ch1 == 'y');        //do-while loop executed if condition true.

    return 0;
}

char grade(float avg)    //function to determine the grade of the student.
{
    if ( avg >= 90 )
    {
	return 'A';
    }
    else if (avg >= 80 && avg < 90)
    {      
	return 'B';
    }
    else if (avg >= 70 && avg < 80)
    {
	return 'C';
    }
    else if (avg >= 60 && avg < 70)
    {
	return 'D';
    }
    else if (avg >= 50 && avg < 60)
    {
	return 'E';
    }
    else
    {
	return 'F';
    }
}

int my_strcmp( char *str1, char *str2)
{
    // compare two strings with case insensitive.
    while ( (*str1 && *str2) && (*str1 == *str2) || (*str1 - 32 == *str2) || (*str1 == *str2 - 32) )
    {
	str1++;
	str2++;
    }
    return *str2 - *str1;         // If both the strings are same means it will return 0 else. 
}
