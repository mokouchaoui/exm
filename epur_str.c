#include <unistd.h>

void    epur_str(char *str)
{
    int i = 0;
    int flag = 0;
    
    while (str[i] == ' ' || str[i] == '\t')
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
        }
        i++;

    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
}
