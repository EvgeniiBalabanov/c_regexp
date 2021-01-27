/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 04:33:17 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 04:52:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"regexp.h"

t_process	*ft_regexp_process_or(t_regexp_or *or, t_process *process)
{
	size_t		start;
	t_process	*res_process;

	start = process->start;
	if (!(res_process = ft_regexp_process_element(or->left, process)))
	{
		process->start = start;
		res_process = ft_regexp_process_element(or->right, process);
	}
	return (res_process);
}
