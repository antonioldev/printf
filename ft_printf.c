/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:50:26 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:31:11 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function that serch if there is any flag*/
static char	ft_find_flag(char c)
{
	char	*flag;
	int		i;

	flag = "+ #-0.";
	i = 0;
	if (c > '0' && c <= '9')
		return ('n');
	while (flag[i] != '\0')
	{
		if (flag[i] == c)
			return (flag[i]);
		i++;
	}
	return (0);
}

/*Function that calculate the minimum field width of the output field*/
static int	ft_calculate_width(const char *fmt, char c, int *i)
{
	int	sum;

	sum = 0;
	if (c != 'n')
		*i += 1;
	while (fmt[*i] >= '0' && fmt[*i] <= '9')
	{
		sum = (sum * 10) + (fmt[*i] - '0');
		*i += 1;
	}
	if (sum > 0)
		return (sum);
	return (0);
}

/*Function that call the right function for the format required*/
static int	find_var(char fmt, va_list ap, char flag, int width)
{
	if (fmt == 'c')
		return (ft_putc(va_arg(ap, int), flag, width));
	else if (fmt == 's')
		return (ft_putstring(va_arg(ap, char *), flag, width));
	else if (fmt == '%')
		return (ft_putchar('%'));
	else if (fmt == 'i' || fmt == 'd')
		return (ft_size_nbr(va_arg(ap, int), flag, width));
	else if (fmt == 'u')
		return (ft_size_nbr_unsigned(va_arg(ap, unsigned int), flag, width));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_decimal_to_exa(va_arg(ap, unsigned int), fmt, flag, width));
	else if (fmt == 'p')
		return (ft_print_address(va_arg(ap, void *), flag, width));
	else
		return (0);
}

/*Function that goes through the string and print it*/
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			c = ft_find_flag(fmt[++i]);
			if (c)
				j += find_var(fmt[i], ap, c, ft_calculate_width(fmt, c, &i));
			else
				j += find_var(fmt[i], ap, 0, 0);
		}
		else
			j += ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (j);
}
