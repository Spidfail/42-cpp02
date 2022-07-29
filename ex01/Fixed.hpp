/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:21:01 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/18 14:27:04 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed {

	public:
		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed( void );
		Fixed	&operator=( Fixed const &target );

		Fixed( const int i );
		Fixed( const float fl );
		int 	getRawBits(void) const;
		void	setRawBits(int const &raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		static int const	_nbFracbits;
		int					_raw_bits;
};

std::ostream &operator<<( std::ostream &stream, Fixed const &src );

#endif
