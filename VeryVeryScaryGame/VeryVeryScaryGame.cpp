
#include <iostream>
#include <SFML/Graphics.hpp>
#include <HorrorEngine/Application.h>
#include <HorrorEngine/Camera.h>
#include <HorrorEngine/ResourceManager.h>
#include <HorrorEngine/SpriteRenderer.h>
#include <HorrorEngine/BoxCollider.h>

int main()
{
    HorrorEngine::Application MyApp;
    MyApp.Init(1920, 1080, "Absolutly Scary Game");
    HorrorEngine::ResourceManager ressourceManager = HorrorEngine::ResourceManager("rm");

















    /*HorrorEngine::AEntity* gwen = MyApp.CreateEntity("Gwen");
    gwen->transform.setPosition(500, 20);
    gwen->transform.setRotation(50);
    HorrorEngine::Camera* yeux = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Camera>(gwen);
    yeux->Init(&MyApp._window);
    HorrorEngine::SpriteRenderer* cheveuxBleus = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxBleus->Init("gwen.png");
    cheveuxBleus->SetColor(12, 132, 238);
    cheveuxBleus->SetSize(200, 100);
    HorrorEngine::SpriteRenderer* cheveuxRoses = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxRoses->Init("gwen.png");
    cheveuxRoses->SetColor(176, 23, 191);
    cheveuxRoses->SetSize(1, 2);*/

    HorrorEngine::AEntity* maxime = MyApp.CreateEntity("Maxime");
    maxime->transform.setPosition(50, 300);
    HorrorEngine::SpriteRenderer* cheveuxRouges = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(maxime);
    cheveuxRouges->Init("gwen.png");
    cheveuxRouges->SetColor(254, 254, 254);
    HorrorEngine::BoxCollider* carre = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::BoxCollider>(maxime);
    HorrorEngine::Rigidbody* rb = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Rigidbody>(maxime);
    carre->SetDensity(1);
    carre->SetHeight(70, 170);
    cheveuxRouges->SetSize(0.2f, 0.75f);
    carre->CreateFixture(rb->GetBody());
    rb->SetBodyType(b2_dynamicBody);

    HorrorEngine::AEntity* gwen = MyApp.CreateEntity("Gwen");
    gwen->transform.setPosition(1835, 600);
    HorrorEngine::SpriteRenderer* cheveuxNoir = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxNoir->Init("gwen.png");
    cheveuxNoir->SetColor(254, 254, 254);
    HorrorEngine::BoxCollider* carre2 = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::BoxCollider>(gwen);
    HorrorEngine::Rigidbody* rb2 = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Rigidbody>(gwen);
    carre2->SetDensity(1);
    carre2->SetHeight(70, 170);
    cheveuxNoir->SetSize(0.2f, 0.75f);
    carre2->CreateFixture(rb2->GetBody());
    rb2->SetBodyType(b2_dynamicBody);

    HorrorEngine::AEntity* orian = MyApp.CreateEntity("Orian");
    orian->transform.setPosition(200, 600);
    HorrorEngine::SpriteRenderer* cheveuxMarron = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(orian);
    cheveuxMarron->Init("orianpong.png");
    cheveuxMarron->SetColor(254, 254, 254);
    HorrorEngine::BoxCollider* balle = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::BoxCollider>(orian);
    HorrorEngine::Rigidbody* rb3 = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Rigidbody>(orian);
    balle->SetDensity(1);
    balle->SetHeight(30, 30);
    cheveuxMarron->SetSize(0.1f, 0.1f);
    balle->CreateFixture(rb3->GetBody());
    rb3->SetBodyType(b2_dynamicBody);
    if (rb3->GetLinearVelocity() == b2Vec2(0, 0))
    {
        rb3->SetLinearVelocity(b2Vec2(0.1f, 0.01f));
    }

    HorrorEngine::AEntity* wallTop = MyApp.CreateEntity("wall top");
    wallTop->transform.setPosition(-5, -5);
    HorrorEngine::SpriteRenderer* spriteMurTop = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(wallTop);
    spriteMurTop->Init("orianpong.png");
    spriteMurTop->SetColor(254, 254, 254);
    HorrorEngine::BoxCollider* mapLimitTop = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::BoxCollider>(wallTop);
    HorrorEngine::Rigidbody* rb4 = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Rigidbody>(wallTop);
    mapLimitTop->SetDensity(1);
    mapLimitTop->SetHeight(1920, 100);
    spriteMurTop->SetSize(10, 0.5f);
    mapLimitTop->CreateFixture(rb4->GetBody());
    rb4->SetBodyType(b2_dynamicBody);


    HorrorEngine::AEntity* wallDown = MyApp.CreateEntity("wall down");
    wallDown->transform.setPosition(-5, 900);
    HorrorEngine::SpriteRenderer* spriteMurDown = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(wallDown);
    spriteMurDown->Init("orianpong.png");
    spriteMurDown->SetColor(254, 254, 254);
    HorrorEngine::BoxCollider* mapLimitDown = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::BoxCollider>(wallDown);
    HorrorEngine::Rigidbody* rb5 = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Rigidbody>(wallDown);
    mapLimitDown->SetDensity(1);
    mapLimitDown->SetHeight(1920, 100);
    spriteMurDown->SetSize(10, 0.5f);
    mapLimitDown->CreateFixture(rb5->GetBody());
    rb5->SetBodyType(b2_dynamicBody);


    

    MyApp.Loop();

    return 0;
}