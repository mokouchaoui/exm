void    pgcd(int a, int b)
{
    int n = a;
 
    while (n > 0)
    {
        if (a % n == 0 && b % n == 0)
        {
            printf("%d", n);
            return;
        }
        --n;
    }
}
