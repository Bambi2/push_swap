/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:52:57 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:52:59 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_env	*set_environment(int *arr, int *arr_sorted, int length)
{
	t_env	*env;

	env = (t_env *) malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->max = arr_sorted[length - 1];
	env->min = arr_sorted[0];
	env->median = arr_sorted[length / 2];
	env->a_stack = convert_to_list(arr, length);
	env->b_stack = NULL;
	env->a_size = length;
	env->b_size = 0;
	if (!env->a_stack)
	{
		free(env);
		return (NULL);
	}
	return (env);
}

static void	push_all_to_b(t_env *env)
{
	int	c;

	while (env->a_size > 3)
	{
		c = env->a_stack->content;
		if (c == env->min || c == env->median || c == env->max)
			ra(env, 1);
		else
			pb(env);
	}
}

static void	sort_three(t_env *env)
{
	int	first;
	int	second;

	if (env->a_size == 1)
		return ;
	else if (env->a_size == 2)
	{
		if (env->a_stack->content > env->a_stack->next->content)
			ra(env, 1);
	}
	else
	{
		first = env->a_stack->content;
		second = env->a_stack->next->content;
		if ((first == env->min && second == env->max)
			|| (first == env->max && second == env->median)
			|| (first == env->median && second == env->min))
			sa(env);
	}
}

static void	move_from_b(t_env *env)
{
	t_list	*temp;
	t_list	*min_element;
	int		min_score;
	int		current_min_score;

	count_rb_score(env);
	count_ra_score(env);
	temp = env->b_stack->next;
	min_element = env->b_stack;
	min_score = count_min_score(min_element);
	while (temp)
	{
		current_min_score = count_min_score(temp);
		if (current_min_score <= min_score)
		{
			min_score = current_min_score;
			min_element = temp;
		}
		temp = temp->next;
	}
	move_min_score(env, min_element);
}

void	push_swap(int *arr, int *arr_sorted, int length)
{
	t_env	*env;

	env = set_environment(arr, arr_sorted, length);
	if (!env)
		return ;
	if (length == 5)
	{
		sort_five(env);
		return ;
	}
	push_all_to_b(env);
	sort_three(env);
	while (env->b_size != 0)
		move_from_b(env);
	rotate_a(env);
	ft_lstclear(&(env->a_stack));
	free(env);
}
