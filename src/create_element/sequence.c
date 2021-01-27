/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:15:43 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 07:15:40 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

static void		ft_init_metods(t_regexp_elem *element)
{
	element->destructor = ft_regexp_delete_sequence;
	element->check = ft_regexp_check_sequence;
	element->process = ft_regexp_process_sequence;
}

t_regexp_elem	*ft_regexp_create_sequence(t_dlist *l_elems)
{
	t_regexp_sequence	*sequence;
	t_regexp_elem		*element;
	size_t				count;

	count = ft_dlstsize(l_elems);
	if (count == 0)
		return (ft_regexp_create_void());
	if (count == 1)
	{
		ft_dlstdelone(l_elems, 0);
		return (l_elems->content);
	}
	sequence = (t_regexp_sequence *)ft_calloc(1, sizeof(t_regexp_sequence));
	if (!sequence)
	{
		ft_dlstclear(&l_elems, (void (*)(void *))ft_regexp_delete_element);
		return (0);
	}
	sequence->l_elems = l_elems;
	element = ft_regexp_create_element("sequence", sequence);
	if (!element)
		ft_regexp_delete_sequence(sequence);
	else
		ft_init_metods(element);
	return (element);
}
