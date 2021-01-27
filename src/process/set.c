/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:18:09 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 19:06:36 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

// !NOT WORK
t_process	*ft_regexp_process_set(t_regexp_set *set, t_process *process)
{
	t_list		*l_set_range;
	size_t		counter;
	t_process	*res_process;

	printf("\nft_regexp_process_set\n");
	counter = process->start;
	res_process = ft_regexp_process_element(set->set_сhars, process);
	l_set_range = set->l_set_range;
	while (!res_process && l_set_range)
	{
		printf("\nft_regexp_process_set while\n");
		process->start = counter;
		res_process = ft_regexp_process_element(l_set_range->content, process);
		l_set_range = l_set_range->next;
	}
	if (!res_process)
		process = 0;
	return (process);
}
