/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:18:02 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/08 16:23:50 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned	int, char))
{
	unsigned int	i;
	char			*chaine;

	if (!s)
	{
		return (0);
	}
	chaine = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!chaine)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		chaine[i] = f(i, s[i]);
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
