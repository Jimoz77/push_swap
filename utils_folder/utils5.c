/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:37:42 by jimpa             #+#    #+#             */
/*   Updated: 2025/02/03 15:42:23 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		new->prev = temp;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->index = 0;
	new_element->push_cost = 0;
	new_element->above_median = false;
	new_element->cheapest = false;
	new_element->target_node = NULL;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	init_stack_a(t_list **lst, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN
			|| check_carac(argv) == 1 || check_doublon(argv) == 1)
		{
			write(2, "Error\n", 6);
			free_list(*lst);
			exit(1);
		}
		ft_lstadd_back(lst, ft_lstnew(ft_atol(argv[i])));
		i++;
	}
}
