# include <iostream>
# include "Test.hpp"

Test::Test() : ProgramObject()
{
	return ;
}

Test::Test( Test const & src ) : ProgramObject( src )
{
	*this = src;
	return ;
}

Test::~Test()
{
	return ;
}

Test &	Test::operator=( Test const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void	Test::update( float delta )
{
	std::cout << "poky" << std::endl;
	ProgramObject::update( delta );
}