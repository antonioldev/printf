/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:31:23 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:39:52 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function that print the int*/
static void	ft_putnbr(long int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nbr);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

/*Function that print sign if requested*/
static int	ft_print_sign(long int nbr, char c)
{
	if ((c == ' ' || c == '+') && nbr >= 0)
	{
		ft_putchar(c);
		return (1);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

/*Function that calculate the size of int*/
static int	ft_lenght(long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*Function that manage the flag*/
static void	check_flag(int *len, int check_sign, int width, char flag)
{
	if (flag == '0')
	{
		ft_print_zero(width - *len);
		if ((width - *len) > 0)
			*len += width - *len;
	}
	if (flag == '.')
	{
		ft_print_zero(width - *len + check_sign);
		if ((width - *len) > 0)
			*len += width - *len;
		if (width >= *len)
			*len += check_sign;
	}
}

/*Function called when format %i or %d is selected*/
int	ft_size_nbr(long int nbr, char flag, int width)
{
	int	len;
	int	check_sign;

	check_sign = ft_print_sign(nbr, flag);
	len = ft_lenght(nbr) + check_sign;
	if (flag)
		check_flag(&len, check_sign, width, flag);
	if (nbr < 0)
		nbr *= -1;
	ft_putnbr(nbr);
	if (len > width || !flag)
		return (len);
	if (flag == '-')
		while (len++ < width)
			ft_putchar(' ');
	return (width);
}
