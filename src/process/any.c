/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:17:01 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 10:20:17 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_any(t_regexp_any *any, t_process *process)
{
	(void)any;
	if (process->start != process->stop)
	{
		process->start++;
		return (process);
	}
	return (0);
}
