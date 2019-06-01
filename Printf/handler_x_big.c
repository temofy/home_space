/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_x_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:00:13 by aaeron-g          #+#    #+#             */
/*   Updated: 2019/05/30 12:05:24 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_big_zero(t_formatting *e_sequence, int *len, char *res)
{
	*len = e_sequence->width;
	if (e_sequence->flags->hash == 1)
	{
		*len = *len + 1;
		res = ft_strdup(" ");
	}
	res = ft_strdup(" ");
	if (e_sequence->width == -1)
	{
		e_sequence->common_length = 0;
		return (ft_strdup(" "));
	}
	while (e_sequence->width >= 0)
	{
		res = ft_strjoin(res, " ");
		e_sequence->width--;
	}
	e_sequence->common_length += *len;
	return (res);
}

char	*hex_b_n_z(t_formatting *e_sequence, int *len, char *res, char *hex)
{
	if (e_sequence->flags->hash == 1)
		*len = *len + 2;
	while (*len < e_sequence->width)
	{
		res = ft_strjoin("0", res);
		*len = *len + 1;
	}
	if (e_sequence->flags->hash == 1 && !ft_strequ(hex, "0"))
		res = ft_strjoin("0X", res);
	return (res);
}

char	*hex_big_while(t_formatting *e_sequence, int *len, char *res)
{
	while (*len < e_sequence->width)
	{
		res = ft_strjoin(" ", res);
		*len = ft_strlen(res);
	}
	return (res);
}

char	*hex_big_else(t_formatting *e_sequence, int *len, char *res, char *hex)
{
	while (*len < e_sequence->precision)
	{
		res = ft_strjoin("0", res);
		*len = ft_strlen(res);
	}
	if (e_sequence->flags->hash == 1 && !ft_strequ(hex, "0"))
	{
		res = ft_strjoin("0X", res);
		*len = *len + 2;
	}
	if (e_sequence->flags->minus == 1)
	{
		while (*len < e_sequence->width)
		{
			res = ft_strjoin(res, " ");
			*len = ft_strlen(res);
		}
	}
	else
		res = hex_big_while(e_sequence, len, res);
	return (res);
}

char	*handler_x_big(va_list arg, t_formatting *e_sequence)
{
	char	*hex;
	char	*res;
	int		len;

	if (e_sequence->length_modifier == 106 ||\
		e_sequence->length_modifier == 108 ||\
		e_sequence->length_modifier == 216)
		hex = hex_big_total_l((long long int)va_arg(arg, void *));
	else
		hex = hex_big_total((int)va_arg(arg, void *));
	if (ft_strequ(hex, "0") && e_sequence->precision == 0)
	{
		res = hex_big_zero(e_sequence, &len, res);
		return (res);
	}
	res = hex;
	len = ft_strlen(hex);
	if (e_sequence->precision <= 0 && e_sequence->flags->minus == 0\
	&& e_sequence->flags->zero == 1)
		res = hex_b_n_z(e_sequence, &len, res, hex);
	else
		res = hex_big_else(e_sequence, &len, res, hex);
	e_sequence->common_length += len;
	return (res);
}