# include "ProgramObject.hpp"

ProgramObject::ProgramObject() :
	_pos( Vector2f( 0, 0 ) ),
	_widthHeight( 0, 0 ),
	_childrens( 0 ),
	_components( 0 ),
	_coreEngine( 0 )
{
	return ;
}

ProgramObject::ProgramObject( Vector2f pos ) :
	_pos( pos ),
	_widthHeight( 0, 0 ),
	_childrens( 0 ),
	_components( 0 ),
	_coreEngine( 0 )
{
	return ;
}

ProgramObject::ProgramObject( Vector2f pos, Vector2f widthHeight ) :
	_pos( pos ),
	_widthHeight( widthHeight ),
	_childrens( 0 ),
	_components( 0 ),
	_coreEngine( 0 )
{
	return ;
}

ProgramObject::ProgramObject( ProgramObject const & src ) :
	_pos( Vector2f( 0, 0 ) ),
	_widthHeight( 0, 0 ),
	_childrens( 0 ),
	_components( 0 ),
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
		this->_pos = rhs.getPos();
		this->_childrens = rhs.getChildrens();
		this->_components = rhs.getComponents();
		this->_coreEngine = &rhs.getCoreEngine();
	}
	return ( *this );
}

void			ProgramObject::addChild( ProgramObject * child )
{
	child->setParent( this );
	child->setCoreEngine( *this->_coreEngine );
	this->_childrens.push_back( child );
}

void			ProgramObject::removeChild( ProgramObject * child )
{
	std::vector<ProgramObject *>::iterator it;
	it = std::find( this->_childrens.begin(), this->_childrens.end(), child );
	this->_childrens.erase( it );
}

void			ProgramObject::addComponent( ProgramComponent * component )
{
	component->setParent( *this );
	this->_components.push_back( component );
}

void			ProgramObject::init( CoreEngine & coreEngine )
{
	(void)coreEngine;
	return ;
}

void 			ProgramObject::ncursesRenderAll( NcursesRenderEngine & renderEngine )
{
	ncursesRender( renderEngine );

	for ( size_t i = 0; i < this->_childrens.size(); i++ )
		this->_childrens[i]->ncursesRenderAll( renderEngine );
}

void			ProgramObject::ncursesRender( NcursesRenderEngine & renderEngine )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->ncursesRender( renderEngine );
}

void 			ProgramObject::graphicRenderAll( GraphicRenderEngine & renderEngine )
{
	graphicRender( renderEngine );

	for ( size_t i = 0; i < this->_childrens.size(); i++ )
		this->_childrens[i]->graphicRenderAll( renderEngine );
}

void			ProgramObject::graphicRender( GraphicRenderEngine & renderEngine )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->graphicRender( renderEngine );
}

void 			ProgramObject::inputAll( float delta )
{
	input( delta );

	for ( size_t i = 0; i < this->_childrens.size(); i++ )
		this->_childrens[i]->inputAll( delta );
}

void			ProgramObject::input( float delta )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->input( delta );
}

void 			ProgramObject::updateAll( float delta )
{
	update( delta );

	for ( size_t i = 0; i < this->_childrens.size(); i++ )
		this->_childrens[i]->updateAll( delta );
}

void			ProgramObject::update( float delta )
{
	for ( size_t i = 0; i < this->_components.size(); i++ )
		this->_components[i]->update( delta );
}

void			ProgramObject::setCoreEngine( CoreEngine & engine )
{
	if ( this->_coreEngine != &engine )
	{
		this->_coreEngine = &engine;
		for ( size_t i = 0; i < this->_childrens.size(); i++ )
			this->_childrens[i]->setCoreEngine( engine );
	}
}

void				ProgramObject::setParent( ProgramObject * value )
{
	this->_parent = value;

	return ;
}

void				ProgramObject::setPos( Vector2f & value )
{
	this->_pos = value;

	return ;
}

Vector2f			ProgramObject::getPos() const
{
	return ( this->_pos );
}

ProgramObject &		ProgramObject::getParent() const
{
	return ( *this->_parent );
}

CoreEngine &		ProgramObject::getCoreEngine() const
{
	return ( *this->_coreEngine );
}

std::vector<ProgramObject *>	ProgramObject::getChildrens( void ) const
{
	return ( this->_childrens );
}

std::vector<ProgramComponent *>	ProgramObject::getComponents( void ) const
{
	return ( this->_components );
}

int						ProgramObject::getWidth( void ) const
{
	return ( static_cast<int>( this->_widthHeight.getX() ) );
}

int						ProgramObject::getHeight( void ) const
{
	return ( static_cast<int>( this->_widthHeight.getY() ) );
}
