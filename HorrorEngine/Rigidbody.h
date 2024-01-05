#pragma once
#include <box2d/box2d.h>
#include "AComponent.h"
namespace HorrorEngine
{
	class Rigidbody : public AComponent
	{
	protected:
		b2BodyDef _bodyDef;
		b2Body* _body;
	public:
		Rigidbody(AEntity* entity);
		// Setters
		void SetBodyType(b2BodyType bodyType);
		void SetPosition(b2Vec2 position, float angle);
		void SetLinearVelocity(b2Vec2 velocity);
		void SetAngularVelocity(float w);
		 
		// Getters
		b2Vec2 GetPosition();
		float GetAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();

	};
}

