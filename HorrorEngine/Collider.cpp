#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Collider.h"


HorrorEngine::Collider::Collider(AEntity* entity) : AComponent(entity)
{

}

void HorrorEngine::Collider::CreateFixture(b2Body* body)
{
	_fixtureDef.shape = GetShape();
	_fixture = body->CreateFixture(&_fixtureDef);
}

void HorrorEngine::Collider::SetDensity(float density)
{
	_fixtureDef.density = density;
	if (_fixture)
	{
		_fixture->SetDensity(density);
	}
}

void HorrorEngine::Collider::SetFriction(float friction)
{
	_fixtureDef.friction = friction;
	if (_fixture)
	{
		_fixture->SetFriction(friction);
	}
}



