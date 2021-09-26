/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:27:51 by prolling          #+#    #+#             */
/*   Updated: 2021/09/21 11:10:40 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Resets fpos to NULL at index 1 & 2
* 0: counter for pos in fstr
* 1: start of current block
* 2: end of current block
* 3: flag 1=normal, 2=interpolate
*/
void	reset_fpos(int *fpos, int zero)
{
	fpos[0] = zero;
	fpos[1] = 0;
	fpos[2] = 0;
	fpos[3] = 0;
	fpos[4] = 0;
	return ;
}

/*
* The strset() function returns a pointer to the first occurrence of any char
* in the string s2 in the string s1.
* RETURN: like the  strchr()  and strrchr() functions return a pointer to
* the matched character or NULL if the character is not found.
* The terminating null byte is considered part of the string, so that if c is
* specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strset(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (ft_strchr(s2, *s1))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}

/*
* Returns a character pointer to the end of str (\0)
*/
char	*ft_strend(const char *str)
{
	while (*str != '\0')
		++str;
	return ((char *)str);
}

/*
* checks if i is negative or positive
*/
size_t	ft_is_neg(long long int i)
{
	if (i < 0)
		return (1);
	return (0);
}
