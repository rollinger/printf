/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:37:55 by prolling          #+#    #+#             */
/*   Updated: 2021/07/09 16:00:45 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Checks at the current position what fragment is actual:
- if char => return 1
- if %%-sign => return -1 (a '%' char)
- if format => return >= 2 (length indicates how long the formatter is)
*/
static int	get_fragment_length(const char *str)
{
	int length;

	length = 1;
	if (*str == '%')
	{
		if (str[length] == '%')
			length = -1;
		else
		{
			length = 2;
			while(ft_strchr(CONVERSIONS, str[length]) == NULL)
				length++;
		}
	}
	return (length);
}

/*
*
*/
static int	process_position(const char *str, va_list args)
{
	int 	current;
	void	**result;

	current = get_fragment_length(str);
	result = NULL;
	if (current == 1)
		ft_putchar((char)*str);
	else if (current == -1)
	{
		ft_putchar('%');
		current = 2;
	}
	else if (current >= 2)
	{
		ft_putchar('#'); //ACTUAL
		*result = va_arg(args, char *);
	}
	return (current);
}

/*
* printf takes a string and variadic data, interpolates it and prints it out.
* <str>	format string containing %<flags><conv> formatter.
* ... elipsis for variadic arguments.
*
// preparse flags and check if type is supported / or otherwise illegal
// print str loop
	// halt at % flag and parse conversion command
	// get (char *) from conversion function (conv, flag, variable)
		// handle error if c,f or v returned NULL from function.
	// print str loop of the conversion
// return int (state convention)
* TODO: protect against !str or !va_args
*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total;

	va_start(args, str);
	total = 0;
	while (str[total] != '\0')
	{
		total += process_position(&str[total], args);
	}
	va_end(args);
	return (total); //return total bytes written
}
