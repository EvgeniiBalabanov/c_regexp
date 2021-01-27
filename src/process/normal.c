/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:01:50 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 18:40:15 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_normal(t_regexp_normal *normal,\
										t_process *process)
{
	size_t	counter;

	counter = 0;
	while (normal->string[counter])
	{
		if (normal->string[counter] == process->string[process->start++])
			counter++;
		else
			return (0);
	}
	return (process);
}
