/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:22:20 by jorbarro          #+#    #+#             */
/*   Updated: 2024/09/24 18:11:02 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*b;

	b = s;
	i = 0;
	while (i < n)
	{
		if (b[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
