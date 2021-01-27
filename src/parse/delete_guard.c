/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_guard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:58:51 by telron            #+#    #+#             */
/*   Updated: 2020/12/13 20:21:49 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

t_dlist	*ft_create_dlist(t_regexp_elem *content)
{
	t_dlist *new;

	if (!content)
		return (0);
	new = ft_dlstnew(content);
	if (!new)
		ft_regexp_delete_element(content);
	return (new);
}

int		ft_regexp_parse_insert(t_dlist **dlist, t_regexp_elem *elem,\
								size_t index_left, size_t index_right)
{
	t_regexp_natural	*natural;
	t_dlist				*dlist_left;
	t_dlist				*dlist_right;
	t_regexp_elem		*for_free;

	natural = (t_regexp_natural *)((t_regexp_elem *)(*dlist)->content)->content;
	for_free = (*dlist)->content;
	(*dlist)->content = elem;
	if (natural->start != index_left)
	{
		dlist_left = ft_create_dlist(ft_regexp_create_natural(\
							natural->pattern, natural->start, index_left));
		ft_dlstrelation((*dlist)->left, dlist_left);
		ft_dlstrelation(dlist_left, *dlist);
	}
	if (index_right != natural->stop)
	{
		dlist_right = ft_create_dlist(ft_regexp_create_natural(\
							natural->pattern, index_right, natural->stop));
		ft_dlstrelation(dlist_right, (*dlist)->right);
		ft_dlstrelation(*dlist, dlist_right);
	}
	ft_regexp_delete_element(for_free);
	return (0);
}

int		ft_regexp_parse_m_p(t_dlist **build,\
							t_regexp_elem *(*func)(t_regexp_elem *),\
							size_t index_left, size_t index_right)
{
	t_regexp_natural	*natural;

	natural = (t_regexp_natural *)((t_regexp_elem *)(*build)->content)->content;
	if (natural->start != index_left - 1)
		return (ft_regexp_parse_insert(build, func(ft_regexp_create_normal(\
				natural->pattern, index_left - 1, index_left)),\
				index_left - 1, index_right));
	if ((*build)->left)
	{
		(*build)->left->content = func((*build)->left->content);
		natural->start = index_left;
		return (0);
	}
	return (-1);
}

int		ft_regexp_parse_sd_d_sp_ss_m(t_dlist **build, t_regexp_natural *natural)
{
	size_t			counter;

	counter = natural->start;
	while (counter < natural->stop)
	{
		if (natural->pattern[counter] == '\\' && counter + 1 < natural->stop)
		{
			if (natural->pattern[counter + 1] == 'd')
				return (ft_regexp_parse_insert(build, ft_regexp_create_set_range_digit(), counter, counter + 2));
			else if (natural->pattern[counter + 1] == 'w')
				return (ft_regexp_parse_insert(build, ft_regexp_create_set_w(), counter, counter + 2));
			else if (ft_strchr("*+.\\", natural->pattern[counter + 1]))
				return (ft_regexp_parse_insert(build, ft_regexp_create_normal(natural->pattern, counter + 1, counter + 2), counter, counter + 2));
		}
		else if (natural->pattern[counter] == '.')
			return (ft_regexp_parse_insert(build, ft_regexp_create_any(), counter, counter + 1));
		else if (natural->pattern[counter] == '+')
		{
			(*build)->left->content = ft_regexp_create_one_or_more((*build)->left->content);
			natural->start = counter + 1;
		}
		else if (natural->pattern[counter] == '*')
		{
			(*build)->left->content = ft_regexp_create_zero_or_more((*build)->left->content);
			natural->start = counter + 1;
		}
		if (counter + 1 < natural->stop)
		{
			if (natural->pattern[counter + 1] == '+')
				return (ft_regexp_parse_insert(build, ft_regexp_create_one_or_more(ft_regexp_create_normal(natural->pattern, counter, counter + 1)), counter, counter + 2));
			else if (natural->pattern[counter + 1] == '*')
				return (ft_regexp_parse_insert(build, ft_regexp_create_zero_or_more(ft_regexp_create_normal(natural->pattern, counter, counter + 1)), counter, counter + 2));
		}
		counter++;
	}
	return (0);
}
