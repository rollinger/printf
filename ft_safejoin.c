/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:49:39 by prolling          #+#    #+#             */
/*   Updated: 2021/09/02 11:11:11 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Safe join makes sure no memory leaks appear with using strjoin
* frees str1 and str2 after join, i.e. the input get freed. 
* Returns <rstr>
*/
char	*ft_strfjoin(char *str1, char *str2)
{
	char	*rstr;

	rstr = NULL;
	if (!str1 && str2)
		rstr = ft_strjoin("", str2);
	else if (str1 && !str2)
		rstr = ft_strjoin((const char *)str1, "");
	else if (str1 && str2)
		rstr = ft_strjoin((const char *)str1, str2);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (rstr);
}

/*
* prints a string and ignores \007 bell character 
* (placeholder for non-printables)
*/
void	ft_putprintfstr(char *s)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		if (*s != '\007')
			write(STDOUT_FD, s, 1);
		++s;
	}
	return ;
}
