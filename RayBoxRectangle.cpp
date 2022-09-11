#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <raylib.h>

#include "Convertir.hpp"
#include "RayBoxRectangle.hpp"
#include "RayRectangle.hpp"

RayBoxRectangle::RayBoxRectangle()
{
    world = nullptr;
    body = nullptr;
    rec = nullptr;
}

RayBoxRectangle::RayBoxRectangle(Rectangle _rec, float _rotation, Color _color, b2World *_world, b2BodyType type)
{
    world = _world;
    rec = new RayRectangle(_rec, _rotation, _color);
    createDefaultBody(type);
    createInitialCollider();
}

RayBoxRectangle::RayBoxRectangle(RayRectangle *_rec, b2World *_world, b2BodyType type)
{
    world = _world;
    rec = _rec;
    createDefaultBody(type);
    createInitialCollider();
}

void RayBoxRectangle::drop()
{
    if (rec)
        delete rec;
    if (body)
        world->DestroyBody(body);
}

RayBoxRectangle::~RayBoxRectangle()
{
    drop();
}

void RayBoxRectangle::syncGraphicsWithPhysics()
{
    if (rec && body)
    {
        rec->rec.x = body->GetPosition().x;
        rec->rec.y = body->GetPosition().y;
        rec->rotation = body->GetAngle() * RAD2DEG;
    }
}

void RayBoxRectangle::draw()
{
    if (rec)
    {
        Rectangle tempRec = rec->rec;
        Vector2 tempOrigin = rec->origin;
        rec->rec = Convertir::MetrosEnPixeles(tempRec);
        rec->origin = Convertir::MetrosEnPixeles(tempOrigin);
        rec->draw();
        rec->rec = tempRec;
        rec->origin = tempOrigin;
    }
}

Vector2 RayBoxRectangle::getPosition() const
{
    Vector2 position = {0};
    if (rec)
        position = rec->getPosition();
    return position;
}

float RayBoxRectangle::getAngle() const
{
    float angle = 0.f;
    if (rec)
        angle = rec->rotation;
    return angle;
}

void RayBoxRectangle::createDefaultBody(b2BodyType type)
{
    if (!rec)
        return;
    b2BodyDef bdef;
    bdef.type = type;
    bdef.position.Set(rec->rec.x, rec->rec.y);
    bdef.angle = rec->rotation * DEG2RAD;
    body = world->CreateBody(&bdef);
}

void RayBoxRectangle::createInitialCollider()
{
    if (!rec || !body)
        return;
    b2PolygonShape shape;
    Vector2 half = rec->getHalfDimension();
    shape.SetAsBox(half.x, half.y);
    if (body)
    {
        if (body->GetType() == b2_staticBody)
            body->CreateFixture(&shape, 0.f);
        else
            body->CreateFixture(&shape, 1.f);;
    }
}
