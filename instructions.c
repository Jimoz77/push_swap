#include "push_swap.h"

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a,b);
	set_index(*a);
	set_index(*b);
	
}

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a,b);
	set_index(*a);
	set_index(*b);
	
}

// FONCTION DE MOUVEMENT DE LISTE //

//SA swap a // SB swap b
void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return;
	first = *lst;
	second = (*lst)->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}
 
//PB push b //PA push a
void	push(t_list **lst_b, t_list **lst_a)
{
	if (*lst_a == NULL)
		return; // Liste A est vide, rien à pousser
	t_list *first_a = *lst_a;
	*lst_a = (*lst_a)->next; // Mettre à jour lst_a pour pointer vers le deuxième élément
	first_a->next = *lst_b; // Relier le premier élément de A au début de la liste B
	*lst_b = first_a; // Mettre à jour lst_b pour pointer vers le nouvel élément ajouté
}

//RA rotate a //RB rotate b
void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return;
	first = *lst;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = first;
	*lst = first->next;
	first->next = NULL;
	
}
//RRA reverse rotate a //RRB reverse rotate b
void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (*lst == NULL || (*lst)->next == NULL)
		return;
	second_last = NULL;
	last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}
// FONCTION INTERMEDIARE POUR WRITE A CHAQUE APPEL //

void	sa(t_list **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_list **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	write (1, "ss\n", 3);
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	push(lst_a, lst_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	push(lst_b, lst_a);
	write(1, "pb\n", 3);
}

void	ra(t_list **lst)
{
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **lst)
{
	rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	write(1, "rr\n", 3);
}

void	rra(t_list **lst)
{
	reverse_rotate(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_list **lst)
{
	reverse_rotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	write(1, "rrr\n", 4);
}