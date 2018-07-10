/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial_my.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:19:33 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/23 19:13:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial_my(int nb)
{
	int fac;

	fac = nb;
	if (fac > 12 || fac < 0)
		return (0);
	if (nb >= 0 && nb <= 1)
		return (1);
	nb = nb * ft_recursive_factorial_my(nb - 1);
	return (nb);
}
