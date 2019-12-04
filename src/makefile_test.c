/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:51:41 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/04 21:07:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <stdio.h>

int					main(void)
{
	// ft_putstr_fd("afaf", 1); // ft_stdio.h
	printf("%zu\n", ft_strlen("hah"));
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_atoi("11"));
	test_autocom();
	test_history();
	test_terminal();
}
