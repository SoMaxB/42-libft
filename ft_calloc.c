/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:46:57 by jorbarro          #+#    #+#             */
/*   Updated: 2024/09/20 18:48:39 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*aux;
	size_t			i;

	i = 0;
	aux = malloc(nmemb * size);
	if (!aux)
		return (NULL);
	while (i < nmemb * size)
		aux[i++] = 0;
	return (aux);
}
