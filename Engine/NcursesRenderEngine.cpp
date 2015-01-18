/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesRenderEngine.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/18 15:58:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "NcursesRenderEngine.hpp"

NcursesRenderEngine::NcursesRenderEngine()
{
	return ;
}

NcursesRenderEngine::NcursesRenderEngine( NcursesRenderEngine const & src )
{
	*this = src;
	return ;
}

NcursesRenderEngine::~NcursesRenderEngine()
{
	return ;
}

NcursesRenderEngine &	NcursesRenderEngine::operator=( NcursesRenderEngine const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

void			NcursesRenderEngine::init( void )
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

	init_pair( COLOR_1, COLOR_CYAN, COLOR_BLACK );
	init_pair( COLOR_2, COLOR_WHITE, COLOR_BLACK );
}

void			NcursesRenderEngine::destroy()
{
	delwin( this->_window );
	endwin();
}

WINDOW &		NcursesRenderEngine::getWindow() const
{
	return ( *this->_window );
}

int				NcursesRenderEngine::getWidth() const
{
	return ( this->_width );
}

int				NcursesRenderEngine::getHeight() const
{
	return ( this->_height );
}

int				NcursesRenderEngine::getMode( void )
{
	return this->_mode;
}

void			NcursesRenderEngine::setMode( int mode )
{
	this->_mode = mode;
	return ;
}

