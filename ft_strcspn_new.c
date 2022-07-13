#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;

    while(s[i])
    {
        while (reject[j])
        {
            if (reject[j] == s[i])
          
                return(i);
            j++;
        }
        j = 0;
        i++;
    }
    while (s[i])
        i++;
    return (i);
    
}
