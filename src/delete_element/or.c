/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:02:36 by telron            #+#    #+#             */
/*   Updated: 2020/12/09 17:02:38 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regexp.h"

void	ft_regexp_delete_or(t_regexp_or *or)
{
	if (or)
	{
		ft_regexp_delete_element(or->left);
		ft_regexp_delete_element(or->right);
		free(or);
	}
}
