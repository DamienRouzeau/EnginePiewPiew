#include <SFML/Graphics.hpp>
#include <box2d/b2_body.h>
#include "BoxCollider.h"
#include "Physics.h"
#include "AComponent.h"




HorrorEngine::BoxCollider::BoxCollider(AEntity* parent) : Collider(parent)
{

}

b2Shape* HorrorEngine::BoxCollider::GetShape()
{
	_shape.SetAsBox(_height / 2, _length / 2);

	return &_shape;
}

void HorrorEngine::BoxCollider::SetHeight(float height, float length)
{
	_height = height;
	_length = length;
}
