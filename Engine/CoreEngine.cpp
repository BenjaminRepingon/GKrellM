/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:24 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 20:22:35 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <sstream>
# include "CoreEngine.hpp"
# include "Input.hpp"

CoreEngine::CoreEngine( double framerate, Program & game ) :
	_framerate( framerate ),
	_program( &game ),
	_isRunning( false )
{
	game.setEngine( *this );
	return ;
}

CoreEngine::CoreEngine( CoreEngine const & src )
{
	*this = src;
}

CoreEngine::~CoreEngine()
{
	return ;
}

CoreEngine &	CoreEngine::operator=( CoreEngine const & rhs )
{
	if ( this != &rhs )
	{
		this->_framerate = rhs.getFramerate();
		this->_program = &rhs.getProgram();
		this->_isRunning = rhs.isRunning();
		this->_ncursesRenderEngine = &rhs.getNcursesRenderEngine();
//		this->_ncursesRenderEngine = &rhs.getNcursesRenderEngine();
	}
	return ( *this );
}

bool			CoreEngine::createWindow( int mode )
{
	if ( ( mode & NCURSES ) == NCURSES )
		this->_ncursesRenderEngine = new NcursesRenderEngine();
	if ( ( mode & GRAPHIC ) == GRAPHIC )
		this->_graphicRenderEngine = new GraphicRenderEngine();
	return ( true );
}

bool			CoreEngine::start()
{
	if ( this->_isRunning )
		return ( false );
	this->_isRunning = true;
	this->run();
	return ( true );
}

bool			CoreEngine::stop()
{
	if ( !this->_isRunning )
		return ( false );
	this->_isRunning = false;
	return ( true );
}

int				CoreEngine::run()
{
	unsigned	startTime;
	unsigned	endTime;

	this->_program->init();
	while ( this->_isRunning )
	{
		startTime = getTime();
		if ( this->_ncursesRenderEngine )
			clear();
		Input::update();
		if ( Input::isKeyDown( 27 ) )
			this->stop();
		this->_program->input( _framerate );
		this->_program->update( _framerate );

		// GRAPHIC
		if ( this->_graphicRenderEngine )
		{
			this->_program->graphicRender( *this->_graphicRenderEngine );
		}

		// NCURSES
		if ( this->_ncursesRenderEngine )
		{
			this->_program->ncursesRender( *this->_ncursesRenderEngine );
			wrefresh( &getNcursesRenderEngine().getWindow() );
		}

		endTime = getTime();
		usleep( ( 1000000 / this->_framerate ) - ( endTime - startTime ) );
	}
	if ( this->_ncursesRenderEngine )
	{
		delwin( &getNcursesRenderEngine().getWindow() );
		endwin();
	}
	return (0);
}

/**
 * GETTER
 */
unsigned		CoreEngine::getTime()
{
	timeval curTime;
	gettimeofday(&curTime, 0);
	return ( (unsigned)curTime.tv_usec );
}

double			CoreEngine::getFramerate() const
{
	return ( this->_framerate );
}

Program &		CoreEngine::getProgram() const
{
	return ( *this->_program );
}

NcursesRenderEngine &	CoreEngine::getNcursesRenderEngine() const
{
	return ( *this->_ncursesRenderEngine );
}

GraphicRenderEngine &	CoreEngine::getGraphicRenderEngine() const
{
	return ( *this->_graphicRenderEngine );
}

bool			CoreEngine::isRunning() const
{
	return ( this->_isRunning );
}
