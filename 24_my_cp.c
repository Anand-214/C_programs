/*Documentation:
Name: Anand Arvind Kulkarni.
Date: 25/12/2021.
Description: Implementation of my_cp() function.
Sample Execution:
❯ ./a.out file.txt 2file.txt
Content of file.txt copied successfully in 2file.txt
❯ ./a.out file.txt 
Destination file missing.
❯ ./a.out 
ERROR:File names not passed
❯ ./a.out qwerty.txt file.txt 
qwerty.txt: No such file exists.
 */

#include<stdio.h>
char ch;  //global variable declaration.
int my_cp (FILE*, FILE* );   //function prototype.
int main(int argc, char* argv[])  
{
    if (argc == 1)   //if not file name passed as command line argument.
	printf("ERROR:File names not passed\n");
    else if( argc == 3)   //to check if 2 file names are passed or not.
    {
	FILE* fpo = fopen(argv[1],"r");   //open the file at argv[1] in read mode.
	if ( fpo != NULL)       //file pointer return NULL when file doesnt exists.
	{
	    FILE* fpw = fopen(argv[2],"w");   //open the file at argv[2] in  write mode.(create file is not present)
	    my_cp (fpo, fpw);   //function call with both file pointers are parameters.
	    fclose(fpo);
	    fclose(fpw);
	    printf("Content of %s copied successfully in %s",argv[1],argv[2]);   //confirmation message.
	}
	else
	    printf("ERROR : %s : No such file exists.\n",argv[1]);   
    }
    else
	printf("ERROR: Destination file missing.\n");
}

int my_cp (FILE* fpo, FILE* fpw)    //function definition to copy the content of one file to other.
{
    while ((ch = getc(fpo)) != EOF)
	putc (ch,fpw);
}
