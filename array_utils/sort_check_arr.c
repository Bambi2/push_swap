#include "array_utils.h"

//swap two integers
static void	swap(int *first, int *second)
{
	int	temp;

	if (!first || !second)
		return ;
	temp = *first;
	*first = *second;
	*second = temp;
}

//get array in ascending order and check for duplicates
int	*sort_arr(int *arr, int length)
{
	int	i;
	int	j;
	int	min;
	int	*sorted_arr;

	i = 0;
	sorted_arr = copy_arr(arr, length);
	if (!sorted_arr)
		return (NULL);
	while (i < length - 1)
	{
		min = i;
		j = i + 1;
		while (j < length)
		{
			if (sorted_arr[j] < sorted_arr[min])
				min = j;
			j++;
		}
		swap(sorted_arr + min, sorted_arr + i);
		i++;
	}
	if (has_duplicates(sorted_arr, length))
		return (NULL);
	return (sorted_arr);
}

//check if arr is in ascending order
int	is_arr_sorted(int *arr, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (arr[i + 1] < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *arr, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (1);
		}
		i++;
	}
	return (0);
}
