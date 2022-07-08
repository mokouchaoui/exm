#include <unistd.h>

int is_blank(char c)
{
    if (c == ' ' || c == '\t')
        return(1);
    return(0);
}

void    rostring(char *str)
{
    int i = 0;
    int start;
    int end;
    int flag = 0;
    int r = 0;

    while (is_blank(str[i]))
    i++;
    if (!is_blank(str[i]) && str[i])
        start = i;
    while (!is_blank(str[i]) && str[i])
        i++;
    end = i - 1;
    while (is_blank(str[i]))
    i++;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            flag = 1;
        if (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            if (flag)
                write(1, " ", 1);
            flag = 0;
            write(1, &str[i], 1);
            r = 1;
        }
        i++;
    }
    if (r == 1)
        write(1, " ", 1);
    while (start <= end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1 && argv[1])
    {
       rostring(argv[1]);    
    }
    write(1, "\n", 1);
}
