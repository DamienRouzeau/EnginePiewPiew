#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "AComponent.h"

namespace HorrorEngine
{
	class Collider : public AComponent
	{
	protected:
		b2FixtureDef _fixtureDef;
		b2Fixture* _fixture;
	public:
		Collider(AEntity* entity);
		void CreateFixture(b2Body* body);
		virtual b2Shape* GetShape() = 0;

		// Setters
		void SetDensity(float density);
		void SetFriction(float friction);

	};
}
