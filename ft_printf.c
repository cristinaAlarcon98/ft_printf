
#include "ft_printf.h"


int get_num_vars(const char *str)
{
    int counter;
    int i;

    if(!str)
        return(0);
    counter = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '%')
            counter++;
        i++;
    }
    return (counter);
    
}

char *get_next_type(char *str)
{
    

    while(*str != '\0')
    {
        if(*str == '%')
        {
            str++;
            return (str);
        }
        str++;
    }
}

int ft_printf(const char *str, ...)
{
    
    
    int num_vars;
    int i;
    char *buff;
    int int_ptr;
    char *str_pointer;

    va_list args;
    va_start(args, str);
    
    num_vars = get_num_vars(str);
    i = 0;
    str_pointer = (char *)str;
    while(i < num_vars)
    {
        str_pointer = get_next_type(str_pointer);
        handle_input(str_pointer, args);
        i++;
    }
    va_end(args);
    return 0;
}

void handle_input(char *str_pointer, va_list args)
{
    if (str_pointer[0] == 's')
        ft_put_str(va_arg(args, char*), 1);
    if (str_pointer[0] == 'd')
        ft_putnbr_fd(va_arg(args, int), 1);
}

int main()
{
    ft_printf("Var num %d  %s", 12, "hola");
}