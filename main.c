#include "ft_printf.h"
int main()
{
     char *name;
    int n;
    int num;


    setbuf(stdout, NULL);
    name = "cristina";
    num = printf("Hello my name is %s\n", name);
    printf("%d", num);
    n = ft_printf("Hello my name is %s\n", name);
    printf("%d", n);

    printf("\n...............................\n");

    int number;

    number = 10000;
    num = printf("Hello my number is %d\n", number);
    printf("%d", num);
    n = ft_printf("Hello my number is %d\n", number);
    printf("%d", n);

    printf("\n...............................\n");

    #include <limits.h>
   

    number = INT_MAX;
    num = printf("Hello my number is %d\n", number);
    printf("%d", num);
    n = ft_printf("Hello my number is %d\n", number);
    printf("%d", n);


    printf("\n...............................\n");   

    char c ='a';

    num = printf("Hello my char is %c\n", c);
    printf("%c", c);
    n = ft_printf("Hello my char is %c\n", c);
    printf("%d", n);



    printf("\n...............................\n");   

    char *p ="pointer";

    num = printf("Hello my pointer is %p\n", p);
    printf("%d", num);
    num = ft_printf("Hello my pointer is %p\n", p);
    printf("%d", num);

    printf("\n...............................\n");   

    char *point = 0;
    num = printf("%p\n", point);
    printf("%d", num);
    
    printf("\n...............................\n");  
    num = ft_printf("%p\n", point);
    printf("%d", num);



    printf("\n...............................\n");   

    unsigned int u = 852099;  


    num = printf("Hello my unsigned integer is %u\n", u);
    printf("%d\n", num);

    num = ft_printf("Hello my unsigned integer is %u\n", u);
    printf("%d\n", num);





    printf("\n...............................\n");   

    unsigned int x = 852099;  


    num = printf("Hello my unsigned integer is %x\n", x);
    printf("%d\n", num);

    num = ft_printf("Hello my unsigned integer is %x\n", x);
    printf("%d\n", num);



     printf("\n...............................\n");   

    unsigned int X = 852099;  


    num = printf("Hello my unsigned integer is %X\n", x);
    printf("%d\n", num);

    num = ft_printf("Hello my unsigned integer is %X\n", x);
    printf("%d\n", num);
 
}