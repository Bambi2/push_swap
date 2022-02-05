/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:54:09 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:54:10 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

# include "../libft/libft.h"

//sort and check
int		has_duplicates(int *arr, int length);
int		*sort_arr(int *arr, int length);
int		is_arr_sorted(int *arr, int length);

//convert and copy
t_list	*convert_to_list(int *arr, int length);
int		*copy_arr(int *arr, int length);
char	**transform_array(int argc, char **argv);

#endif
