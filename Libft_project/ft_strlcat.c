/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpuma <tpuma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:31:41 by tpuma             #+#    #+#             */
/*   Updated: 2022/04/03 16:27:14 by tpuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	SYNOPSIS
	LIBRARY
		#include <string.h>
	PROTOTYPE
	size_t strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
	DESCRIPTION
	strlcat() appends string src to the end of dst. It will append at most
	dstsize - strlen(dst) - 1 characters. It will then NUL - terminate, unless
	dstsize is 0 or the original dst string was longer than dstsize
	(in practice this should not happen as it means that either dstsize is incorrect
	or that dst is not a proper string). If the src and dst strings overlap,
	the behavior is undefined.
	PARAMETERS
			1. A pointer to the destiny string in which to concatenate.
			2. A pointer to the source string to concatenate.
			3. The size of the destination buffer.
	RETURN VALUES
	The strlcat() functions return the total length of the string they tried to
	create, that means the initial length of dst plus the length of src.
	 */

#include "libft.h"
#include<stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	long_dst;
	size_t	long_src;
	size_t	i;

	long_dst = ft_strlen(dst);
	long_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (long_src);
	if (dstsize < long_dst)
		return (dstsize + long_src);
	while ((dst[i] != '\0') && (i < (dstsize - long_dst - 1)))
	{
		dst[long_dst + i] = src[i];
		printf("Debug1: %c\n", dst[long_dst + i]);
		printf("Debug2: %c\n", src[i]);
		i++;
	}
	dst[long_dst + i] = '\0';
	return (dstsize = long_dst + long_src);
}

/* int	main(void)
{
	size_t			l;

	char	dest1[100] = "AMA";
	char	source1[100] = "POLOLO";
	char 	dest2[100] = "AMA";
	char	source2[100] = "POLOLO";

	l = 2;
	printf("%s | %s\n", dest1, source1);
	printf("Mi función: %zu\n", ft_strlcat(dest1, source1, l));
	printf("La concatenación de mi fución es: %s\n", dest1);
	printf("La original: %lu\n", strlcat(dest2, source2, l));
	printf("La concatenación de la original es: %s\n", dest2);
	return (0);
} */