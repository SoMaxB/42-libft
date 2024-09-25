/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorbarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:51:59 by jorbarro          #+#    #+#             */
/*   Updated: 2024/09/24 18:05:06 by jorbarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char	*ft_xneg(char *dest, char *src)
{
	int	i;

	dest = malloc(12 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		nb;

	str = NULL;
	if (n == -2147483648)
		return (ft_xneg(str, "-2147483648"));
	nb = n;
	digit = ft_count(nb);
	if (n < 0)
		nb *= -1;
	str = malloc((digit + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[digit - 1] = (nb % 10) + 48;
		nb /= 10;
		digit--;
	}
	if (n < 0)
		str[digit] = '-';
	return (str);
}
