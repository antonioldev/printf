/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimotta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:51:37 by alimotta          #+#    #+#             */
/*   Updated: 2023/11/23 10:09:45 by alimotta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
//# include <stdlib.h>
//# include <string.h>

int	ft_printf(const char *fmt, ...);
int	ft_putc(char c, char flag, int width);
int	ft_putchar(char c);
int	ft_putstring(char *c, char flag, int width);
int	ft_putstr(char *c, char flag, int width);
int ft_size_nbr(long int nbr, char flag, int width);
int	ft_size_nbr_unsigned(unsigned int nbr, char flag, int width);
int	ft_decimal_to_exa(unsigned int nbr, char c, char flag, int width);
int ft_print_address(void *p, char flag, int width);
int	ft_strlen(const char *s);
void ft_invert(char *buffer, int len);
void	ft_print_zero(int	n);
#endif
