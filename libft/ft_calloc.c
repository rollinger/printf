/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:19:19 by prolling          #+#    #+#             */
/*   Updated: 2021/08/04 15:30:07 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
* The calloc() function allocates memory for an array of nmemb elements of size
* bytes each and returns a pointer to the allocated memory. The memory is set
* to zero. If nmemb or size is 0, then calloc() returns either NULL, or a
* unique pointer value that can later be successfully passed to free().
* size_t: unsigned int (kind of guaranteed to hold array indexes)
* BUG: if nmemb*size > size_t then should return error.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*m;
	size_t			bytes;

	bytes = nmemb * size;
	arr = malloc(bytes);
	if (bytes && arr)
	{
		m = arr;
		if (arr)
			while (bytes--)
				*(m++) = '\0';
	}
	return (arr);
}
