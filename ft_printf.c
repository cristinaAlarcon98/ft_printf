
#include <stdarg.h>
#include <stdio.h>

int ft_caca(const char *str, ...)
{
    
    va_list args;
    va_start(args, str);

    const char *current_str = str;
    while(current_str)
    {
        printf("%s", current_str);
        current_str = va_arg(args, const char*);
    }
    va_end(args);
    return 0;
}

void main()
{
    ft_caca("HOLA","ME","LLAMO");
}