/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:53:10 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:53:11 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_env *env)
{
	t_list	*temp;

	temp = env->a_stack->next;
	ft_lstadd_front(&(env->b_stack), env->a_stack);
	env->a_stack = temp;
	env->a_size--;
	env->b_size++;
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_env *env, int print)
{
	t_list	*first;
	t_list	*temp;

	temp = env->a_stack;
	first = env->a_stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	env->a_stack = env->a_stack->next;
	first->next = NULL;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_env *env, int print)
{
	t_list	*first;
	t_list	*temp;

	if (env->b_size == 1)
		return ;
	temp = env->b_stack;
	first = env->b_stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	env->b_stack = env->b_stack->next;
	first->next = NULL;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_env *env)
{
	ra(env, 0);
	rb(env, 0);
	ft_putstr_fd("rr\n", 1);
}

void	sa(t_env *env)
{
	t_list	*temp;

	temp = env->a_stack;
	env->a_stack = env->a_stack->next;
	temp->next = env->a_stack->next;
	env->a_stack->next = temp;
	ft_putstr_fd("sa\n", 1);
}
