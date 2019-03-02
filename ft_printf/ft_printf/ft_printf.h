/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:50 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/07 00:07:51 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define ALL_FLAGS	"Llh+- .#0123456789,"
# define ALL_CONV	"cspdiouxXbf%"
# define REDIRECT	"DIOU"
# define INT_CONV	"di"
# define UINT_CONV	"ouxXb"
# define BASE_CONV	"oxXb"
# define CHAR_CONV	"cs%"
# define SEPARABLES	"iduf"
# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"
# define REVERSE	"\033[7m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define BG_BLACK	"\033[40m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"
# define CLEAR		"\e[1;1H\e[2J"


typedef struct	s_buf
{
	void			*str;
	size_t			len;
}				t_buf;

typedef struct	s_flags
{
	unsigned short	hh	: 1;
	unsigned short	h	: 1;
	unsigned short	l	: 1;
	unsigned short	ll	: 1;
	unsigned short	lm	: 1;
	unsigned short	dz	: 1;
	unsigned short	f0	: 1;
	unsigned short	mo	: 1;
	unsigned short	pl	: 1;
	unsigned short	sp	: 1;
	unsigned short	com	: 1;
	unsigned short	base: 5;
	int				prc;
	int				pad;
	char			c;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *s, size_t size, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vsprintf(char *s, const char *format, va_list ap);
int				ft_vsnprintf(char *s, size_t size, const char *format,
					va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
t_buf			*init_buf(void);
t_flags			*init_flags(void);
void			add_flag(const char c, t_flags *fl);
int				parse_format(const char **format, t_buf *buf);
int				parse_flags(const char **format, t_buf *buf, va_list ap);
int				ft_parse_color(const char **format, t_buf *buf);
void			redirection_conversion(t_flags *fl);
int				conversion(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_numeric(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_double(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_str(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_ptr(t_flags *fl, t_buf *buf, va_list ap);
int				ft_format_flag(t_flags *fl, char **conv);
int				ft_format_prc(t_flags *fl, char **conv, int *len);
int				ft_zero_value_numeric_conv_zero_prc(t_flags *fl, char **conv);
int				ft_format_plus_space(t_flags *fl, char **conv, int sign);
int				compute_padding_len(t_flags *fl, int len, int sign);
int				ft_format_padding(t_flags *fl, char **conv, int len, int sign);
int				ft_format_diese(t_flags *fl, char **conv);
int				ft_format_char(t_flags *fl, t_buf *buf, unsigned char c);
int				ft_format_str(t_flags *fl, char **conv, int len, t_buf *buf);
int				dieze_position(t_flags *fl, char **conv, int len, int sign);
int				plus_position(t_flags *fl, char **conv, int len, int sign);
int				format_sign(t_flags *fl, char **conv, int len, int sign);
int				format_no_sign(t_flags *fl, char **conv, int len, int sign);
int				ft_format_comma(t_flags *fl, char **conv);

#endif
