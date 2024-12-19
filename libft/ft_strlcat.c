/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalinow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:29:49 by smalinow          #+#    #+#             */
/*   Updated: 2024/12/16 19:29:52 by smalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_strlen(const char *str, int max_len)
{
	int	i;

	i = 0;
	while (str[i] && i < max_len)
		i++;
	return (i);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	dst_len;
	int	src_len;

	dst_len = ft_strlen(dst, dstsize);
	src_len = ft_strlen(src, INT_MAX);
	if (dstsize == 0)
		return (src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (i < dstsize - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
