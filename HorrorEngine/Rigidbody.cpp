#include <box2d/b2_body.h>
#include "Rigidbody.h"
#include "Physics.h"
#include "Application.h"



HorrorEngine::Rigidbody::Rigidbody(AEntity* entity) : AComponent(entity)
{
	Application* app = Application::GetInstance();
	
	_body = app->_physics._world.CreateBody(&_bodyDef);

}

void HorrorEngine::Rigidbody::SetBodyType(b2BodyType bodyType)
{
	_body->SetType(bodyType);
}

void HorrorEngine::Rigidbody::SetPosition(b2Vec2 position, float angle)
{
	_body->SetTransform(position, angle);
}

void HorrorEngine::Rigidbody::SetLinearVelocity(b2Vec2 velocity)
{
	_body->SetLinearVelocity(velocity);
}

void HorrorEngine::Rigidbody::SetAngularVelocity(float w)
{
	_body->SetAngularVelocity(w);
}

b2Vec2 HorrorEngine::Rigidbody::GetPosition()
{
	return _body->GetPosition();
}

float HorrorEngine::Rigidbody::GetAngle()
{
	return _body->GetAngle();
}

b2Vec2 HorrorEngine::Rigidbody::GetLinearVelocity()
{
	return _body->GetLinearVelocity();
}

float HorrorEngine::Rigidbody::GetAngularVelocity()
{
	return _body->GetAngularVelocity();
}

b2Body* HorrorEngine::Rigidbody::GetBody()
{
	return _body;
}


