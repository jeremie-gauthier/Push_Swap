/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:06:57 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/26 13:06:58 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clean_quit(char **conv, int ret)
{
	ft_strdel(conv);
	return (ret);
}

int			ft_conv_double(t_flags *fl, t_buf *buf, va_list ap)
{
	char	*conv;

	if (fl->lm)
		conv = ft_ldtoa(va_arg(ap, long double), (fl->prc == -1) ? 6 : fl->prc);
	else
		conv = ft_dtoa(va_arg(ap, double), (fl->prc == -1) ? 6 : fl->prc);
	if (conv == NULL)
		return (0);
	if (!(ft_format_flag(fl, &conv)))
		return (clean_quit(&conv, 0));
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, conv,
			ft_strlen(conv))))
		return (clean_quit(&conv, 0));
	buf->len += ft_strlen(conv);
	return (1);
}
