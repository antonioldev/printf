/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:31:36 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:40:46 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *c, char flag, int width)
{
	int	len;

	if (!c)
		return ((int)write (1, "(null)", 6));
	len = ft_strlen(c);
	if (len == 0 && width == 0)
		return (0);
	if (flag == '.' && width < len)
		return ((int)write(1, c, width));
	if (!flag || width >= len || (flag == '-' && width < len))
		write(1, c, len);
	if ((flag == '-' || flag == 'n') && width > len)
	{
		while (len++ < width)
			ft_putchar(' ');
		return (width);
	}
	return (len);
}

int	ft_putstr(char *c, char flag, int width)
{
	int	len;
	int	i;

	if (!c)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(c);
	if (flag == '.')
	{
		i = 0;
		while (i++ < (width - len))
			ft_putchar('0');
	}
	write(1, c, len);
	if (len < width)
	{
		if (flag == '-')
			while (len++ < width)
				ft_putchar(' ');
		return (width);
	}
	return (len);
}
