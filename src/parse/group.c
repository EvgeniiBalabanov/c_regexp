/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:05:14 by telron            #+#    #+#             */
/*   Updated: 2020/12/14 15:37:56 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_parse_group(t_regexp_elem *elem, size_t *index_group)
{
	int					counter_scope;
	size_t				counter;
	t_dlist				*dlist;
	t_regexp_natural	*base;

	base = (t_regexp_natural *)(elem->content);
	dlist = 0;
	counter = base->start;
	counter_scope = 0;
	while (counter < base->stop)
	{
		if (base->pattern[counter] == '(')
		{
			if (!counter_scope && base->start != counter)
			{
				ft_dlstadd_right_content(&dlist, ft_regexp_create_natural(base->pattern, base->start, counter));
				base->start = counter;
			}
			counter_scope += 1;
		}
		else if (base->pattern[counter] == ')' && base->start != counter)
		{
			counter_scope -= 1;
			if (!counter_scope)
			{
				ft_dlstadd_right_content(&dlist,\
					ft_regexp_create_group(\
						ft_regexp_parse_group(\
							ft_regexp_create_natural(base->pattern, base->start + 1, counter),\
							index_group),\
						*index_group));
				(*index_group)++;
				base->start = counter + 1;
			}
			else if (counter_scope < 0)
			{
				ft_putstr_fd("Warning! Bad scope \")\"", 2);
				counter_scope += 1;
			}
		}
		counter++;
	}
	if (base->start != base->stop)
	{
		ft_dlstadd_right_content(&dlist, ft_regexp_create_natural(base->pattern, base->start, base->stop));
	}
	ft_regexp_delete_element(elem);
	return (ft_regexp_parse_or(&dlist));
}
