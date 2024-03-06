/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:32:29 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/30 16:42:47 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Function that calculate the lenght of a string*/
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*Function that print a set zero when required*/
void	ft_print_zero(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

/*Function that print a char to stdout*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*Function that inver the order of an array*/
void	ft_invert(char *buffer, int len)
{
	int		i;
	char	temp;

	i = 0;
	len--;
	while (i < len)
	{
		temp = buffer[i];
		buffer[i] = buffer[len];
		buffer[len] = temp;
		i++;
		len--;
	}
}
