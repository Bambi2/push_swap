#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	char	**transformed_arr;
	int		*sorted_arr;
	int		numbers_count;

	transformed_arr = transform_array(argc, argv);
	if (!transformed_arr)
		return (1);
	numbers_count = set_arrays(transformed_arr, &arr, &sorted_arr);
	if (!numbers_count)
		return (1);
	if (!is_arr_sorted(arr, numbers_count))
		push_swap(arr, sorted_arr, numbers_count);
	free(arr);
	free(sorted_arr);
	free_two_dim(transformed_arr);
}
