
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int *count, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', count, fd);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, count, fd);
		ft_putchar_fd((num % 10) + '0', count, fd);
	}
	else
	{
		ft_putchar_fd(num + '0', count, fd);
	}
}

void	ft_putunsig_fd(unsigned int n, int *count, int fd)
{
	long	num;

	num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, count, fd);
		ft_putchar_fd((num % 10) + '0', count, fd);
	}
	else
		ft_putchar_fd(num + '0', count, fd);
}

void	ft_putchar_fd(char c, int *count, int fd)
{
	write(fd, &c, 1);
	(*count)++;

}



void	ft_put_str_fd(char *str, int *count, int fd)
{
	if (str == NULL)
	{
		write_null(fd, count);
	}
	else
	{
		while(*str)
		{
			write(fd, str, 1);
			(*count)++;
			str++;
		}
	}
		
	
}

void write_null(int fd, int *count)
{
	char* str_null;

	str_null = "(null)";
	while(*str_null)
	{
		write(fd, str_null, 1);
		(*count)++;
		str_null++;
	}
}

void	ft_put_special_char(char c, int *count, int fd)
{
	char *ptr;

	ptr = &c;
	write(fd, ptr, 1);
	(*count)++;
}



void ft_putptr_fd(void *ptr, int *count, int fd)
{
    unsigned long long address;
	char *hex_digits;

	
    write(fd, "0", 1);
	write(fd, "x", 1);
	*count += 2;

    address = (unsigned long long)ptr;
	hex_digits = "0123456789abcdef";
	ft_puthexa_fd(address, fd, hex_digits, count);
	
}

void ft_puthexa_lower_case(unsigned int num,int *count, int fd)
{
	char *hex_digits;
	hex_digits = "0123456789abcdef";
	
    ft_puthexa_fd((unsigned long long)num, fd, hex_digits, count);
}

void ft_puthexa_upper_case(unsigned int num, int *count, int fd)
{
	char *hex_digits;
	hex_digits = "0123456789ABCDEF";
	
    ft_puthexa_fd((unsigned long long)num, fd, hex_digits, count);
}

void ft_puthexa_fd(unsigned long long num, int fd, char *hex_digits, int *count)
{
	
	int reminder;
	char buffer[16];
	int i; 

	reminder = 0;
	if (num == 0)
	{
    	write(fd, "0", 1);
		(*count)++;
    	return;
	}
	i = 0;
	while(num != 0)
	{
		buffer[i] = hex_digits[num % 16];
		num = num / 16;
		i++;
	}
	while(--i != 0)
	{
		write(fd, &buffer[i], 1);
		(*count)++;

	}
	write(fd, &buffer[i], 1);
	(*count)++;
}

