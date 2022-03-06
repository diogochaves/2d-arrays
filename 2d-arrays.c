#include <stdio.h>	//printf
#include <stdlib.h>	// Malloc, Free, Exit

void	_2darray_single_pointer_(int rows, int columns) ;
void	_pointer_to_a_pointer_(int rows, int columns) ;

/*
How to dinamically allocate 2D arrays (matrix)

  1  2  3  4
  5  6  7  8
  9  10 11 12 

*/

int	main(void)
{
	int	rows;
	int	columns;

	rows = 3;
	columns = 4;

	printf(" ----------- \n| 2D Arrays |\n ----------- \n\n");

	// Using a single pointer and a 1D array with pointer arithmetic
	printf("_2darray_single_pointer_\n.\n");
	_2darray_single_pointer_(rows, columns);

	// Using pointer to a pointer
	printf("_pointer_to_a_pointer_\n.\n");
	_pointer_to_a_pointer_(rows, columns);

	return (0);
}

void	_2darray_single_pointer_(int rows, int columns)
{
	int *ptr;
	
	ptr = malloc((rows * columns) * sizeof(int));

	/* Putting 1 to 12 in the 1D array in a sequence */
	for (int i = 0; i < rows * columns; i++)
		ptr[i] = i + 1;

	/* Accessing the array values as if it was a 2D array */
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			printf("%d ", ptr[i * columns + j]);
		printf("\n");
	}
	printf(".\n\n");

	free(ptr);
}

void	_pointer_to_a_pointer_(int rows, int columns)
{
	int	i, j, count;
	int	**array;
	
	array = malloc(rows * sizeof(int*));
	for (i = 0; i < rows; i++)
		array[i] = malloc(columns * sizeof(int));

	// Note that array[i][j] is same as *(*(array+i)+j)
	count = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < columns; j++)
			array[i][j] = ++count; // OR *(*(array+i)+j) = ++count

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf("%d ", array[i][j]);
		printf("\n");
	}

	/* Code to free the dynamically allocated memory */
	for (int i = 0; i < rows; i++)
		free(array[i]);
	free(array);
}
