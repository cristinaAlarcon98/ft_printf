#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
char *get_next_type(char *str);
int get_num_vars(const char *str);
void	ft_put_str_fd(char *str, int *count, int fd);
void	ft_putunsig_fd(unsigned int n, int *count, int fd);
void ft_puthexa_fd(unsigned long long num, int fd, char *hex_digits, int *count);
void	ft_putnbr_fd(int n, int *count, int fd);
void handle_input(char *str_pointer, int *count, va_list args);
void	ft_putchar_fd(char c,int *count, int fd);
void ft_putptr_fd(void *ptr, int *count, int fd);
void ft_puthexa_lower_case(unsigned int num,int *count, int fd);
void ft_puthexa_upper_case(unsigned int num, int *count, int fd);
void	ft_put_special_char(char c, int *count, int fd);
void write_str(char *str, int fd, int *count);












#endif