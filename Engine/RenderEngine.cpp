/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RenderEngine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:15:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RenderEngine.hpp"

RenderEngine::RenderEngine()
{
	initscr();
	start_color();
	noecho();
	curs_set( false );
	getmaxyx( stdscr, this->_height, this->_width );
	this->_window = stdscr;
	nodelay( stdscr, true );
	keypad( stdscr, true );
	init_pair( COLOR_BLACK, COLOR_BLACK, COLOR_BLACK );
	init_pair( COLOR_RED, COLOR_RED, COLOR_BLACK );
	init_pair( COLOR_GREEN, COLOR_GREEN, COLOR_BLACK );
	init_pair( COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK );
	init_pair( COLOR_BLUE, COLOR_BLUE, COLOR_BLACK );
	init_pair( COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK );
	init_pair( COLOR_CYAN, COLOR_CYAN, COLOR_BLACK );
	init_pair( COLOR_WHITE, COLOR_WHITE, COLOR_BLACK );
	init_color( COLOR_GRAY, 500, 500, 500);
	init_pair( COLOR_GRAY, COLOR_GRAY, COLOR_BLACK );
	init_color( COLOR_HIGH_YELLOW, 800, 800, 400);
	init_pair( COLOR_HIGH_YELLOW, COLOR_GRAY, COLOR_BLACK );
	return ;
}

RenderEngine::RenderEngine( RenderEngine const & src )
{
	*this = src;
	return ;
}

RenderEngine::~RenderEngine()
{
	return ;
}

RenderEngine &	RenderEngine::operator=( RenderEngine const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

WINDOW &		RenderEngine::getWindow() const
{
	return ( *this->_window );
}

int				RenderEngine::getWidth() const
{
	return ( this->_width );
}

int				RenderEngine::getHeight() const
{
	return ( this->_height - 7 );
}
