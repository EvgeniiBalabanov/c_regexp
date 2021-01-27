/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:34:03 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:04:10 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_set(t_regexp_set *set)
{
	if (set)
	{
		ft_regexp_delete_element(set->set_сhars);
		ft_lstclear(&set->l_set_range, (void (*)(void *))ft_regexp_delete_element);
		free(set);
	}
}
