/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:40:08 by jorbarro          #+#    #+#             */
/*   Updated: 2024/09/19 19:31:03 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	j;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == '\0')
	{
		return ((char *) big);
	}
	while (i < len && big[i] != '\0')
	{
		if (i + little_len <= len && big[i] == little[0])
		{
			j = 0;
			while (j < little_len && big[i + j] == little[j])
				j++;
			if (j == little_len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
