/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalphit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:53:50 by mmalphit          #+#    #+#             */
/*   Updated: 2022/02/05 14:53:52 by mmalphit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "array_utils/array_utils.h"

typedef struct s_env	t_env;

struct s_env {
	t_list	*a_stack;
	t_list	*b_stack;
	int		max;
	int		min;
	int		median;
	int		a_size;
	int		b_size;
};

void	push_swap(int *arr, int *arr_sorted, int length);
int		*convert_to_arr(char **num_strings, int count);
int		set_arrays(char **transformed_arr, int **arr, int **sorted_arr);
void	free_two_dim(char **arr);

//push_swap actions
void	pb(t_env *env);
void	pa(t_env *env);
void	ra(t_env *env, int print);
void	rb(t_env *env, int print);
void	rra(t_env *env, int print);
void	rrb(t_env *env, int print);
void	rr(t_env *env);
void	rrr(t_env *env);
void	sa(t_env *env);

//score_counting
void	count_rb_score(t_env *env);
void	count_ra_score(t_env *env);
int		count_min_score(t_list *stack);
void	move_min_score(t_env *env, t_list *min_element);

//moving
void	rr_type_move(t_env *env, t_list *min_element);
void	rrr_type_move(t_env *env, t_list *min_element);
void	ra_rrb_type_move(t_env *env, t_list *min_element);
void	rra_rb_type_move(t_env *env, t_list *min_element);

//last move
void	rotate_a(t_env *env);

//sort five
void	sort_five(t_env *env);

#endif
