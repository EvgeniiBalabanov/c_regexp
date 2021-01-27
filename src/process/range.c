/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:30:28 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 16:32:23 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_range(t_regexp_range *range,\
										t_process *process)
{
	size_t		counter;
	size_t		start;
	t_process	*res_process;

	counter = 0;
	start = process->start;
	res_process = process;
	while (res_process && counter < range->max)
	{
		start = res_process->start;
		if ((res_process = ft_regexp_process_element(range->elem, res_process)))
		{
			process = res_process;
			counter++;
		}
	}
	if (range->min > counter)
		process = 0;
	if (process)
		process->start = start;
	return (process);
}
