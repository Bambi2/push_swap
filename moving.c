#include "push_swap.h"

void	rr_type_move(t_env *env, t_list *min_element)
{
	int	difference;
	int	rr_count;

	if (min_element->ra_score > min_element->rb_score)
	{
		difference = min_element->ra_score - min_element->rb_score;
		rr_count = min_element->rb_score;
		while (rr_count-- > 0)
			rr(env);
		while (difference-- > 0)
			ra(env, 1);
	}
	else
	{
		difference = min_element->rb_score - min_element->ra_score;
		rr_count = min_element->ra_score;
		while (rr_count-- > 0)
			rr(env);
		while (difference-- > 0)
			rb(env, 1);
	}
}

void	rrr_type_move(t_env *env, t_list *min_element)
{
	int	difference;
	int	rrr_count;

	if (min_element->rra_score > min_element->rrb_score)
	{
		difference = min_element->rra_score - min_element->rrb_score;
		rrr_count = min_element->rrb_score;
		while (rrr_count-- > 0)
			rrr(env);
		while (difference-- > 0)
			rra(env, 1);
	}
	else
	{
		difference = min_element->rrb_score - min_element->rra_score;
		rrr_count = min_element->rra_score;
		while (rrr_count-- > 0)
			rrr(env);
		while (difference-- > 0)
			rrb(env, 1);
	}
}

void	ra_rrb_type_move(t_env *env, t_list *min_element)
{
	int	ra_count;
	int	rrb_count;

	ra_count = min_element->ra_score;
	rrb_count = min_element->rrb_score;
	while (ra_count-- > 0)
		ra(env, 1);
	while (rrb_count-- > 0)
		rrb(env, 1);
}

void	rra_rb_type_move(t_env *env, t_list *min_element)
{
	int	rra_count;
	int	rb_count;

	rra_count = min_element->rra_score;
	rb_count = min_element->rb_score;
	while (rra_count-- > 0)
		rra(env, 1);
	while (rb_count-- > 0)
		rb(env, 1);
}

void	rotate_a(t_env *env)
{
	t_list	*temp;
	int		counter;

	temp = env->a_stack;
	counter = 0;
	while (temp->content != env->min)
	{
		temp = temp->next;
		counter++;
	}
	if (counter > env->a_size / 2)
		while (env->a_stack->content != env->min)
			rra(env, 1);
	else
		while (env->a_stack->content != env->min)
			ra(env, 1);
}
