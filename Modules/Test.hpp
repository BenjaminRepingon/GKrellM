#ifndef TEST
# define TEST
# include "../Engine/ProgramObject.hpp"

class Test : public ProgramObject
{
public:
	Test( void );
	Test( Test const & src );
	virtual ~Test( void );

	Test &			operator=( Test const & rhs );

	virtual void	update( float delta );

private:
};

#endif
