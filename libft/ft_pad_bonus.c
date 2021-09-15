/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:51:41 by prolling          #+#    #+#             */
/*   Updated: 2021/07/13 15:49:27 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* ft_lpad and ft_rpad pad the <str> with <c> for a total of <size>bytes. If the
* size <= strlen(str) nothing happens. The function returns a ptr to the new
* allocated str.tion has the new floor plan and two of
*/

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
* Expands a <str> to the total <size> and pads it on the left side with <c>
* Returns the <padding>
*/
char	*ft_lpad(char *str, size_t size, int c)
{
	char	*padding;

	if (!str || size <= ft_strlen(str))
		return (str);
	padding = ft_seqc(size - ft_strlen(str), c);
	if (padding)
		return (ft_strjoin(padding, str));
	return (NULL);
}

/*
* Expands a <str> to the total <size> and pads it on the right side with <c>
* Returns the <padding>
*/
char	*ft_rpad(char *str, size_t size, int c)
{
	char	*padding;

	if (!str || size <= ft_strlen(str))
		return (str);
	padding = ft_seqc(size - ft_strlen(str), c);
	if (padding)
		return (ft_strjoin(str, padding));
	return (NULL);
}
