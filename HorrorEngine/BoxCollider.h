#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "Collider.h"
#include "AEntity.h"


namespace HorrorEngine
{

	class BoxCollider : public Collider
	{
	protected:
		b2PolygonShape _shape;
		float _height;
		float _length;

	public:
		BoxCollider(AEntity* entity);
		virtual b2Shape* GetShape();
		void SetHeight(float height, float length);

	};
}

