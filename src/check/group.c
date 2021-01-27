/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:55:30 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:40:14 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_group(t_regexp_group *group)
{
	ft_putstr_fd("group_", 1);
	ft_putnbr_fd((int)group->index, 1);
	ft_putstr_fd("(", 1);
	ft_regexp_check_element(group->elem);
	ft_putstr_fd(")", 1);
}
