/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:17:51 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:40:16 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_normal(t_regexp_normal *normal)
{
	ft_putstr_fd("str(", 1);
	ft_putstr_fd(normal->string, 1);
	ft_putstr_fd(")", 1);
}
