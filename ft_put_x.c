/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:31:46 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:51:14 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function that print the exadeciaml number*/
static int	ft_calculate_exa(unsigned int nbr, char *buffer, int i, char c)
{
	unsigned int	temp;

	temp = nbr % 16;
	if (temp < 10)
		temp += 48;
	else if (c == 'X')
		temp += 55;
	else
		temp += 87;
	buffer[i] = temp;
	nbr /= 16;
	return (nbr);
}

/*Function called when format %x or %X is selected*/
int	ft_decimal_to_exa(unsigned int nbr, char c, char flag, int width)
{
	char	buffer[20];
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (nbr == 0)
	{
		buffer[i] = '0';
		i++;
		check = -1;
	}
	while (nbr > 0)
		nbr = ft_calculate_exa(nbr, buffer, i++, c);
	if (flag == '#' && check == 0)
	{
		buffer[i++] = c;
		buffer[i++] = '0';
	}
	buffer[i] = '\0';
	ft_invert(buffer, i);
	if (flag == '0')
		ft_print_zero(width - i);
	return (ft_putstr(buffer, flag, width));
}
