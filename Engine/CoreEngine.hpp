/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 10:59:59 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 19:53:55 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE
# define CORE_ENGINE
# include <iostream>
# include <unistd.h>
# include "Program.hpp"
# include "RenderEngine.hpp"

class CoreEngine
{
public:
	CoreEngine( void );
	CoreEngine( CoreEngine const & src );
	CoreEngine( double framerate, Program & program );
	virtual ~CoreEngine( void );

	CoreEngine &	operator=( CoreEngine const & rhs );

	double			getFramerate() const;
	Program &		getProgram() const;
	bool			isRunning() const;
	RenderEngine &	getRenderEngine() const;

	bool			start();
	bool			stop();
	bool			createWindow();
	static unsigned	getTime();

private:
	int				run();

	double			_framerate;
	Program *		_program;
	bool			_isRunning;
	RenderEngine *	_renderEngine;
};

#endif
