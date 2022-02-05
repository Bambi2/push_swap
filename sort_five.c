/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:52:48 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:52:50 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sb(t_env *env)
{
	t_list	*temp;

	temp = env->b_stack;
	env->b_stack = env->b_stack->next;
	temp->next = env->b_stack->next;
	env->b_stack->next = temp;
	ft_putstr_fd("sb\n", 1);
}

static void	sort_a(t_env *env)
{
	int	first;
	int	second;

	first = env->a_stack->content;
	second = env->a_stack->next->content;
	if (first < second)
		ra(env, 1);
}

static void	sort_b(t_env *env)
{
	int	first;
	int	second;
	int	third;

	first = env->b_stack->content;
	second = env->b_stack->next->content;
	third = env->b_stack->next->next->content;
	if (third < first && third > second)
	{
		sb(env);
		rb(env, 1);
	}
	else if (!(second > third && second < first))
	{
		if (second > first && second < third)
			sb(env);
		else if (third < second && third > first)
			rrb(env, 1);
		else if (first > third && first < second)
		{
			sb(env);
			return ;
		}
		rrb(env, 1);
	}
}

void	sort_five(t_env *env)
{
	while (env->a_size != 2)
	{
		if (env->a_stack->content == env->min
			|| env->a_stack->content == env->max)
			ra(env, 1);
		else
			pb(env);
	}
	sort_b(env);
	sort_a(env);
	pa(env);
	pa(env);
	pa(env);
	rra(env, 1);
}
