/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:08:28 by telron            #+#    #+#             */
/*   Updated: 2020/12/10 14:14:28 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

int				ft_regexp_parse_normal(t_dlist **build, t_regexp_natural *natural)
{
	t_regexp_elem *for_free;

	for_free = (*build)->content;
	(*build)->content = ft_regexp_create_normal(natural->pattern, natural->start, natural->stop);
	ft_regexp_delete_element(for_free);
	return (0);
}

t_regexp_elem	*ft_regexp_parse_other(t_dlist *dlist)
{
	t_regexp_elem		*elem;
	ft_regexp_parse_iter_natural(&dlist, ft_regexp_parse_sd_d_sp_ss_m);
	ft_regexp_parse_iter_natural(&dlist, ft_regexp_parse_normal);
	elem = ft_regexp_create_sequence(dlist);
	return (elem);
}
