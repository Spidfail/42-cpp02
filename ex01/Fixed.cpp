/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:35:20 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/18 15:45:34 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <bitset>

int const	Fixed::_nbFracbits = 8;

/////////////////////////////////////////////////////////////////////////////////

Fixed::Fixed( void ) {

	std::cout << "- Rock -         Default constructor Called." << std::endl;

	_raw_bits = 0;
}

Fixed::Fixed( Fixed const &src ) {

	std::cout << "- Metal -        Copy constructor Called." << std::endl;

	*this = src;
}

Fixed::Fixed( const int  i) {

	std::cout << "- Gojira band -   Int constructor called." << std::endl;

	this->_raw_bits = roundf(i * (1 << Fixed::_nbFracbits));
}

Fixed::Fixed( const float  fl ) {

	std::cout << "- Tool band -     Float constructor called." << std::endl;

	this->_raw_bits = roundf(fl * (1 << Fixed::_nbFracbits));
}

/////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<( std::ostream &stream, Fixed const &src ) {

	stream << (float)src.getRawBits() / (float)(1 << 8);

	return stream;
}


Fixed	&Fixed::operator=( Fixed const &target ) {

	std::cout << "- Guitar hero -  Assignation operator called." << std::endl;

	this->_raw_bits = target.getRawBits();
	return *this;
}

/////////////////////////////////////////////////////////////////////////////////

int 	Fixed::getRawBits( void ) const {

	return this->_raw_bits;
}

void	Fixed::setRawBits( int const &raw ) {

	this->_raw_bits = raw;
}

float	Fixed::toFloat(void) const {

	return (float)this->_raw_bits / (float)(1 << 8);
}

int		Fixed::toInt(void) const {

	return roundf(this->_raw_bits >> this->_nbFracbits);
}


Fixed::~Fixed( void ) {

	std::cout << "- Broken string - Destructor called" << std::endl;
}
