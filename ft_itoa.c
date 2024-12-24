/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                       :+:      :+:    :+:      */
/*                                                    +:+ +:+         +:+     */
/*   By: smalinow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:19:28 by smalinow          #+#    #+#             */
/*   Updated: 2024/12/05 20:19:48 by smalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

static int	is_negative(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	digit_amount(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static char	*str_reverse(char *src)
{
	int		i;
	int		str_len;
	char	temp;

	i = 0;
	while (src[i])
		i++;
	str_len = i - 1;
	i = 0;
	while (str_len > i)
	{
		temp = src[i];
		src[i] = src[str_len];
		src[str_len] = temp;
		i++;
		str_len--;
	}
	return (src);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_length;
	int		i;
	int		sign;

	if (n == -2147483648)
		return ("-2147483648");
	n_length = digit_amount(n);
	result = (char *) malloc(sizeof(char) * (n_length + 2));
	if (!result)
		return (NULL);
	sign = is_negative(n);
	n *= sign;
	i = 0;
	while (n_length > i)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (sign == -1)
		result[i] = '-';
	result[i + (sign == -1)] = '\0';
	return (str_reverse(result));
}
