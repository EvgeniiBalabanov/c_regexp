/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:07:30 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 12:46:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_regexp_elem	*ft_regexp_parse_or(t_dlist **dlist)
{
	size_t				counter;
	size_t				count_slash;
	t_regexp_elem		*elem;
	t_regexp_natural	*natural;
	t_dlist				*dlist_left, *dlist_right;

	printf("ft_regexp_parse_or pattern %p\n", *dlist);
	while (*dlist)
	{
		elem = (*dlist)->content;
		if (!ft_strcmp(elem->type, "natural"))
		{
			natural = (t_regexp_natural *)elem->content;
			counter = natural->start;
			count_slash = 0;
			while (counter < natural->stop)
			{
				if (natural->pattern[counter] == '\\')
					count_slash += 1;
				else if (natural->pattern[counter] == '|' && !(count_slash % 2))
				{
					dlist_left = ft_dlstcopy_left((*dlist)->left, (void (*)(void *))ft_regexp_delete_element);
					dlist_right = ft_dlstcopy_right((*dlist)->right, (void (*)(void *))ft_regexp_delete_element);
					if (natural->start != counter)
						ft_dlstadd_right_content(&dlist_left, ft_regexp_create_natural(natural->pattern, natural->start, counter));
					if (counter != natural->stop)
						ft_dlstadd_left_content(&dlist_right, ft_regexp_create_natural(natural->pattern, counter + 1, natural->stop));
					ft_regexp_delete_element(elem);
					ft_dlstclear(dlist, 0);
					return (ft_regexp_create_or(
						ft_regexp_parse_other(dlist_left),
						ft_regexp_parse_or(&dlist_right)));
				}
				else
					count_slash = 0;
				counter++;
			}
		}
		if (!(*dlist)->right)
			break;
		*dlist = (*dlist)->right;
	}
	*dlist = ft_dlstleft(*dlist);
	printf("*dlist %p\n", *dlist);
	return (ft_regexp_parse_other(*dlist));
}
