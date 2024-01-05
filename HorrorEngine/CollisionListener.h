#pragma once
#include<box2d/box2d.h>
namespace HorrorEngine
{
	class CollisionListener : public b2ContactListener
	{
	public:
		CollisionListener();
		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);
	};

}