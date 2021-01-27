/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:08:46 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:15:12 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_set_char(t_regexp_set_chars *set_char,\
										t_process *process)
{
	if (process->start != process->stop &&\
		ft_strchr(set_char->chars, process->string[process->start]))
	{
		process->start++;
		return (process);
	}
	return (0);
}