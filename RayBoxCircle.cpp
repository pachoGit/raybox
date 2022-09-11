#include "RayBoxCircle.hpp"
#include "RayCircle.hpp"
#include <box2d/b2_body.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_world.h>
#include "Convertir.hpp"

RayBoxCircle::RayBoxCircle()
{
    world = nullptr;
    body = nullptr;
    circle = nullptr;
}

RayBoxCircle::RayBoxCircle(Vector2 _center, float _radius, Color _color, b2World *_world, b2BodyType type)
{
    circle = new RayCircle( _center, _radius, _color);
    world = _world;
    createDefaultBody(type);
    createInitialCollider();
}

RayBoxCircle::RayBoxCircle(RayCircle *_circle, b2World *_world, b2BodyType type)
{
    circle = _circle;
    world = _world;
    createDefaultBody(type);
    createInitialCollider();
}

void RayBoxCircle::drop()
{
    if (circle)
        delete circle;
    if (body)
        world->DestroyBody(body);
}

RayBoxCircle::~RayBoxCircle()
{
    drop();
}

void RayBoxCircle::draw()
{
    if (circle)
    {
        float tempRadius = circle->radius;
        Vector2 tempCenter = circle->center;
        circle->radius = Convertir::MetrosEnPixeles(tempRadius);
        circle->center = Convertir::MetrosEnPixeles(tempCenter);
        circle->draw();
        circle->radius = tempRadius;
        circle->center = tempCenter;
    }
}

void RayBoxCircle::createDefaultBody(b2BodyType type)
{
    if (!circle)
        return;
    b2BodyDef bdef;
    bdef.type = type;
    bdef.position.Set(circle->center.x, circle->center.y);
    body = world->CreateBody(&bdef);
}

void RayBoxCircle::createInitialCollider()
{
    if (!circle || !body)
        return;
    b2CircleShape shape;
    shape.m_radius = circle->radius;
    if (body)
    {
        if (body->GetType() == b2_staticBody)
            body->CreateFixture(&shape, 0.f);
        else
            body->CreateFixture(&shape, 1.f);;
    }
}
