/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:56:54 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/08 14:51:27 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	is_nega;
	int	res;

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
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp ->next = new;
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

void init_stack_a(t_list **lst,char  **argv)				//il faut aussi isoler les fautes de syntaxe et autre erreur
{															//que l'ont ne veut pas dans la chaine !!!!
	int i = 1;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_atoi(argv[i])));
		i++;
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
