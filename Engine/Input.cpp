/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:26:24 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/10 19:10:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

bool Input::lastKeys[NUM_KEYCODE] = {false};

/*
** CONSTRUCT & DESTRUCT
*/

Input::Input( void )
{
	return ;
}

Input::Input( Input & cpy )
{
	*this = cpy;

	return ;
}

Input::~Input( void )
{
	return ;
}

/*
** OPERATOR
*/

Input &		Input::operator=( Input & )
{
	return ( *this );
}

/*
** METHOD
*/

void		Input::update( void )
{
	int		current_key = getch();
	int		i = 0;

	while ( i < NUM_KEYCODE )
		Input::lastKeys[i++] = false;

	if ( current_key < NUM_KEYCODE && current_key >= 0 )
		Input::lastKeys[current_key] = true;

	while ( ( current_key = getch() ) != ERR )
	{
		if ( current_key < NUM_KEYCODE && current_key >= 0 )
			Input::lastKeys[current_key] = true;
	}

	return ;
}

bool		Input::isKeyDown( int key )
{
	if ( key >= NUM_KEYCODE || key < 0 )
		return ( false );
	else
		return ( Input::lastKeys[key] );
}
