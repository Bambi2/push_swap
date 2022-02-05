/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:54:15 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:54:27 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_utils.h"

//get a new array copied from arr
int	*copy_arr(int *arr, int length)
{
	int	i;
	int	*new_array;

	new_array = (int *) malloc(sizeof(int) * length);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_array[i] = arr[i];
		i++;
	}
	return (new_array);
}

//convert arr to t_list
t_list	*convert_to_list(int *arr, int length)
{
	int		i;
	t_list	*temp;
	t_list	*new_list;

	i = 0;
	new_list = NULL;
	while (i < length)
	{
		temp = ft_lstnew(arr[i]);
		if (!temp)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp);
		i++;
	}
	return (new_list);
}

char	**transform_array(int argc, char **argv)
{
	char	**new_array;
	char	*new_string;
	int		i;

	i = 2;
	if (argc == 1)
		return (NULL);
	new_string = ft_strdup(argv[1]);
	if (!new_string)
		return (NULL);
	while (i < argc)
	{
		new_string = ft_strjoin(new_string, argv[i]);
		if (!new_string)
			return (NULL);
		i++;
	}
	new_array = ft_split(new_string, ' ');
	free(new_string);
	if (!new_array)
		return (NULL);
	return (new_array);
}
