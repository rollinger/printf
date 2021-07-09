/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:35:19 by prolling          #+#    #+#             */
/*   Updated: 2021/07/09 15:49:29 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define CONVERSIONS "cspdiuxX"

typedef struct s_chunk
{
	char			*result; 	//The result getting printed
	char			conv;		//The conversion flag cspdiuxX
	struct s_chunk	*next;
}					t_chunk;

int		ft_printf(const char *str, ...);
/* Conversion Functions */
/* Helper Function */
#endif
