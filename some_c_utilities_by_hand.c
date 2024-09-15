#include <unistd.h>

void	ft_printnbr(int nbr)
{
    if (nbr == -2147483648)
    {
	write(1, "-2147483648", 11);
	return ;
    }
    if (nbr >= 0 && nbr <= 9)
    {
	nbr += 48;
	write(1, &nbr, 1);
    } else if (nbr < 0)
    {
	write(1, "-", 1);
	nbr *= -1;
	ft_printnbr(nbr);
    } else {
	ft_printnbr(nbr / 10);
	ft_printnbr(nbr % 10);
    }
}

void	ft_printstr(char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
	write(1, &str[i++], 1);
}

int 	ft_strlen(char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
	i++;
    return (i);
}

int 	ft_strcmp(char *str_one, char *str_two)
{
    while (*str_one && (*str_one == *str_two))
    {
	str_one++;
	str_two++;
    }
    return *(unsigned char *)str_one - *(unsigned char *)str_two;
}

int main(int argc, char **argv)
{
    char	*str_len_option = "len";
    if (argc < 3)
    {
	ft_printstr("ERROR: too few arguments\n");
	return (1);
    }
    if (ft_strcmp(str_len_option, argv[1]) == 0) //the prompt is equal to the option
    {
	ft_printstr("the string length is: ");
	ft_printnbr(ft_strlen(argv[2]));
    }
    else
    {
	ft_printstr("the option is incorect\n");
    }
    return (0);
}
