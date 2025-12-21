
#include <stdio.h>

int is_number(char *arg)
{
	unsigned int	i;
	
	i = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int is_unique(char **arg)
{
	
}

int main()
{
	char str[6] = " -23a";

	printf("%d\n", is_number(str));

}