/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpa <jimpa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:55:53 by jimpa             #+#    #+#             */
/*   Updated: 2024/10/04 13:14:38 by jimpa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const int	checker(const char *same, const char *little)
{
	int	i;

	i = 0;
	while (little[i])
	{
		if (same[i] == little[i])
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		if (big[i] == *little)
		{
			if (i + ft_strlen(little) <= len && checker(big + i, little) > 0)
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
