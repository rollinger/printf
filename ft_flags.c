/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 11:58:03 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Builds the structure of conversion, flags and variable and returns it. Used
* for later interpolation
*/
t_flags	build_flags_struct(char **fpos, va_list args)
{
	t_flags	flags;

	flags->conv = *fpos[2];
	if (flags->conv == 's')
		flags->var = va_arg(args, char *);
	else if (flags->conv == 'c')
		flags->var = va_arg(args, char);
	return (flags);
}
