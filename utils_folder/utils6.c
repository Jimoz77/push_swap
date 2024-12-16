/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:39:22 by jimpa             #+#    #+#             */
/*   Updated: 2024/12/16 12:21:06 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stacks(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
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
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
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
