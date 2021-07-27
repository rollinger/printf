/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:27:51 by prolling          #+#    #+#             */
/*   Updated: 2021/07/22 16:02:28 by prolling         ###   ########.fr       */
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
	return ;
}

/*
* Right shift down. [1]==[2] && [2]==0
*/
void	shift_fpos(int **fpos)
{
	fpos[1] = fpos[2];
	fpos[2] = 0;
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
* Prints a character and returns 1 as the length
*/
size_t	ft_is_neg(long long int i)
{
	if (i < 0)
		return (1);
	return (0);
}

size_t	ft_get_field_width(const char *str)
{
	while(*str != '\0')
	{
		if (*str >= '1' && *str <= '9')
			return (ft_atoi(str));
		str++;
	}
	return (0);
}

/*
* Prints a character and returns 1 as the length

size_t	print_c(char c)
{
	ft_putchar(c);
	return (1);
}*/

/*
* Prints the string and return the length of the string.

size_t	print_s(char *s)
{
	if (s)
	{
		ft_putstr(s);
		return (ft_strlen(s));
	}
	return (0);
}*/
