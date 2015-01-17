/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicRenderEngine.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:21:02 by rbenjami          #+#    #+#             */
/*   Updated: 2015/01/11 22:15:39 by rbenjami         ###   ########.fr       */
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

int				GraphicRenderEngine::getWidth() const
{
	return ( this->_width );
}

int				GraphicRenderEngine::getHeight() const
{
	return ( this->_height );
}
