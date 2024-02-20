#include "sort.h"
/**
  * shell_sort - shell sort, knuth sequence
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *array, size_t size)
{
	size_t knuth, i, j;
	int t_mp;

	knuth = 1;
	while (knuth < size)
		knuth = (knuth * 3) + 1;
	knuth = (knuth - 1) / 3;
	while (knuth > 0)
	{
		for (i = knuth; i < size; i++)
		{
			t_mp = array[i];
			for (i2 = i; j >= knuth && array[j - knuth] > t_mp; j -= knuth)
				array[j] = array[j - knuth];
			array[j] = t_mp;
		}
		knuth = (knuth - 1) / 3;
		print_array(array, size);
	}
}
