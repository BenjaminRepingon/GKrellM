/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleObject.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:30:07 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 16:51:46 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULEOBJECT
# define MODULEOBJECT
# include "../Engine/ProgramObject.hpp"
# include "IMonitorModule.hpp"

class ModuleObject : public ProgramObject, public IMonitorModule
{
	public:
		ModuleObject( std::string const & title );
		ModuleObject( ModuleObject const & src );
		virtual ~ModuleObject( void );

		ModuleObject &			operator=( ModuleObject const & rhs );
		virtual std::string const &		getTitle( void ) const;


		virtual void	update( float delta );

	private:
		ModuleObject( void );
		std::string const		_title;
};

#endif
