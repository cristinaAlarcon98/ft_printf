
#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

void	ft_putunsig_fd(unsigned int n, int fd)
{
	long	num;

	num = n;
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_put_str_fd(char *str, int fd)
{
	while(*str)
	{
		write(fd, str, 1);
		str++;

	}
}

char *parse_to_exadecimal(unsigned long long adress)
{
	int reminder;
	char *hex_digits;

	hex_digits = "0123456789ABCDEF";
	reminder = 0;
	while(adress != 0)
	{
		reminder = adress % 16;
		adress = adress / 16;

		
	}
}

void ft_putptr_fd(void *ptr, int fd)
{
    unsigned long long address;
	
    write(fd, "0", 1);
	write(fd, "x", 1);

    address = (unsigned long long)ptr;
	ft_puthexa_fd(address, fd);
	
}

void ft_puthexa_fd(unsigned long long num,int fd)
{
	
	char *hex_digits;
	int reminder;
	char buffer[16];
	int i; 

	hex_digits = "0123456789abcdef";
	reminder = 0;
	if (num == 0)
	{
    	write(fd, "0", 1);
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
		write(fd, &buffer[i], 1);
	write(fd, &buffer[i], 1);
}

