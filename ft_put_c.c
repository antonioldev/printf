/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:51:12 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:34:42 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function for printing char*/
int	ft_putc(char c, char flag, int width)
{
	int	i;

	i = 1;
	if (!c)
		write(1, "\0", 1);
	if (c)
		write(1, &c, 1);
	if (flag == '-')
	{
		while (i++ < width)
			ft_putchar(' ');
		return (width);
	}
	return (1);
}