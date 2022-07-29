/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:21:01 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/22 20:04:29 by guhernan         ###   ########.fr       */
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

		static Fixed	&min( Fixed &t1, Fixed &t2);
		static Fixed	const &min( Fixed const &t1, Fixed const &t2);
		static Fixed	&max( Fixed &t1, Fixed &t2);
		static Fixed	const &max( Fixed const &t1, Fixed const &t2);

		bool	operator==( Fixed const &right ) const;
		bool	operator!=( Fixed const &right ) const;
		bool	operator<=( Fixed const &right ) const;
		bool	operator>=( Fixed const &right ) const;
		bool	operator<( Fixed const &right ) const;
		bool	operator>( Fixed const &right ) const;

		Fixed	operator+( Fixed const &right ) const;
		Fixed	operator-( Fixed const &right ) const;
		Fixed	operator*( Fixed const &right ) const;
		Fixed	operator/( Fixed const &right ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

	private:
		static int const	_nbFracbits;
		int					_raw_bits;
};

std::ostream	&operator<<( std::ostream &stream, Fixed const &src );

#endif //////////////////////////////////////////////////////////////////
