/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:17:44 by prolling          #+#    #+#             */
/*   Updated: 2021/05/26 13:27:14 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Allocates (with malloc(3)) and returns a substring from the string ’s’.
* The substring begins at index ’start’ and is of maximum size ’len’.
* Returns The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!sub || !s)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (sub);
	ft_strlcpy(sub, (char *)(s + start), len + 1);
	return (sub);
}
