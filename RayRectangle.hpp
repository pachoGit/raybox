#ifndef RAY_RECTANGLE_H_
#define RAY_RECTANGLE_H_

#include <raylib.h>

/*
** Clase simple para el manejo de rectangulos de Raylib
** NOTE: El origen por defecto es el centro del rectangulo
** TODO: No tiene soporte para Gradiente, Outline ni Rounded
*/

class RayRectangle
{
    public:

        Rectangle rec;

        float rotation;

        Vector2 origin;

        Color color;

    public:

        RayRectangle();

        RayRectangle(int _posX, int _posY, int _width, int _height, float _rotation, Color _color);

        RayRectangle(Rectangle _rec, float _rotation, Color _color);

        ~RayRectangle() = default;

        void draw();

        Vector2 getHalfDimension() const;

        Vector2 getPosition() const;

        Vector2 getDimension() const;
};

#endif // RAY_RECTANGLE_H_
