/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:17:50 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:43:07 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_set;
	element->check = ft_regexp_check_set;
	element->process = ft_regexp_process_set;
}

t_regexp_elem	*ft_regexp_create_set(t_regexp_elem *elem_set_chars,\
														t_list *l_set_range)
{
	t_regexp_set	*set;
	t_regexp_elem	*element;

	if (!l_set_range)
		return (elem_set_chars);

	set = (t_regexp_set *)ft_calloc(1, sizeof(t_regexp_set));
	if (!set)
		return (0);
	set->set_сhars = elem_set_chars;
	set->l_set_range = l_set_range;
	element = ft_regexp_create_element("set", set);
	if (!element)
	{
		ft_regexp_delete_element(elem_set_chars);
		ft_lstclear(&l_set_range, (void (*)(void *))ft_regexp_delete_set_range);
		ft_regexp_delete_set(set);
	}
	else
		ft_init_metods(element);
	return (element);
}
