/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:35:19 by prolling          #+#    #+#             */
/*   Updated: 2021/08/28 11:14:03 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FORMAT_FLAG '%'
# define CONVERSIONS "cspdiuxX%"

typedef struct s_format
{
	char					*str;
	char					conv;
	char					*var_s;
	char					var_c;
	long long int			var_lli;
	unsigned long long int	var_ulli;
	short					is_neg;
	short					flg_break;
	short					flg_space;
	short					flg_plus;
	short					flg_alt_form;
	short					flg_lpad;
	short					flg_rpad;
	short					flg_zero_pad;
	char					pad_char;
	short					field_width;
	short					precision;
	short					exe_flags;
}				t_format;

int				ft_sprintf(char *str, const char *fstr, ...);
int				ft_printf(const char *fstr, ...);
char			*ft_vprintf(const char *fstr, va_list args);
/* Conversion Functions */
void			ft_convert_variable(t_format *format);
void			ft_apply_flags_to_variable(t_format *format);
void			ft_convert_str(t_format *format);
void			ft_convert_char(t_format *format);
void			ft_convert_percent(t_format *format);
void			ft_convert_int(t_format *format);
void			ft_convert_uint(t_format *format);
void			ft_convert_hex(t_format *format);
void			ft_convert_ptr(t_format *format);
/* Format Functions */
t_format		*build_format_struct(int *fpos, const char *fstr, va_list args);
t_format		*build_conv(t_format *f, int *fpos, \
	const char *fstr, va_list args);
t_format		*build_flags(t_format *f, int *fpos, \
	const char *fstr);
t_format		*init_format(t_format *format);
void			free_format(t_format *format);
/* Helper Function */
void			reset_fpos(int *fpos, int zero);
char			*ft_strset(const char *s1, const char *s2);
char			*ft_strend(const char *str);
size_t			ft_is_neg(long long int i);
size_t			ft_get_field_width(const char *str);
size_t			ft_get_precision(const char *str);
char			ft_get_zero_padding(const char *str);
char			*ft_strfjoin(char *str1, char *str2);
void			ft_printstring(char *s, int fd);
long long int	ft_abs(long long int nbr);
#endif
