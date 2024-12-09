/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:56:54 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/09 17:39:55 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *lst)
{
	t_list *max_node;
	int max_val;

	max_val = INT_MIN;
	max_node = NULL;
	while (lst)
	{
		if (lst->content > max_val)
		{
			max_val = lst->content;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

void sort_three(t_list **lst)
{
	t_list *big_node;

	big_node =find_max(*lst);
	if (big_node == *lst)
		ra(lst);
	else if ((*lst)->next == big_node)
		rra(lst);
	if ((*lst)->content > (*lst)->next->content)
		sa(lst);
	
}

bool stack_sorted(t_list *lst)
{
	if(!lst)
		return (1);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

bool check_carac(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '-')
            j++;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

bool check_doublon(char **argv)
{
    int i;
    int j;
    int val_i;
    int val_j;

    i = 1;
    while (argv[i])
    {
        val_i = ft_atol(argv[i]);
        j = i + 1;
        while (argv[j])
        {
            val_j = ft_atol(argv[j]);
            if (val_i == val_j)
            {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	long	is_nega;
	long	res;

	i = 0;
	res = 0;
	is_nega = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_nega = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_nega);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return;
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
		temp =ft_lstlast(*lst);
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
	new_element->content = (int)(long)content;
	new_element->next = NULL;
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

void init_stack_a(t_list **lst,char  **argv)
{
	int i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN || check_carac(argv) == 1 || check_doublon(argv) == 1)
		{
			write(STDERR_FILENO, "Error\n", 6);
			return ;
		}
		
		ft_lstadd_back(lst, ft_lstnew(ft_atol(argv[i])));
		i++;
	}
}

void	sort_stacks(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		// a suivre dans la suite de la video : 34:26
	}
		
}


// pour split :

static char	**free_all(char **result, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	int	in_word;
	int	count;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while(s[cursor] == c)
		++cursor;
	while((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return(next_word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**result;

	i = 0;
	words = count_words(s, c);
	if (!words)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(words + 2));
	if (!result)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (free_all(result, i));
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(s, c);
	}
	result[i] = NULL;
	return (result);
}
