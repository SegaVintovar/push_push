#include "push_push_header.h"

void find_lis(int *arr, int size, int *keep)
{
    int dp[size];
    int prev[size];
    int i, j, max = 0, max_i = 0;

	// init em
    for (i = 0; i < size; i++)
    {
        dp[i] = 1;
        prev[i] = -1;
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max)
        {
            max = dp[i];
            max_i = i;
        }
    }

    // mark LIS
    while (max_i != -1)
    {
        keep[max_i] = 1;
        max_i = prev[max_i];
    }
}

// here is mine

void	LIS(t_stack *a)
{
	int dp[a->size];
	size_t	i;
	size_t	p;
	size_t	t;

	i = 0;
	while (i < a->size)
		dp[i++] = 1;
	i = 0;
	//p = 0;
	while (i < a->size)
	{
		p = i;
		while (p >= 0 && p < a->size)
		{
			if (a->arr[i] > a->arr[p])
				dp[i] += 1;
				//smth more here
			p--;
		}
		i++;
	}
	print_stack(dp, a->size);
	int	dp_max = 0;
	i = 0;
	while (i < a->size)
	{
		if (dp[i] > dp_max)
			dp_max = dp[i];
		i++;
	}
	printf("%d\n", dp_max);
	//account from the highest value in dp and mark all the values that are 
}
