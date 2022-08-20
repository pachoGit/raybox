#ifndef RAYBOX_RECTANGLE_H_
#define RAYBOX_RECTANGLE_H_

#include <box2d/b2_body.h>
#include <box2d/b2_world.h>
#include <box2d/box2d.h>
#include "RayRectangle.hpp"

class RayBoxRectangle
{
    public:

        // El mundo al que esta sujeto el cuerpo. SOLO LECTURA
        b2World *world;

        // El cuerpo de box2d
        b2Body *body;

        // La forma del cuerpo
        RayRectangle *rec;


    public:

        RayBoxRectangle();

        RayBoxRectangle(Rectangle _rec, float _rotation, Color _color, b2World *_world, b2BodyType type);

        RayBoxRectangle(RayRectangle *_rec, b2World *_world, b2BodyType type);

        // Destruir el cuerpo (de memoria)
        void drop();

        ~RayBoxRectangle();

        // Sincroniza la posicion y angulo que calcula el motor de fisicas con los graficos
        void syncGraphicsWithPhysics();

        // Dibujar el cuerpo y el objeto
        void draw();

    private:

        // Crea un colisionador rectangular por defecto para el objeto
        // Los valores del colisionador (fixture) tambien son por defecto provenientes de box2d
        void createInitialCollider();

};

#endif // RAYBOX_RECTANGLE_H_
