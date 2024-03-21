/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:49:29 by nmellal           #+#    #+#             */
/*   Updated: 2023/11/18 17:54:34 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;

	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	dtmp = (unsigned char *)dest;
	stmp = (unsigned char *)src;
	while (n > 0)
	{
		*dtmp = *stmp;
		dtmp++;
		stmp++;
		n--;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main
// (void)
// {
// 	char s1[] = "0123456789abcdef";
// 	char s2[] = "0123456789abcdef";
// 	printf("%s\n", memcpy(&s1[3], &s1[0], 6));
// 	printf("%s\n",ft_memcpy(&s2[3], &s2[3], 6));
// }
