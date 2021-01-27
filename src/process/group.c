/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 05:20:26 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 09:23:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_process	*ft_regexp_process_group(t_regexp_group *group, t_process *process)
{
	printf("\ft_regexp_process_group\n%zu\n%s\n", group->index, process->string + process->start);
	return (ft_regexp_process_element(group->elem, process));
}
