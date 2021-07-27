/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:35:19 by prolling          #+#    #+#             */
/*   Updated: 2021/07/22 17:22:37 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FORMAT_FLAG '%'
# define CONVERSIONS "cspdiuxX%"

typedef struct	s_format
{
	char					*str;
	char					conv;
	char					*var_s;
	int						var_i;
	unsigned int			var_ui;
	unsigned long long int	var_ulli;
	size_t					is_neg;
	size_t					flg_space;
	size_t					flg_plus;
	size_t					flg_alt_form;
	size_t					flg_lpad;
	size_t					flg_rpad;
	size_t					field_width;
}				t_format;

int			ft_sprintf(char **str, const char *fstr, ...);
int			ft_printf(const char *fstr, ...);
char		*ft_vprintf(const char *fstr, va_list args);
/* Conversion Functions */
void		ft_convert_variable(t_format *format);
void		ft_apply_flags_to_variable(t_format *format);
void		ft_convert_str(t_format *format);
void		ft_convert_char(t_format *format);
void		ft_convert_int(t_format *format);
void		ft_convert_uint(t_format *format);
void		ft_convert_hex(t_format *format);
void		ft_convert_ptr(t_format *format);
/* Format Functions */
t_format	*build_format_struct(int *fpos, const char *fstr, va_list args);
t_format	*init_format();
void		free_format(t_format *format);
/* Helper Function */
void		reset_fpos(int *fpos, int zero);
char		*ft_strset(const char *s1, const char *s2);
char		*ft_strend(const char *str);
size_t		ft_is_neg(long long int i);
size_t		ft_get_field_width(const char *str);
size_t		print_c(char c);
size_t		print_s(char *s);

#endif
