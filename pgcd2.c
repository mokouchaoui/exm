void    pgcd(int nb1, int nb2)
{
    if (nb1 > 0 && nb2 > 0)
    {
        while (nb1 != nb2)
        {
           if (nb1 > nb2)
            nb1 -= nb2;
        else
            nb2 -= nb1;
        }  
        printf("%d", nb1);
    }
}
