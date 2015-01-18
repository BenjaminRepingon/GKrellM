/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesRenderEngine.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/18 15:57:08 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_RENDER_ENGINE
# define NCURSES_RENDER_ENGINE
# include <ncurses.h>
# include "IMonitorDisplay.hpp"
# include "GeometricDrawer.hpp"
# define SET_COLOR(COLOR) (attron(COLOR_PAIR(COLOR)))
# define COLOR_GRAY (COLOR_WHITE + 1)
# define COLOR_HIGH_YELLOW (COLOR_WHITE + 2)
# define COLOR_1 (COLOR_WHITE + 3)
# define COLOR_2 (COLOR_WHITE + 4)

class NcursesRenderEngine : public IMonitorDisplay
{
public:
	NcursesRenderEngine( void );
	NcursesRenderEngine( NcursesRenderEngine const & src );
	virtual ~NcursesRenderEngine( void );

	NcursesRenderEngine &	operator=( NcursesRenderEngine const & rhs );

	virtual int				getWidth() const;
	virtual int				getHeight() const;
	int						getMode( void );
	void					setMode( int mode );

	virtual void			init( void );
	WINDOW &				getWindow() const;
	void					destroy();

private:
	int						_width;
	int						_height;
	WINDOW *				_window;
	int						_mode;
};

#endif
