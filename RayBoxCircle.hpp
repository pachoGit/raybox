#ifndef RAYBOX_CIRCLE_H_
#define RAYBOX_CIRCLE_H_

#include "RayCircle.hpp"
#include <box2d/b2_body.h>
#include <box2d/b2_world.h>

class RayBoxCircle
{
    public:

        b2World *world;

        b2Body *body;

        RayCircle *circle;

    public:

        RayBoxCircle();

        RayBoxCircle(Vector2 _center, float _radius, Color _color, b2World *_world, b2BodyType type);

        RayBoxCircle(RayCircle *_circle, b2World *_world, b2BodyType type);

        void drop();

        ~RayBoxCircle();

        void draw();

    private:

        void createDefaultBody(b2BodyType type);

        void createInitialCollider();
};


#endif // RAYBOX_CIRCLE_H_
