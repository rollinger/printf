/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:46:29 by prolling          #+#    #+#             */
/*   Updated: 2021/07/09 13:34:09 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		nc;
	int		percent;
	char	*name;

	name = "Philipp";
	percent = 98;
	ft_putstr("Show ft_printf function visually:\n");
	nc = ft_printf("Hello! My name is %s. I am a %i%% male.\n", name, percent);
	ft_putnbr_fd(nc, 1);
	return (0);
}
