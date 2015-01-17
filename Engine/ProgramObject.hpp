#ifndef PROGRAM_OBJECT
# define PROGRAM_OBJECT
# include <vector>
# include <algorithm>
# include "Vector2f.hpp"
# include "ProgramComponent.hpp"
# include "NcursesRenderEngine.hpp"

class CoreEngine;

class ProgramObject
{
public:
	ProgramObject( void );
	ProgramObject( ProgramObject const & src );
	virtual ~ProgramObject( void );

	ProgramObject &					operator=( ProgramObject const & rhs );

	Vector2f &						getPos() const;

	virtual void					addChild( ProgramObject & child );
	virtual void					removeChild( ProgramObject & child );
	virtual void					addComponent( ProgramComponent & component );
	virtual void					ncursesRenderAll( NcursesRenderEngine & renderEngine );
	virtual void					ncursesRender( NcursesRenderEngine & renderEngine );
//	virtual void					renderAll( RenderEngine & renderEngine );
//	virtual void					render( RenderEngine & renderEngine );
	virtual void					inputAll( float delta );
	virtual void					input( float delta );
	virtual void					updateAll( float delta );
	virtual void					update( float delta );
	virtual void					init( CoreEngine & coreEngine );

	std::vector<ProgramObject *>	getChildrens( void ) const;
	std::vector<ProgramComponent *>	getComponents( void ) const;
	CoreEngine &					getCoreEngine() const;
	ProgramObject &					getParent( void ) const;
	void							setPos( Vector2f & value );
	void							setCoreEngine( CoreEngine & engine );

protected:
	Vector2f *						_pos;
	std::vector<ProgramObject *>	_childrens;
	std::vector<ProgramComponent *>	_components;
	CoreEngine *					_coreEngine;

private:
	ProgramObject *					_parent;
};

#endif
