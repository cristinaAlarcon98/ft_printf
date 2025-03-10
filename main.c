
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

    unsigned long long u = 8520982409;  // Using unsigned long long


    // Using the correct format specifier %llu for unsigned long long
    num = printf("Hello my unsigned integer is %llu\n", u);
    printf("%d\n", num);

    // Assuming ft_printf is implemented correctly, use the same %llu specifier
    num = ft_printf("Hello my unsigned integer is %llu\n", u);
    printf("%d\n", num);

}