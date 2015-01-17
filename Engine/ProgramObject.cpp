# include "ProgramObject.hpp"

ProgramObject::ProgramObject() :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 ),
	_coreEngine( 0 )
{
	return ;
}

ProgramObject::ProgramObject( ProgramObject const & src ) :
	_pos( new Vector2f( 0, 0 ) ),
	_nbChildrens( 0 ),
	_nbComponents( 0 ),
	_coreEngine( 0 )
{
	*this = src;
	return ;
}

ProgramObject::~ProgramObject()
{
	return ;
}

ProgramObject &	ProgramObject::operator=( ProgramObject const & rhs )
{
	if ( this != &rhs )
	{
		this->_pos = &rhs.getPos();
		this->_nbChildrens = rhs.getNbChildrens();
		this->_nbComponents = rhs.getNbComponents();
		this->_coreEngine = &rhs.getCoreEngine();
	}
	return ( *this );
}

void			ProgramObject::addChild( ProgramObject & child )
{
	this->_childrens.push_back( &child );
}

void			ProgramObject::removeChild( ProgramObject & child )
{
	std::vector<ProgramObject *>::iterator it;
	it = std::find( this->_childrens.begin(), this->_childrens.end(), &child );
	this->_childrens.erase( it );
}

void			ProgramObject::addComponent( ProgramComponent & component )
{
	this->_components[this->_nbComponents] = &component;
	this->_components[this->_nbComponents]->setParent( *this );
	this->_nbComponents++;
}

void			ProgramObject::init( CoreEngine & coreEngine )
{
	(void)coreEngine;
	return ;
}

void 			ProgramObject::renderAll( RenderEngine & renderEngine )
{
	render( renderEngine );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->renderAll( renderEngine );
}

void			ProgramObject::render( RenderEngine & renderEngine )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
		this->_components[i]->render( renderEngine );
}

void 			ProgramObject::inputAll( float delta )
{
	input( delta );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->inputAll( delta );
}

void			ProgramObject::input( float delta )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
		this->_components[i]->input( delta );
}

void 			ProgramObject::updateAll( float delta )
{
	update( delta );

	for ( int i = 0; i < this->_nbChildrens; i++ )
		this->_childrens[i]->updateAll( delta );
}

void			ProgramObject::update( float delta )
{
	for ( int i = 0; i < this->_nbComponents; i++ )
		this->_components[i]->update( delta );
}

void			ProgramObject::setCoreEngine( CoreEngine & engine )
{
	if ( this->_coreEngine != &engine )
	{
		this->_coreEngine = &engine;
		for ( int i = 0; i < this->_nbChildrens; i++ )
			this->_childrens[i]->setCoreEngine( engine );
	}
}

void				ProgramObject::setPos( Vector2f & value )
{
	this->_pos = &value;

	return ;
}

Vector2f &			ProgramObject::getPos() const
{
	return ( *this->_pos );
}

ProgramObject &		ProgramObject::getParent() const
{
	return ( *this->_parent );
}

int					ProgramObject::getNbChildrens() const
{
	return ( this->_childrens.size() );
}

int					ProgramObject::getNbComponents() const
{
	return ( this->_nbComponents );
}

CoreEngine &		ProgramObject::getCoreEngine() const
{
	return ( *this->_coreEngine );
}
