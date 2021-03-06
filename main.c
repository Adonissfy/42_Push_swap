/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 10:18:02 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/27 10:18:02 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_fmain(t_main *main, int a)
{
	free(main->number);
	if (a == 11 || a == 1)
		free(main->str);
	if (a == 1 || a == 2)
		free(main->sorted_tab);
	main->size = 0;
	while (main->strr[main->size])
		free(main->strr[main->size++]);
	free(main->strr);
	return (0);
}

int	ft_main_min(int argc, char *argv[], t_main *main, t_data *data)
{
	data->size_a = -1;
	main->size = 0;
	if (argc == 2 && ft_strlen(argv[1]) && ft_check_one_arg(argv[1]) != 0)
	{
		main->strr = ft_split(argv[1], ' ');
		main->a++;
	}
	else if (argc > 2 && ft_check_mult_arg(argv, argc) == 1)
	{
		main->str = ft_argc_to_tab(argv, argc);
		main->strr = ft_split(main->str, ' ');
	}
	else
		return (1);
	return (0);
}

void	ft_sort_main(t_main *main, t_data *data)
{
	main->sorted_tab = ft_sort_tab(main->number, main->size);
	data->max = main->sorted_tab[main->size - 1];
	ft_swap_radix(data, main->sorted_tab, main->size, main->number);
	free(main->number);
	main->number = ft_update(data, main->size);
	while (ft_is_sorted(main->number, main->size) == 0)
	{
		ft_swap_radix(data, main->sorted_tab, main->size, main->number);
		main->number = ft_update(data, main->size);
	}
}

void	ft_main(int argc, char *argv[], t_main *main, t_data *data)
{
	if (ft_main_min(argc, argv, main, data))
		ft_usage();
	main->number = ft_splittochar(main->strr, &main->size);
	if (ft_check_double(main->number, main->size) == 0)
	{
		main->a = main->a + 10;
		ft_printf("\033[2K\r\033[0;31mError\033[0m : double numbers\n");
		ft_fmain(main, main->a);
		return ;
	}
	else if (ft_first_sort(main->strr) == 1)
	{
		main->a = main->a + 10;
		ft_fmain(main, main->a);
		return ;
	}
	if (main->size <= 5)
		ft_sort(main, data);
	else
		ft_sort_main(main, data);
	ft_pb_(data);
	ft_free(data, main->a);
	ft_fmain(main, main->a);
}

int	main(int argc, char *argv[])
{
	t_main		main;
	t_data		data;
	t_pile		pile_a;
	t_pile		pile_b;
	t_chunk		chunk;

	data.pile_a = &pile_a;
	data.pile_b = &pile_b;
	data.chunk = &chunk;
	main.a = 1;
	if (argc > 1)
		ft_main(argc, argv, &main, &data);
	return (0);
}
