#include <stdlib.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

char *creat_wrd(char *str)
{
    char *new;
    int i = 0;

    new = (char *) malloc(sizeof(char *) * 1000);
    while (str[i] && !is_space(str[i]))
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return(new);
}

char **ft_split(char *str)
{
    int i;
    char **tab;

    i = 0;
    tab = (char **)malloc (sizeof(char ) * 1000);
    
    while (*str)
    {
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str && !is_space(*str))
    {
        tab[i] = creat_wrd(str);
        i++;
        while (*str && !is_space(*str))
            str++;
    }
    }
    tab[i] = 0;
    return(tab);
}


 #include <stdio.h>

 int		main(int ac, char **av)
 {
 	char **arr;

 	char *phrase = "   Hello,   Flavio\t Wuensche!  ";
 	arr = ft_split(phrase);
 	printf("%s\n", arr[0]);
 	printf("%s\n", arr[1]);
 	printf("%s\n", arr[2]);
 	printf("%s\n", arr[3]);
 }
