/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:49:12 by kdustin           #+#    #+#             */
/*   Updated: 2020/05/21 17:50:54 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char *s, char c)
{
	char	*end_of_word;
	size_t	counter;

	if (c == '\0')
		return (1);
	if (ft_strncmp(s, "", 1) == 0)
		return (0);
	counter = 0;
	end_of_word = s;
	while ((end_of_word = ft_strchr(end_of_word, c)) != NULL)
	{
		while (end_of_word[0] == c)
			end_of_word++;
		counter++;
	}
	counter++;
	return (counter);
}

static char	**fill_array(char **array, char *str, char c)
{
	char	*start;
	char	*end;
	char	**first;

	first = array;
	start = str;
	end = str;
	while ((end = ft_strchr(start, c)) != NULL && c != '\0')
	{
		*end = '\0';
		if (!(*array = ft_strdup(start)))
			return (NULL);
		while ((++end)[0] == c)
			;
		start = end;
		array++;
	}
	if (ft_strncmp(start, "", 1) != 0)
	{
		if (!(*array = ft_strdup(start)))
			return (NULL);
	}
	return (first);
}

static char	**free_every_thing(char *copy, char *set, char **result, size_t n)
{
	size_t	i;

	if (copy != NULL)
		free(copy);
	if (set != NULL)
		free(set);
	if (result != NULL)
	{
		i = 0;
		while (i < n)
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	*copy;
	char	*set;
	char	**result;
	size_t	size;

	size = 0;
	copy = NULL;
	set = NULL;
	result = NULL;
	if (!(set = (char*)ft_calloc(2, sizeof(char))))
		return (NULL);
	set[0] = c;
	if (!(copy = ft_strtrim(s, set)))
		return (free_every_thing(copy, set, result, size));
	size = get_size(copy, c) + 1;
	if (!(result = (char**)ft_calloc(size, sizeof(char*))))
		return (free_every_thing(copy, set, result, size));
	if (!(result = fill_array(result, copy, c)))
		return (free_every_thing(copy, set, result, size));
	free(copy);
	free(set);
	return (result);
}
