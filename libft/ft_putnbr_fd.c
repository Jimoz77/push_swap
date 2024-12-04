/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:26:15 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/08 13:30:23 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nombre;
	char			c;

	nombre = n;
	c = '\0';
	if (n < 0)
	{
		write (fd, "-", 1);
		nombre = -nombre;
	}
	if (nombre == 2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (nombre == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (nombre >= 10)
		ft_putnbr_fd (nombre / 10, fd);
	c = (nombre % 10) + '0';
	write (fd, &c, 1);
}
