#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>


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
void	init_stack_a(t_list **lst,char  **argv);
bool	stack_sorted(t_list *lst);
void	sort_three(t_list **lst);
void	set_index(t_list *lst);
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	sort_stacks(t_list **a, t_list **b);



#endif