/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:31:58 by kdustin           #+#    #+#             */
/*   Updated: 2020/09/12 19:38:19 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (!c)
		return ((char*)(s + i));
	return (NULL);
}

size_t	gnl_strlen(const char *str)
{
	size_t i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*data_add(char *data, const char *buf, int buf_data_len)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = malloc(sizeof(char) * (gnl_strlen(data) + buf_data_len + 1))))
		return (NULL);
	i = 0;
	while (data != NULL && data[i] != '\0')
	{
		result[i] = data[i];
		i++;
	}
	j = i;
	i = 0;
	while (i < buf_data_len)
		result[j++] = buf[i++];
	result[j] = '\0';
	free(data);
	return (result);
}

char	*gnl_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*p;

	len = gnl_strlen(s1);
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*cut_first_line(char **data)
{
	char *result;
	char *data_cutted;
	char *separator;

	data_cutted = NULL;
	if ((separator = gnl_strchr(*data, '\n')) != NULL)
	{
		if (separator[1] != '\0' && !(data_cutted = gnl_strdup(separator + 1)))
			return (NULL);
		*separator = '\0';
		if (!(result = gnl_strdup(*data)))
		{
			free(data_cutted);
			return (NULL);
		}
		free(*data);
		*data = data_cutted;
		return (result);
	}
	if (*data == NULL)
		result = gnl_strdup("");
	else
		result = *data;
	*data = NULL;
	return (result);
}
