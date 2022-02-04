#include "push_swap.h"

static int	find_min(int *arr)
{
	int	i;
	int	min;

	min = arr[0];
	i = 1;
	while (i < 4)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

//count rb
void	count_rb_score(t_env *env)
{
	int		score;
	t_list	*temp;

	env->b_stack->rb_score = 0;
	env->b_stack->rrb_score = 0;
	temp = env->b_stack->next;
	score = 1;
	while (temp)
	{
		temp->rb_score = score;
		temp->rrb_score = env->b_size - score;
		score++;
		temp = temp->next;
	}
}

//count ra
void	count_ra_score(t_env *env)
{
	int		score;
	t_list	*temp_b;
	t_list	*a_first;
	t_list	*a_last;
	t_list	*last;

	last = ft_lstlast(env->a_stack);
	temp_b = env->b_stack;
	score = 0;
	while (temp_b)
	{
		a_first = env->a_stack;
		a_last = last;
		score = 0;
		while (!(temp_b->content < a_first->content
				&& temp_b->content > a_last->content))
		{
			a_last = a_first;
			a_first = a_first->next;
			score++;
		}
		temp_b->ra_score = score;
		temp_b->rra_score = env->a_size - score;
		temp_b = temp_b->next;
	}
}

//count the minimum score of the element
int	count_min_score(t_list *stack)
{
	int	min_score[4];
	int	min;

	min_score[0] = stack->ra_score + stack->rrb_score;
	min_score[1] = stack->rra_score + stack->rb_score;
	if (stack->ra_score > stack->rb_score)
		min_score[2] = stack->ra_score;
	else
		min_score[2] = stack->rb_score;
	if (stack->rra_score > stack->rrb_score)
		min_score[3] = stack->rra_score;
	else
		min_score[3] = stack->rrb_score;
	min = find_min(min_score);
	if (min_score[0] == min)
		stack->action_type = ra_rrb_type;
	else if (min_score[1] == min)
		stack->action_type = rra_rb_type;
	else if (min_score[2] == min)
		stack->action_type = rr_type;
	else if (min_score[3] == min)
		stack->action_type = rrr_type;
	return (min);
}

void	move_min_score(t_env *env, t_list *min_element)
{
	if (min_element->action_type == rr_type)
		rr_type_move(env, min_element);
	else if (min_element->action_type == rrr_type)
		rrr_type_move(env, min_element);
	else if (min_element->action_type == ra_rrb_type)
		ra_rrb_type_move(env, min_element);
	else if (min_element->action_type == rra_rb_type)
		rra_rb_type_move(env, min_element);
	pa(env);
}
