#include <stdio.h>

int ft_strcmp(char *str1, char *str2)
{
    int n;

    n = 0;
    while(str1[n] != '\0' && str1[n] == str2[n])
    {
        n++;
    }
    return(str1[n] - str2[n]);
}
/*
int main(void)
{
    char *veta1;
    char *veta2;
    veta1 =  "Kym vies snivat";
    veta2 = "Kymvies snivat";

    printf("Dlzka retazca: %d\n", ft_strcmp(veta1, veta2));
    return(0);
}
*/
