/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:22:56 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/18 15:46:33 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const c(42.42f);
	Fixed const b(10);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as an integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as an integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as an integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as an integer" << std::endl;

	return 0 ;
}
