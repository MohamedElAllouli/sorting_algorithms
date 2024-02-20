#include "sort.h"
/**
*swap_helper - swap positions of two elements into an array
*@array: array of integer
*@n1: size of array element
*@n2: size of array element
*/
void swap_helper(int *array, ssize_t n1, ssize_t n2)
{
	int tmp;

	tmp = array[n1];
	array[n1] = array[n2];
	array[n2] = tmp;
}
/**
 *partition_array - lomuto partition sorting scheme implementation
 *@array: array
 *@f: first array element
 *@l: last array element
 *@s: size array
 *Return: return the position of the last element sorted
 */
int partition_array(int *array, ssize_t f, ssize_t l, size_t s)
{
	int p_ivot = array[l];
	ssize_t current = f, find;

	for (find = f; find < l; find++)
	{
		if (array[find] < p_ivot)
		{
			if (array[current] != array[find])
			{
				swap_helper(array, current, find);
				print_array(array, s);
			}
			current++;
		}
	}
	if (array[current] != array[l])
	{
		swap_helper(array, current, l);
		print_array(array, s);
	}
	return (current);
}
/**
 *quiks - qucksort algorithm implementation
 *@array: array of integer
 *@f: first array element
 *@l: last array element
 *@s: array size
 */
void quiks(int *array, ssize_t f, ssize_t l, int s)
{
	ssize_t pos = 0;


	if (f < l)
	{
		pos = partition_array(array, f, l, s);

		quiks(array, f, pos - 1, s);
		quiks(array, pos + 1, l, s);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quiks(array, 0, size - 1, size);
}
