/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 06:54:41 by prolling          #+#    #+#             */
/*   Updated: 2021/05/28 06:55:47 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Extended strlen that returns if c is found or \0
*/
size_t	ft_strclen(const char *s, char c)
{
	size_t	int_len;

	int_len = 0;
	while (s[int_len] != '\0' && s[int_len] != c)
		int_len++;
	return (int_len);
}
