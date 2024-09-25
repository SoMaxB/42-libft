/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:50:11 by jorbarro          #+#    #+#             */
/*   Updated: 2024/09/24 18:21:29 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_stringptr_length(const char *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			count++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (count);
}

static int	get_len(const char *s, char c, int i)
{
	int	start_i;

	while (s[i] && s[i] == c)
	{
		i++;
	}
	start_i = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			break ;
		}
		i++;
	}
	return (i - start_i);
}

static void	fill_string(const char *str_in, char *str_out, char c, int *i)
{
	int	j;

	j = 0;
	while (str_in[*i] && str_in[*i] == c)
	{
		(*i)++;
	}
	while (str_in[*i])
	{
		if (str_in[*i] == c)
		{
			break ;
		}
		str_out[j] = str_in[*i];
		(*i)++;
		j++;
	}
}

char	**free_all(char **failed_array, int length)
{
	while (length)
	{
		free(failed_array[length - 1]);
		length--;
	}
	free(failed_array);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		str_count;
	int		i;
	int		j;
	char	**str_array;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	str_count = get_stringptr_length(s, c, 0);
	str_array = (char **)ft_calloc(str_count + 1, sizeof(char *));
	if (!str_array)
		return (0);
	while (s[i] && j < str_count)
	{
		str_array[j] = (char *)ft_calloc(get_len(s, c, i) + 1, sizeof(char));
		if (!str_array[j])
			return (free_all(str_array, j));
		fill_string(s, str_array[j], c, &i);
		j++;
	}
	return (str_array);
}
