#include "ultra_utils.h"

static int	ft_dgts(long int n)
{
	int div;
	int i;

	div = 1;
	i = 0;
	n = n < 0 ? n * -1 : n;
	if (n < 10)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			dgts;
	int			min;
	long int	n2;
	char		*p;

	dgts = n >= 0 ? ft_dgts(n) : ft_dgts(n) + 1;
	if (!(p = malloc(dgts + 1)))
		return (0);
	min = n >= 0 ? 0 : 1;
	p[0] = '-';
	p[dgts] = 0;
	n2 = n;
	n2 *= n >= 0 ? 1 : -1;
	while (--dgts >= min)
	{
		p[dgts] = n2 % 10 + 48;
		n2 /= 10;
	}
	return (p);
}

int	ft_atoi(const char *str)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		sign = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str++ <= '9')
		ret = *(str - 1) - 48 + 10 * ret;
	return (ret * sign);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}