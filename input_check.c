/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:53:37 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:53:38 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_integer(char *number)
{
	long	temp_num;
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(number);
	if (len > 11)
		return (0);
	if (number[0] != '-' && !ft_isdigit(number[0]))
		return (0);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	temp_num = ft_atoi(number);
	if (temp_num > 2147483647 || temp_num < -2147483648)
		return (0);
	return (1);
}

void	free_two_dim(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	word_count(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int	set_arrays(char **transformed_arr, int **arr, int **sorted_arr)
{
	int	count;

	count = word_count(transformed_arr);
	*arr = convert_to_arr(transformed_arr, count);
	if (!*arr)
	{
		free_two_dim(transformed_arr);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	*sorted_arr = sort_arr(*arr, count);
	if (!*sorted_arr)
	{
		free(*arr);
		free_two_dim(transformed_arr);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (count);
}

//convert from strings to numbers
int	*convert_to_arr(char **num_strings, int count)
{
	int		*numbers;
	int		i;

	i = 0;
	numbers = (int *) malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	while (i < count)
	{
		if (!check_integer(num_strings[i]))
		{
			free(numbers);
			return (NULL);
		}
		numbers[i] = (int) ft_atoi(num_strings[i]);
		i++;
	}
	return (numbers);
}
