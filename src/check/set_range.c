/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:35:42 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 06:38:53 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_set_range(t_regexp_set_range *set_range)
{
	ft_putstr_fd("set_range(from \'", 1);
	ft_putchar_fd(set_range->from, 1);
	ft_putstr_fd("\' to  \'", 1);
	ft_putchar_fd(set_range->to, 1);
	ft_putstr_fd("\')", 1);
}
