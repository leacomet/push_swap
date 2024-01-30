/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:57:41 by acomet            #+#    #+#             */
/*   Updated: 2023/02/23 15:40:35 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

/* libft_modified */
char	*strjoin_with_space(char *s1, char const *s2);
long	atol(const char *str);

/* lst_functions.c */
t_list	*ft_lstnew(int content);
t_list	*create_stack_a(char **grid);
void	ft_lstclear(t_list **lst);

/* check_errors */
int		check_error_empty_and_spaces(char **argv);
int		check_error_nodigit_max_min_int(char **grid);
int		check_duplicate(char **grid);
int		check_duplicate2(t_list *list);

/* grid */
char	**create_grid(int argc, char **argv, char **grid);
void	free_grid(char **grid);

/* stack_a */
t_list	*create_stack_a_and_check_duplicate(char **grid, t_list *stack_a);

/* free functions */
void	free_grid(char **grid);
void	free_grid_exit(char **grid);
void	free_str_exit(char *str);

/* count of number */
int		count_of_number(t_list **lst);

/* normalized */
void	normalized(t_list **stack_a, int nbr_count);

/* sorts algorithm */
void	sort_algorithm(t_list **stack_a, t_list **stack_b, int nbr_count);
void	specific_sort(t_list **stack_a, t_list **stack_b, int nbr_count);

/* sorts verif */
int		total_is_not_sorted(t_list **stack_a, t_list **stack_b);
int		is_not_sorted(t_list **lst);
int		is_not_upside_down(t_list **lst);

/* sort little number */
void	sort_little_number(t_list **stack_a, t_list **stack_b, int nbr_count);

/* sorts */
void	main_sort(t_list **stack_a, t_list **stack_b, int nbr_count);

/* sort optimization */
int		if_rotate_better(t_list **stack_a, t_list **stack_b, int target, int i);
int		is_rotate_better(t_list **stack_b, int target, int limit);
int		is_rotate_better_at_end(t_list **stack_b, int target, int limit, int i);
int		if_reverse_better(t_list **stack_a, t_list **stack_b, int target,
			int i);
int		is_reverse_better(t_list **stack_b, int target);

/* instructions */
	/* swaps */
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ab(t_list **stack_a, t_list **stack_b);
void	swap_a_without_write(t_list **stack_a);
void	swap_b_without_write(t_list **stack_b);

	/* pushes */
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

	/* rotates */
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_ab(t_list **stack_a, t_list **stack_b);
void	rotate_a_without_write(t_list **stack_a);
void	rotate_b_without_write(t_list **stack_b);

	/* reverses */
void	reverse_a(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	reverse_ab(t_list **stack_a, t_list **stack_b);
void	reverse_a_without_write(t_list **stack_a);
void	reverse_b_without_write(t_list **stack_b);

	/* bonus */
int		get_instructions(t_list **stack_a, t_list **stack_b);
int		do_instruction(t_list **stack_a, t_list **stack_b, char *str);
int		do_reverse(t_list **stack_a, t_list **stack_b, char *str);
char	*get_next_line(int fd, int error);

	/* bonus instructions */
		/* swaps */
void	swap_a_bonus(t_list **stack_a);
void	swap_b_bonus(t_list **stack_b);
void	swap_ab_bonus(t_list **stack_a, t_list **stack_b);

		/* pushes */
void	push_a_bonus(t_list **stack_a, t_list **stack_b);
void	push_b_bonus(t_list **stack_a, t_list **stack_b);

		/* rotates */
void	rotate_a_bonus(t_list **stack_a);
void	rotate_b_bonus(t_list **stack_b);
void	rotate_ab_bonus(t_list **stack_a, t_list **stack_b);

		/* reverses */
void	reverse_a_bonus(t_list **stack_a);
void	reverse_b_bonus(t_list **stack_b);
void	reverse_ab_bonus(t_list **stack_a, t_list **stack_b);

#endif
