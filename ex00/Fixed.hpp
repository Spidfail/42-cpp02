/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:21:01 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/17 20:26:04 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:
		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed( void );
		Fixed	&operator=( Fixed const &target );

		int 	getRawBits(void) const;
		void	setRawBits(int const &raw);

	private:
		int					_raw_bits;
		static int const	_nb_fracbits;
};

#endif
