#pragma once

namespace HorrorEngine
{
	class ICollisationnable
	{
	protected:

	public:
		virtual void BeginCollision() = 0;
		virtual void EndCollision() = 0;

	};

}