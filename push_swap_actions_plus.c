#include "push_swap.h"

void	pa(t_env *env)
{
	t_list	*temp;

	temp = env->b_stack->next;
	ft_lstadd_front(&(env->a_stack), env->b_stack);
	env->b_stack = temp;
	env->b_size--;
	env->a_size++;
	ft_putstr_fd("pa\n", 1);
}

void	rra(t_env *env, int print)
{
	t_list	*last;
	t_list	*temp;

	last = ft_lstlast(env->a_stack);
	temp = env->a_stack;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = env->a_stack;
	env->a_stack = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_env *env, int print)
{
	t_list	*last;
	t_list	*temp;

	if (env->b_size == 1)
		return ;
	last = ft_lstlast(env->b_stack);
	temp = env->b_stack;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = env->b_stack;
	env->b_stack = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_env *env)
{
	rra(env, 0);
	rrb(env, 0);
	ft_putstr_fd("rrr\n", 1);
}
