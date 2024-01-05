#include <box2d/b2_body.h>

#include "Physics.h"
#include "Rigidbody.h"
#include "Application.h"
#include "CollisionListener.h"



HorrorEngine::Physics::Physics() : _gravity(b2Vec2(0,0)), _world(_gravity) //gravité terrestre 9.8
{
	_world.SetContactListener(&_colListener);
}

void HorrorEngine::Physics::Update(float deltaTime)
{

	Application* application = Application::GetInstance();

	for (auto value : application->componentsList)
	{
		Rigidbody* check = dynamic_cast<Rigidbody*>(value.second);
		if (check != nullptr)
		{
			int entityId = application->_linkBetweenComponentAndEntity[value.first];
			AEntity* entity = application->entitiesList[entityId];
			sf::Vector2f pos = entity->transform.getPosition();
			check->SetPosition(b2Vec2(pos.x, pos.y), entity->transform.getRotation());
			
		}
	}
	_world.Step(deltaTime, 6,3);

	for (auto value : application->componentsList)
	{
		Rigidbody* check = dynamic_cast<Rigidbody*>(value.second);

		if (check != nullptr)
		{
			b2Body* body = check->GetBody();
			int entityId = application->_linkBetweenComponentAndEntity[value.first];
			AEntity* entity = application->entitiesList[entityId];
			entity->transform.setPosition(body->GetPosition().x, body->GetPosition().y);
			entity->transform.setRotation(body->GetAngle());
		}
	}
}
