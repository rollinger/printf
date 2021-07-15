/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:35:19 by prolling          #+#    #+#             */
/*   Updated: 2021/07/15 10:47:23 by prolling         ###   ########.fr       */
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
	char					*str;
	char					conv;
	char					*var_s;
	int						var_i;
	unsigned int			var_ui;
	unsigned long long int	var_ulli;
	size_t					field_width;
	size_t					flg_space;
	size_t					flg_hash;
	size_t					flg_plus;
}				t_format;

//int			ft_sprintf(char *str, const char *format, ...);
int			ft_printf(const char *str, ...);
/* Conversion Functions */
void		ft_convert_variable(t_format *format);
void		ft_convert_str(t_format *format);
void		ft_convert_char(t_format *format);
void		ft_convert_int(t_format *format);
void		ft_convert_uint(t_format *format);
void		ft_convert_hex(t_format *format);
void		ft_convert_ptr(t_format *format);
/* Format Functions */
t_format	*build_format_struct(char **fpos, va_list args);
t_format	*init_format();
void		free_format(t_format *format);
/* Helper Function */
void		reset_fpos(char **fpos, const char *zero);
size_t		print_c(char c);
size_t		print_s(char *s);

#endif
