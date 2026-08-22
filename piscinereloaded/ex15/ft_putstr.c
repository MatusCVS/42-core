void    ft_putchar(char c);
void    ft_putstr(char *str)
{
    int n;

    n = 0;
    while(str[n] != '\0')
    {
        ft_putchar(str[n]);
        n++;
    }
}
/*
int main(void)
{
    char *veta;
    veta =  "Kym vies snivat";
    ft_putstr(veta);
    return(0);
}
*/