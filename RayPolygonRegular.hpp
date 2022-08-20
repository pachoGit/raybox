#ifndef RAY_POLYGON_REGULAR_H_
#define RAY_POLYGON_REGULAR_H_

#include <raylib.h>

/*
** Clase para la rapida creacion de poligonos regulares
*/
class RayPolygonRegular
{
    public:

        Vector2 center;

        int sides;

        float radius;

        float rotation;

        Color color;

        bool outline;

        float lineThick;

    public:

        RayPolygonRegular();

        RayPolygonRegular(Vector2 _center, int _sides, float _radius, float _rotation, Color _color);

        void draw();

        void setOutline(bool _outline);
};

#endif // RAY_POLYGON_REGULAR_H_
