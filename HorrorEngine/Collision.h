#pragma once
#include "Rigidbody.h"


namespace HorrorEngine
{
	class Collision
	{
	protected:
		Rigidbody* myRigidbody;
		Rigidbody* otherRigidbody;
	
	public:

		Collision();
		void SetMyRigidbody(Rigidbody* myrb);
		void SetOtherRigidbody(Rigidbody* otherrb);

		Rigidbody* GetMyRigidbody();
		Rigidbody* GetOtherRigidbody();


	};

}