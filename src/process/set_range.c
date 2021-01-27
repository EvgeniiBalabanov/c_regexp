/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:41:02 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:49:31 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_set_range(t_regexp_set_range *set_range,\
										t_process *process)
{
	// printf("\nft_regexp_process_set_range \n%s\n", process->string + process->start);
	if (process->start != process->stop &&\
		set_range->from <= process->string[process->start] &&\
		process->string[process->start] <= set_range->to)
	{
		process->start++;
		return (process);
	}
	return (0);
}
