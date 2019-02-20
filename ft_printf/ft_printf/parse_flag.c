/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:08:02 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:08:03 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clean_quit(t_flags **fl, int ret)
{
	ft_memdel((void**)fl);
	return (ret);
}

/*
**	Add the numeric values (precision and padding) to the struct.
*/

static void	add_numeric_flags(t_flags *fl, const char **format)
{
	if (**format == '.')
	{
		(*format)++;
		fl->prc = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_isdigit(**format) && **format != '0')
	{
		fl->pad = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static void	set_base_conv(t_flags *fl)
{
	if (fl->c == 'b')
		fl->base = 2;
	else if (fl->c == 'o')
		fl->base = 8;
	else if (fl->c == 'x' || fl->c == 'X')
		fl->base = 16;
}

/*
**	Function that parse from '%' to a conversion character ["cspdiouxXb"] and
**	fill the struct.
*/

int			parse_flags(const char **format, t_buf *buf, va_list ap)
{
	t_flags	*fl;

	if (!(fl = init_flags()))
		return (0);
	(*format)++;
	while (**format && ft_instr(**format, ALL_FLAGS))
	{
		add_flag(**format, fl);
		if (**format == '.' || (ft_isdigit(**format) && **format != '0'))
			add_numeric_flags(fl, format);
		else
			(*format)++;
	}
	if (ft_instr(**format, ALL_CONV) || ft_instr(**format, REDIRECT))
	{
		fl->c = **format;
		if (ft_instr(**format, REDIRECT))
			redirection_conversion(fl);
		set_base_conv(fl);
		if (!(conversion(fl, buf, ap)))
			return (clean_quit(&fl, 0));
		if (**format)
			(*format)++;
	}
	return (clean_quit(&fl, 1));
}
