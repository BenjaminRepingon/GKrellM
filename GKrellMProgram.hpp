#ifndef GKRELLM_PROGRAM
# define GKRELLM_PROGRAM
# include "Engine/Program.hpp"

class GKrellMProgram : public Program
{
public:
	GKrellMProgram( void );
	GKrellMProgram( GKrellMProgram const & src );
	virtual ~GKrellMProgram( void );

	virtual bool	init( void );

	GKrellMProgram &			operator=( GKrellMProgram const & rhs );

};

#endif
