#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.h"
#include "AEntity.h"
#include "AComponent.h"


int HorrorEngine::Application::_entityID = 0;
HorrorEngine::Application* HorrorEngine::Application::_instance = nullptr;

HorrorEngine::Application::Application()
{
	std::cout << "App Created" << std::endl;
	if (_instance == nullptr)
	{
		_instance = this;
	}
}

HorrorEngine::Application::~Application()
{
	std::cout << "App Destroyed" << std::endl;
}

void HorrorEngine::Application::Init(int windowSizeX, int windowSizeY, std::string windowName)
{

	_window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
	std::cout << "Window Created" << std::endl;
}

void HorrorEngine::Application::Loop()
{
	{
		sf::Clock clock;

		AEntity* joueur1 = entitiesList[1];
		AEntity* joueur2 = entitiesList[5]; // c'est normal t'inquiète... c'est fait exprès o_o
		AEntity* balle = entitiesList[9]; // ça aussi...
		/*Rigidbody* rbBalle;

		for (auto value : balle->componentsList)
		{
			Rigidbody* check = dynamic_cast<Rigidbody*>(value.second);

			if (check != nullptr)
			{
				rbBalle = check;

			}
		}*/

		for (auto value : entitiesList)
		{
			std::cout << "ID = " << value.first << " with the name : " << value.second << std::endl;
		}

		while (_window.isOpen())
		{

			float deltaTime = clock.getElapsedTime().asSeconds();
			sf::Event event;

			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
			}


			// Player 1

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				if (joueur1->transform.getPosition().y < 910)
				{
					joueur1->transform.setPosition(joueur1->transform.getPosition().x, joueur1->transform.getPosition().y + 0.5f);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				if (joueur1->transform.getPosition().y > 0)
				{
					joueur1->transform.setPosition(joueur1->transform.getPosition().x, joueur1->transform.getPosition().y - 0.5f);
				}
			}



			
			// Player 2
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (joueur2->transform.getPosition().y < 910)
				{
					joueur2->transform.setPosition(joueur2->transform.getPosition().x, joueur2->transform.getPosition().y + 0.5f);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (joueur2->transform.getPosition().y > 0)
				{
					joueur2->transform.setPosition(joueur2->transform.getPosition().x, joueur2->transform.getPosition().y - 0.5f);
				}
			}
			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				rbBalle->SetLinearVelocity(b2Vec2(2, 3));
			}

			
			/*
			
			if (rbBalle->GetPosition().y > 0)
			{
				rbBalle->SetLinearVelocity(b2Vec2(rbBalle->GetLinearVelocity().x, rbBalle->GetLinearVelocity().y * -1));
			}

			if (rbBalle->GetPosition().y < 1050)
			{
				rbBalle->SetLinearVelocity(b2Vec2(rbBalle->GetLinearVelocity().x, rbBalle->GetLinearVelocity().y * -1));
			}
			*/
			std::map<int, AEntity*>::iterator it;

			
			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				it->second->Update(deltaTime);
			}

			_physics.Update(deltaTime);

			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				it->second->LateUpdate();
			}

			_window.clear();
			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				_window.draw(*it->second);
			}
			_window.display();
		}
	}
}

HorrorEngine::AEntity* HorrorEngine::Application::CreateEntity(std::string name)
{
	HorrorEngine::AEntity* entity = new AEntity(name);
	entity->_ID = GenerateID();
	entitiesList.insert({ entity->GetID(), entity });
	std::cout << "the entity : " << name << " was created with ID=" << entity->_ID << std::endl;
	return entity;
}

void HorrorEngine::Application::GetAllComponents(AEntity* parent, std::map<int, AComponent*> result)
{

}

HorrorEngine::Application* HorrorEngine::Application::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Application();
	}
	return _instance;
}

int HorrorEngine::Application::GenerateID()
{
	_entityID++;
	return _entityID;
}

