/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpuma <tpuma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:04:33 by tpuma             #+#    #+#             */
/*   Updated: 2022/04/02 18:18:02 by tpuma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* SYNOPSIS
LIBRARY
	#include <string.h>
PROTOTYPE
size_t strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
DESCRIPTION
The strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0. It take the full size of the
destination buffer and guarantee NUL-termination if there is room.
Note that room for the NUL should be included in dstsize.
PARAMETERS
		1. The destiny string in which to write.
		2. The source string to copy.
		3. The final number of bytes copied.
RETURN VALUES
The strlcpy() return the total length of the string they tried to create, that means the length of src.
If the return value is >= dstsize, the output string has been truncated.
 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dst[i] == 0)
		return (j);
	while ((src[i] != '\0') && (i < dstsize))
	{
		if ((src[i] != '\0') && (i < dstsize - 1))
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (j);
}