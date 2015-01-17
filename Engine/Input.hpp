/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:26:10 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/10 18:22:12 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INPUT_HPP
# define INPUT_HPP
# include <ncurses.h>
# include <iostream>
# define NUM_KEYCODE 262

class Input
{
	public:
		Input( void );
		Input( Input & cpy );
		~Input( void );

		Input &			operator=( Input & rhs );

		static void		update( void );
		static bool		isKeyDown( int key );

		static bool		lastKeys[NUM_KEYCODE];
};

#endif
