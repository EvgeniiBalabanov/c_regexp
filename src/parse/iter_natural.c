/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_natural.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:40:54 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:17:48 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

int		ft_regexp_parse_iter_natural(t_dlist **build,\
					int (*func)(t_dlist **dlist, t_regexp_natural *natural))
{
	t_dlist				*dlist;
	t_regexp_elem		*elem;

	dlist = *build;
	while (dlist)
	{
		elem = dlist->content;
		if (!ft_strcmp(elem->type, "natural") && func(&dlist, elem->content))
			return (-1);
		if (dlist->right)
			dlist = dlist->right;
		else
			break ;
	}
	*build = ft_dlstleft(dlist);
	return (0);
}