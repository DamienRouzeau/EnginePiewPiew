#include "Collision.h"
#include "Rigidbody.h"

HorrorEngine::Collision::Collision()
{

}

void HorrorEngine::Collision::SetMyRigidbody(Rigidbody* myrb)
{
	myRigidbody = myrb;
}

void HorrorEngine::Collision::SetOtherRigidbody(Rigidbody* otherrb)
{
	otherRigidbody = otherrb;
}

HorrorEngine::Rigidbody* HorrorEngine::Collision::GetMyRigidbody()
{
	return myRigidbody;
}

HorrorEngine::Rigidbody* HorrorEngine::Collision::GetOtherRigidbody()
{
	return otherRigidbody;
}
