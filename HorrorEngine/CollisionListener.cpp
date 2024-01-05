#include <iostream>
#include "CollisionListener.h"

HorrorEngine::CollisionListener::CollisionListener()
{

}

void HorrorEngine::CollisionListener::BeginContact(b2Contact* contact)
{
	
	contact->GetFixtureA()->GetBody()->SetLinearVelocity(b2Vec2(-contact->GetFixtureA()->GetBody()->GetLinearVelocity().x, contact->GetFixtureA()->GetBody()->GetLinearVelocity().y));
	contact->GetFixtureB()->GetBody()->SetLinearVelocity(b2Vec2(-contact->GetFixtureB()->GetBody()->GetLinearVelocity().x, contact->GetFixtureB()->GetBody()->GetLinearVelocity().y));
}

void HorrorEngine::CollisionListener::EndContact(b2Contact* contact)
{

}
