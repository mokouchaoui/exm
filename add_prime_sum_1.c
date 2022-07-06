#include <stdio.h>

int is_prime(int n)
{
    int prime = 2;

    while (n > prime)
    {
        if (n % prime == 0)
            return(0);
        prime++;
    }
    return(1);
}

int		add_prime_sum(int n)
{
	int sum = 0;
	int i = 2;

	while (i <= n)
	{
		if (is_prime(i) == 1)
			sum += i;
		i++;
	}
	return (sum);
}

int main()
{
    printf("%d", add_prime_sum(5));
    return 0;
}
