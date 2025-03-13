/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cralarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:49:34 by cralarco          #+#    #+#             */
/*   Updated: 2025/03/13 19:06:54 by cralarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_vars(const char *str)
{
	int	counter;
	int	i;

	if (!str)
		return (0);
	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			counter++;
		i++;
	}
	return (counter);
}

char	*get_next_type(char *str)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			return (str);
		}
		str++;
	}
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	char	*str_pointer;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	str_pointer = (char *)str;
	while (str[i])
	{
		if (str[i] == '%')
		{
			handle_input((char *)&str[i + 1], &count, args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

void	handle_input(char *str_pointer, int *count, va_list args)
{
	if (str_pointer[0] == 's')
		ft_put_str_fd(va_arg(args, char *), count, 1);
	if (str_pointer[0] == 'd' || str_pointer[0] == 'i')
		ft_putnbr_fd(va_arg(args, int), count, 1);
	if (str_pointer[0] == 'c')
		ft_putchar_fd(va_arg(args, int), count, 1);
	if (str_pointer[0] == 'p')
		ft_putptr_fd(va_arg(args, void *), count, 1);
	if (str_pointer[0] == 'u')
		ft_putunsig_fd(va_arg(args, unsigned int), count, 1);
	if (str_pointer[0] == 'x')
		ft_puthexa_lower_case(va_arg(args, unsigned int), count, 1);
	if (str_pointer[0] == 'X')
		ft_puthexa_upper_case(va_arg(args, unsigned int), count, 1);
	if (str_pointer[0] == '%')
		ft_put_special_char('%', count, 1);
}
