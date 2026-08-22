#include <stdio.h>

int ft_strlen(char *str)
{
    int n;

    n = 0;
    while(str[n] != '\0')
    {
        n++;
    }
    return(n);
}
/*
int main(void)
{
    char *veta;
    veta =  "Kym vies snivat";
    ft_strlen(veta);
    printf("Dlzka retazca: %d\n", ft_strlen(veta));
    return(0);
}
*/