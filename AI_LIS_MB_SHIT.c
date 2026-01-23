#include "push_push_header.h"

// void find_lis(t_stack *a)
// {
//     int dp[a->size];
//     int prev[a->size];
//     int i, j, max = 0, max_i = 0;

// 	// init em
//     for (i = 0; i < a->size; i++)
//     {
//         dp[i] = 1;
//         prev[i] = -1;
//     }
// 	i = 0;
//     while ( i < a->size)
//     {
// 		j = 0;
//         while (j < i)
//         {
//             if (a->arr[j] < a->arr[i] && dp[j] + 1 > dp[i])
//             {
//                 dp[i] = dp[j] + 1;
//                 prev[i] = j;
//             }
// 			j++;
//         }
//         if (dp[i] > max)
//         {
//             max = dp[i];
//             max_i = i;
//         }
// 		i++;
//     }
// 	a->keep = malloc(a->size * sizeof(int));
//     // mark LIS
//     while (max_i != -1)
//     {
//         a->keep[max_i] = 1;
//         max_i = prev[max_i];
//     }
// 	print_stack(a->keep, (sizeof(a->keep) / sizeof(a->keep[0])));
// }

// here is mine

void	dp_init(int *dp, size_t size)
{
	size_t	i;

	dp = malloc(size * sizeof(int));
	if (!dp)
		exit(1);
	i = 0;
	while (i < size)
		dp[i++] = 1;
}

//creation of the dp
int	*dp(t_stack *a)
{
	int		*dp;
	int		i;
	int		p;
	int		last;

	dp_init(dp, a->size);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		last = a->arr[i];
		p = i - 1;
		while (p >= 0)
		{
			if (last > a->arr[p])
			{
				dp[i] += 1;
				last = a->arr[p];
			}
			p--;
		}
		i++;
	}
	return(dp);
}

size_t	dp_max(t_stack *a, int *dp)
{
	size_t	dp_max;
	size_t	i;
	size_t	dp_max_i;
	
	dp_max = 0;
	i = 0;
	while (i < a->size)
	{
		if (dp[i] > dp_max)
		{
			dp_max = dp[i];
			dp_max_i = i;
		}
		i++;
	}
	a->keep_size = dp_max;
	printf("dp max: %zu\n", dp_max);
	return(dp_max);
}

// void	keep_creation(t_stack *a, int *dp, int max, size_t max_i)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < max)
// 	{
// 		keep[i] = 
// 		i++;
// 	}
	
// }

void	LIS2(t_stack *a)
{
	int		*dp_arr;
	size_t	max_dp;
	size_t	i;	

	dp_arr = dp(a);
	if (!dp_arr)
		exit(1);
	max_dp = dp_max(a, dp_arr);
	// look for max in arr and find its index
	i = 0;
	while (dp_arr[i] != max_dp)
	{
		i++;
	}
	//now i want to save all sequenced values in a->keep
	a->keep = malloc(a->keep_size * sizeof(int));
	if (!a->keep)
		exit(1);
	//keep_creation(a, dp_arr, max_dp, a->keep_size);
	free(dp_arr);
}


void	LIS(t_stack *a)
{
	int		i;
	int		p;
	int		t;
	int		last;
	int		dp_max_i;
	int		try1;
	int		try2;

	i = 0;
	t = 1;
	while (i < a->size)
	{
		last = a->arr[i];
		p = i - 1;
		while (p >= 0)
		{
			if (last > a->arr[p])
			{
				try1 = a->arr[p];
				while ((p - t) > 0 && t < 5)
				{
					if (a->arr[p - t] > try1 && a->arr[p - t] < last)
					{
						try2 = a->arr[p - t];
						t = 1;
						break;
					}
					t++;
				}
				a->lis[i] += 1;
				last = try2;
				//last = a->arr[p];
				//lets try to check for an extra value that might be better
				//closer to the last element of the sequence that we found before
			}
			p--;
		}
		i++;
	}

	print_stack(a->lis, a->size);
	size_t	ls_max = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->lis[i] > ls_max)
		{
			ls_max = a->lis[i];
			dp_max_i = i;
		}
		i++;
	}
	printf("dp max: %zu\n", dp_max);
	//return(dp_max);
}

//here i want just values that I want to keep in the stack_a
// void	keep_creation(t_stack *a)
// {
// 	a->keep = malloc(LIS)()

// }
