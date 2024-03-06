/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:32:21 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:44:57 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function that print the unsigned int*/
static void	ft_put_nbr_unsigned(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_put_nbr_unsigned(nbr / 10);
		ft_put_nbr_unsigned(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

/*Function that calculate the lenght of the variable*/
static int	ft_lenght(long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*Function called when format %u is selected*/
int	ft_size_nbr_unsigned(unsigned int nbr, char flag, int width)
{
	int	len;

	len = ft_lenght(nbr);
	if (flag == '0' || flag == '.')
		ft_print_zero((width - len));
	ft_put_nbr_unsigned(nbr);
	if (len < width && flag == '-')
	{
		while (len++ < width)
			ft_putchar(' ');
		return (width);
	}
	if (flag && (width > len))
		return (width);
	return (len);
}
