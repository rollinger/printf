/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:42:01 by prolling          #+#    #+#             */
/*   Updated: 2021/08/31 10:42:57 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Returns the absolute value of a lli number
*/
long long int	ft_abs(long long int nbr)
{
	if (nbr < 0)
		return (nbr *-1);
	return (nbr);
}

/*
* Returns a sequence of <n> times char <c>. Returns the <seq>
*/
char	*ft_seqc(size_t n, int c)
{
	char	*seq;
	char	*m;

	if (!n || !c)
		return (NULL);
	seq = (char *)ft_calloc(sizeof(char), n + 1);
	if (!seq)
		return (NULL);
	m = seq;
	while (n--)
		*m++ = (unsigned char)c;
	return (seq);
}

/*
* ft_lpad and ft_rpad pad the <str> with <c> for a total of <size>bytes. If the
* size <= strlen(str) nothing happens. The function returns a ptr to the new
* allocated str
*/

/*
* Expands a <str> to the total <size> and pads it on the left side with <c>
* Returns the <padding>
*/
char	*ft_lpad(char *str, size_t size, int c)
{
	char	*padding;
	char	*ret;

	if (!str || size <= ft_strlen(str))
		return (str);
	padding = ft_seqc(size - ft_strlen(str), c);
	if (padding)
	{
		ret = ft_strjoin(padding, str);
		free(padding);
		free(str);
		return (ret);
	}
	return (NULL);
}

/*
* Expands a <str> to the total <size> and pads it on the right side with <c>
* Returns the <padding>
*/
char	*ft_rpad(char *str, size_t size, int c)
{
	char	*padding;
	char	*ret;

	if (!str || size <= ft_strlen(str))
		return (str);
	padding = ft_seqc(size - ft_strlen(str), c);
	if (padding)
	{
		ret = ft_strjoin(str, padding);
		free(padding);
		free(str);
		return (ret);
	}
	return (NULL);
}
