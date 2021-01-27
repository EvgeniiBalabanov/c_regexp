/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:12:46 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 08:21:51 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_set_char(t_regexp_set_chars *set_char)
{
	ft_putstr_fd("set_chars(", 1);
	ft_putstr_fd(set_char->chars, 1);
	ft_putstr_fd(")", 1);
}
