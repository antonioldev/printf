/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:39:32 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:40:32 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function called when format %p is selected, print the address of *p*/
int	ft_print_address(void	*p, char flag, int width)
{
	int		i;
	char	*hex;
	char	buffer[20];

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = "0123456789abcdef";
	i = 0;
	while ((unsigned long)p > 0)
	{
		buffer[i] = hex[(unsigned long)p % 16];
		p = (void *)((unsigned long)p / 16);
		i++;
	}
	buffer[i++] = 'x';
	buffer[i++] = '0';
	buffer[i] = '\0';
	i = ft_strlen(buffer);
	ft_invert(buffer, i);
	return (ft_putstr(buffer, flag, width));
}
