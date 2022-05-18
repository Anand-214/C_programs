#include<stdio.h>
#include<stdlib.h>
int function (int* entry)
{
    int  i,col,row,matrix,num;
    num = *entry;
    int magic_square[num][num];
    col = num/2;
    row = 0;
    matrix = num * num;
    for( i = 1; i <= matrix ; i++ )
    {
	magic_square[row][col] = i;
	// check for occupied value if so, go row++ and print.
	if( (i % num) == 0 )
	{
	    row++;
	}
	else
	{
	    // boundary for row.
	    if( row == 0 )
	    {
		row = num - 1;
	    }
	    else //next entry.
	    {
		row--;
	    }

	    //boundary for column.
	    if( col == ( num - 1 ) )
	    {
		col = 0;
	    }
	    else // next hop.
	    {
		col++;
	    }
	}
    }
    printf("\n");
    printf("The %dx%d magic square is:\n",*entry,*entry);
    for (row = 0; row < num; row++)
    {
	for (col = 0; col < num; col++)
	{
	    printf("%3d ", magic_square[row][col]);
	}
	printf("\n");
    }
    printf("\n");


}
int main()
{
    int i,entry,row,col;
    printf("Enter the number:");
    scanf("%d", &entry);
    if ( entry > 0)
    {
	if ( entry % 2 != 0)
	{
	    function (&entry);
	}
	else
	{	
	    printf("Error:Enter only positive odd numbers.\n");
	}
    }
    else
    {
	printf("Error:Enter only positive odd numbers.\n");
    }

}
