/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:05:01 by kmykhail          #+#    #+#             */
/*   Updated: 2017/12/17 14:23:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_binary(int nb)
{
	int i;

	i = 0;
	if (!nb)
		return (1);
	while (nb >= 2)
	{
		i++;
		nb /= 2;
	}
	i++;
	return (i);
}

int		ft_len_byte(int *nb)
{
	int i;
	int byte;
	int c;

	byte = 0;
	i = 0;
	c = 0;
	while (nb[i] != 0)
	{
		c = len_binary(nb[i++]);
		byte += (c < 8) ? 1 : 0;
		byte += (c < 12 && c >= 8) ? 2 : 0;
		byte += (c < 17 && c >= 12) ? 3 : 0;
		byte += (c >= 17) ? 4 : 0;
	}
	return (byte);
}

void	ft_utf_1(t_print *pr, t_utf *uf)
{
	if (len_binary(pr->utf) < 17)
	{
		uf->add3 = (uf->cp_utf << 26) >> 26;
		uf->add2 = ((uf->cp_utf >> 6) << 26) >> 26;
		uf->add1 = ((uf->cp_utf >> 12) << 28) >> 28;
		uf->uf_mass[0] = (uf->mask2 >> 16) | uf->add1;
		uf->uf_mass[1] = ((uf->mask2 << 16) >> 24) | uf->add2;
		uf->uf_mass[2] = ((uf->mask2 << 24) >> 24) | uf->add3;
		pr->byte_add += 3;
	}
	else
	{
		uf->add4 = (uf->cp_utf << 26) >> 26;
		uf->add3 = ((uf->cp_utf >> 6) << 26) >> 26;
		uf->add2 = ((uf->cp_utf >> 12) << 26) >> 26;
		uf->add1 = ((uf->cp_utf >> 18) << 29) >> 29;
		uf->uf_mass[0] = (uf->mask3 >> 24) | 01;
		uf->uf_mass[1] = ((uf->mask3 << 8) >> 24) | uf->add2;
		uf->uf_mass[2] = ((uf->mask3 << 16) > 24) | uf->add3;
		uf->uf_mass[3] = ((uf->mask3 << 24) >> 24) | uf->add4;
		pr->byte_add += 4;
	}
}

int		ft_utf(t_print *pr, t_utf *uf)
{
	int i;

	i = 0;
	uf->mask1 = 49280;
	uf->mask2 = 14712960;
	uf->mask3 = 4034953344;
	uf->cp_utf = pr->utf;
	while (i < 4)
		uf->uf_mass[i++] = '\0';
	if (len_binary(pr->utf) < 8)
	{
		uf->uf_mass[0] = pr->utf;
		pr->byte_add += 1;
	}
	else if (len_binary(pr->utf) < 12)
	{
		uf->add2 = (uf->cp_utf << 26) >> 26;
		uf->add1 = ((uf->cp_utf >> 6) << 27) >> 27;
		uf->uf_mass[0] = (uf->mask1 >> 8) | uf->add1;
		uf->uf_mass[1] = ((uf->mask1 << 24) >> 24) | uf->add2;
		pr->byte_add += 2;
	}
	else
		ft_utf_1(pr, uf);
	return (0);
}
