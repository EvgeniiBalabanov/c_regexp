/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:04:36 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 09:40:18 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void		ft_regexp_check_or(t_regexp_or *or)
{
	ft_putstr_fd("or(", 1);
	ft_regexp_check_element(or->left);
	ft_putstr_fd(",", 1);
	ft_regexp_check_element(or->right);
	ft_putstr_fd(")", 1);
}
