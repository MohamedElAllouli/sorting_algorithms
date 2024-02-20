#include "sort.h"
/**
  * selection_sort - algorithm of selection sort
  * @array: array of integer
  * @size: size of array
  * Return: Void
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int Min, tmp, indx;

	for (i = 0; i < size; i++)
	{
		Min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (Min > array[j])
			{
				Min = array[j];
				indx = j;
			}
		}
		if (Min != array[i])
		{
			tmp = array[i];
			array[i] = Min;
			array[indx] = tmp;
			print_array(array, size);
		}
	}
}
