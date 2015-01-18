/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicRenderEngine.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:55:47 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/18 12:35:00 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_RENDER_ENGINE
# define GRAPHIC_RENDER_ENGINE
# include <stdio.h>
# include <string>
# include "IMonitorDisplay.hpp"

class GraphicRenderEngine : public IMonitorDisplay
{
public:
	GraphicRenderEngine( void );
	GraphicRenderEngine( GraphicRenderEngine const & src );
	virtual ~GraphicRenderEngine( void );

	GraphicRenderEngine &	operator=( GraphicRenderEngine const & rhs );

	virtual int				getWidth() const;
	virtual int				getHeight() const;

	virtual void			init( void );
	void *					getWindow() const;
	void *					getMlx() const;
	void					destroy();

private:
	int						_width;
	int						_height;
	void *					_window;
	void *					_mlx;
};

#endif
