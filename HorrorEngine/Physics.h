#pragma once
#include <box2d/box2d.h>
#include "CollisionListener.h"
namespace HorrorEngine
{
	class Physics
	{
	protected:
		b2Vec2 _gravity;
		CollisionListener _colListener;
	public:
		b2World _world;

		const static float worldScale;
		Physics();
		void Update(float deltaTime);
	};
}

