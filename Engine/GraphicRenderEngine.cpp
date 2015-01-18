/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicRenderEngine.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/18 12:35:05 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "GraphicRenderEngine.hpp"

GraphicRenderEngine::GraphicRenderEngine()
{
	return ;
}

GraphicRenderEngine::GraphicRenderEngine( GraphicRenderEngine const & src )
{
	*this = src;
	return ;
}

GraphicRenderEngine::~GraphicRenderEngine()
{
	return ;
}

GraphicRenderEngine &	GraphicRenderEngine::operator=( GraphicRenderEngine const & rhs )
{
	if ( this != &rhs )
	{
	}
	return ( *this );
}

void			GraphicRenderEngine::init()
{

}

void			GraphicRenderEngine::destroy()
{

}

void *			GraphicRenderEngine::getWindow() const
{
	return ( this->_window );
}

void *			GraphicRenderEngine::getMlx() const
{
	return ( this->_mlx );
}

int				GraphicRenderEngine::getWidth() const
{
	return ( this->_width );
}

int				GraphicRenderEngine::getHeight() const
{
	return ( this->_height );
}
