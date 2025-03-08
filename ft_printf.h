#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd);
int ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
char *get_next_type(char *str);
int get_num_vars(const char *str);
void	ft_put_str_fd(char *str, int fd);
void handle_input(char *str_pointer, va_list args);
void ft_putptr_fd(void *ptr, int fd);




#endif