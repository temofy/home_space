/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:42:57 by cheller           #+#    #+#             */
/*   Updated: 2019/06/29 19:43:18 by cheller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int 	main()
{
	if (reading_map() == -1)
		write(2, "Error\n", 6);
	else
		write(1, "OK\n", 3);
	return (0);
}