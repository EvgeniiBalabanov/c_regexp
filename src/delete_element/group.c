/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:53:14 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:02:06 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_group(t_regexp_group *group)
{
	if (group)
	{
		ft_regexp_delete_element(group->elem);
		free(group);
	}
}
