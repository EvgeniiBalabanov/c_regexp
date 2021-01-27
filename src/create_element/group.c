/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:50:08 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 15:33:42 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_group;
	element->check = ft_regexp_check_group;
	element->process = ft_regexp_process_group;
}

t_regexp_elem	*ft_regexp_create_group(t_regexp_elem *elem, size_t index_group)
{
	t_regexp_group	*group;
	t_regexp_elem	*element;

	group = (t_regexp_group *)ft_calloc(1, sizeof(t_regexp_group));
	if (!group)
	{
		ft_regexp_delete_element(elem);
		return (0);
	}
	group->elem = elem;
	group->index = index_group;
	element = ft_regexp_create_element("group", group);
	if (!element)
		ft_regexp_delete_group(group);
	else
		ft_init_metods(element);
	return (element);
}
