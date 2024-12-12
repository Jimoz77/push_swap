/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:03:44 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/12 19:39:58 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>

//une fois tout les utils needed suppr libft
//ajouter ft_printf a la place de printf

typedef struct s_list
{
	int				content;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;

}	t_list;

t_list	*ft_lstnew(int content);
long	ft_atol(const char *str);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst_a, t_list **lst_b);
char	**ft_split(char const *s, char c);
void	init_stack_a(t_list **lst, char **argv);
bool	stack_sorted(t_list *lst);
void	sort_three(t_list **lst);
void	set_index(t_list *lst);
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	sort_stacks(t_list **a, t_list **b);
t_list	*find_max(t_list *lst);
t_list	*find_min(t_list *lst);
void	prep_for_push(t_list **lst, t_list *top_node, char lst_name);
t_list	*get_cheapest(t_list *a);
void	move_a_to_b(t_list **a, t_list **b);
void	move_b_to_a(t_list **a, t_list **b);
void	set_cheapest(t_list *lst);
void	cost_analysis_a(t_list *a, t_list *b);
void	set_target_a(t_list *a, t_list *b);
void	set_target_b(t_list *a, t_list *b);
void	init_nodes_a(t_list *a, t_list *b);
void	init_nodes_b(t_list *a, t_list *b);
void	min_on_top(t_list **a);
t_list	*ft_lstlast(t_list *lst);
bool	check_carac(char **argv);
bool	check_doublon(char **argv);
void	swap(t_list **lst);
void	push(t_list **lst_b, t_list **lst_a);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
int		ft_printf(const char *str, ...);

#endif