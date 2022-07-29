/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:35:20 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/19 15:45:35 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <bitset>

int const	Fixed::_nbFracbits = 8;

/////////////////////////////////////////////////////////////////////////////////

Fixed::Fixed( void ) {

	_raw_bits = 0;
}

Fixed::Fixed( Fixed const &src ) {

	*this = src;
}

Fixed::Fixed( const int i) {

	this->_raw_bits = roundf(i * (1 << Fixed::_nbFracbits));
}

Fixed::Fixed( const float  fl ) {

	this->_raw_bits = roundf(fl * (1 << Fixed::_nbFracbits));
}

/////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<( std::ostream &stream, Fixed const &src ) {

	stream << (float)src.getRawBits() / (float)(1 << 8);
	return stream;
}

// Assignation

Fixed	&Fixed::operator=( Fixed const &target ) {

	this->_raw_bits = target.getRawBits();
	return *this;
}

// Comparison
//
bool	Fixed::operator==( Fixed const &right ) const {

	return this->_raw_bits == right._raw_bits;
}

bool	Fixed::operator!=( Fixed const &right ) const {

	return this->_raw_bits != right._raw_bits;
}

bool	Fixed::operator<=( Fixed const &right ) const {

	return this->_raw_bits <= right._raw_bits;
}

bool	Fixed::operator>=( Fixed const &right ) const {

	return this->_raw_bits >= right._raw_bits;
}

bool	Fixed::operator<( Fixed const &right ) const {

	return this->_raw_bits < right._raw_bits;
}

bool	Fixed::operator>( Fixed const &right ) const {

	return this->_raw_bits > right._raw_bits;
}

// Arithm
//
Fixed	Fixed::operator+( Fixed const &right ) const {

	Fixed	a(this->toFloat() + right.toFloat());
	return a;
}

Fixed	Fixed::operator-( Fixed const &right ) const {

	Fixed	a(this->toFloat() - right.toFloat());
	return a;
}

Fixed	Fixed::operator*( Fixed const &right ) const {

	Fixed	a(this->toFloat() * right.toFloat());
	return a;
}

Fixed	Fixed::operator/( Fixed const &right ) const {

	Fixed	a(this->toFloat() / right.toFloat());
	return a;
}

// Increment & decrement
//
Fixed	&Fixed::operator++( void ) {

	*this = *this + Fixed(1);
	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed tempF(*this);

	++(*this);
	return tempF;
}

Fixed	&Fixed::operator--( void ) {

	*this = *this - Fixed(1);
	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed tempF(*this);

	--(*this);
	return tempF;
}

/////////////////////////////////////////////////////////////////////////////////

int 	Fixed::getRawBits( void ) const {

	return this->_raw_bits;
}

void	Fixed::setRawBits( int const &raw ) {

	this->_raw_bits = raw;
}

float	Fixed::toFloat( void ) const {

	return (float)this->_raw_bits / (float)(1 << 8);
}

int		Fixed::toInt( void ) const {

	return roundf(this->_raw_bits >> this->_nbFracbits);
}

Fixed const &Fixed::min( Fixed const &t1, Fixed const &t2 ) {

	if (t1 > t2)
		return t2;
	return t1;
}

Fixed	&Fixed::min( Fixed &t1, Fixed &t2 ) {

	if (t1 > t2)
		return t2;
	return t1;
}

Fixed const &Fixed::max( Fixed const &t1, Fixed const &t2 ) {

	if (t1 < t2)
		return t2;
	return t1;
}

Fixed	&Fixed::max( Fixed &t1, Fixed &t2 ) {

	if (t1 < t2)
		return t2;
	return t1;
}


Fixed::~Fixed( void ) {

}
