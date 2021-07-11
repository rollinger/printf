/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:35:19 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 15:12:20 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FORMAT_FLAG '%'
# define CONVERSIONS "cspdiuxX"

typedef struct	s_format
{
	char	*str;
	char	conv;
	void	*var_s;
	int		var_i;
	//...flags
}				t_format;

int			ft_printf(const char *str, ...);
/* Conversion Functions */
t_format	*build_format_struct(char **fpos, va_list args);
void		free_flags(t_format *format);
/* Helper Function */
void		reset_fpos(char **fpos);
size_t		print_c(char c);
size_t		print_s(char *s);

#endif
