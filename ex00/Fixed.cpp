/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:35:20 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/17 22:30:35 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_nb_fracbits = 8;

Fixed::Fixed( void ) {

	std::cout << "- Rock -         Default constructor Called." << std::endl;

	_raw_bits = 0;
}

Fixed::Fixed( Fixed const &src ) {

	std::cout << "- Metal -        Copy constructor Called." << std::endl;

	*this = src;
}


int 	Fixed::getRawBits( void ) const {

	std::cout << "- IronMaider -   GetRawBits member function called." << std::endl;

	return this->_raw_bits;
}

void	Fixed::setRawBits( int const &raw ) {

	std::cout << "- ACDC -         SetRawBits member function called." << std::endl;

	this->_raw_bits = raw;
}

Fixed	&Fixed::operator=( Fixed const &target ) {

	std::cout << "- Guitar hero -  Assignation operator called." << std::endl;

	this->_raw_bits = target.getRawBits();
	return *this;
}


Fixed::~Fixed( void ) {
	std::cout << "- Broken string - Destructor called" << std::endl;
}
