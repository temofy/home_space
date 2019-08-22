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

#include "lem_in.h"

int	validate_record_run(t_map *map)
{
	int		i;
	int		rtn;
	char	**ways;
	t_node2	*first_room;

	i = 0;
	first_room = NULL;
	ways = NULL;
	if (reading_ants(map->file[0], &(map->ants)) == -1)
		return (-1);
	map->nbrs_rooms = count_rooms(map->file, i + 1);
	while (map->file[++i] && ((ft_count_words(map->file[i]) == 3) || ft_isthere_chr(map->file[i], '#')))
	{
		if (record_rooms(map, map->file, &i, map->nbrs_rooms) == -1)
			return (-1);
	}
	handler_links(map, map->file, &i);
	if (map->file[i] != NULL || !map->start || !map->end || !map->nbrs_links)
		rtn = -1;
	else
		rtn = check_map(map, &ways, &first_room);
	if (rtn == 1)
		rtn = finding_non_intersecting_ways(map, ways, first_room);
	free_rooms(&first_room, map->nbrs_rooms + 2);
	ft_arrdel(&ways);
	return (rtn);
}

int	lem_in(void)
{
	t_map	map;
	int		i;

	i = 0;
	initialize_map(&map);
	map.file = (char**)malloc(sizeof(char*) * 15000);
	while (get_next_line(0, &(map.file[i++])))
	{
	}
	map.file[i - 1] = NULL;
	if (validate_record_run(&map) == -1)
		return (free_map(&map, -1));
	free_map(&map, 1);
	return (1);
}

int	main(void)
{
	if (lem_in() == -1)
		write(2, "Error\n", 6);
	exit(0);
}