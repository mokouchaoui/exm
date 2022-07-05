#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_isspace(char c)
{
    if (c == ' ' || c == '\t')  
        return(1);
    return(0);
}

int is_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return(c); 
}

int is_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return(c); 
}

void	str_capitalizer(char *s)
{
	while (*s)
	{
		while (ft_isspace(*s))
			ft_putchar(*s++);
		if (*s && !ft_isspace(*s))
			ft_putchar(is_toupper(*s++));
		while (*s && !ft_isspace(*s))
			ft_putchar(is_tolower(*s++));
	}
}
 
int     main(int argc, char **argv)
{
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        int i = 1;
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            ++i;
        }
    }
       return (0);
}
