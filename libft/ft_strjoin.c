/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:34:05 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/08 14:01:33 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*point;
	int		i;
	int		j;
	int		totalen;

	j = 0;
	i = 0;
	totalen = ft_strlen(s1) + ft_strlen(s2);
	point = malloc(sizeof(char) * totalen + 1);
	if (!point)
		return (0);
	while (s1[i] != '\0')
	{
		point[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		point[i] = s2[j];
		i++;
		j++;
	}
	point[i] = '\0';
	return (point);
}
