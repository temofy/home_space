/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheller <cheller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:02:30 by cheller           #+#    #+#             */
/*   Updated: 2019/04/24 16:07:32 by cheller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

float	ft_pow(double number, double exp)
{
	double	result;

	result = number;
	while (exp > 1)
	{
		 result *= number;
		 exp--;
	}
	return (result);
}

int     main()
{
	printf("ft_pow: %f\n", ft_pow(5, -3));
	printf("pow: %f\n", pow(2, -3));
    return (1);
}