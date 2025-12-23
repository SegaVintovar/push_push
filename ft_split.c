/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/21 16:42:19 by vsudak        #+#    #+#                 */
/*   Updated: 2025/12/23 13:42:45 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_push_header.h"

//it returns me an amount of words
//HINT === use a triger - i did not
static size_t	word_count(const char *s, char delimiter)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (i == 0 || s[i - 1] == delimiter))
			wc++;
		i++;
	}
	return (wc);
}

// //return start ofthe word we are looking for index
static size_t	rtrn_strt_of_word(const char *s, char delimiter,\
	size_t word_number)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0' && wc <= word_number)
	{
		while (s[i] == delimiter)
			i++;
		if (s[i] != delimiter && (i == 0 || s[i - 1] == delimiter))
			wc++;
		if (wc - 1 == word_number)
			break ;
		i++;
	}
	return (i);
}

// // returns me a word that i have requested
static char	*get_word(const char *s, size_t word_nbr, char delimiter)
{
	size_t	i;
	size_t	wc;
	size_t	start;
	char	*result;

	wc = 0;
	start = rtrn_strt_of_word(s, delimiter, word_nbr);
	i = start;
	while (s[i] != delimiter && s[i] != '\0')
		i++;
	result = ft_substr(s, start, (i - start));
	return (result);
}

// // Allocate (with malloc(3)) and returns an array of strings
// // obtained by splitting s with the character c, used as delimiter.
// // The returned array must be NUL-terminated.
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	char	**result;

	i = 0;
	wc = word_count(s, c);
	result = malloc((wc + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < wc)
	{
		result[i] = (char *)get_word(s, i, c);
		if (result[i] == NULL)
		{
			i--;
			while (i > 0)
				free(result[i--]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
// int main(int argc, char **argv)
// {
// 	char y = ' ';
// 	size_t i = 1;
// 	size_t j;
// 	char **arr;
// 	while (i < argc)
// 	{
// 		arr = ft_split(argv[i], y);
// 		i++;
// 	}
	
// 	//amount of words in the array(amount of arrays i need)
// 	j = word_count(src, y);
// 	while(i <= j)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	//printf("%s\n", ft_split(src, y));
// }
