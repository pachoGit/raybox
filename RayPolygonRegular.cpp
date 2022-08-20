#include "RayPolygonRegular.hpp"
#include <raylib.h>

RayPolygonRegular::RayPolygonRegular()
{
    center = {0};
    sides = 0;
    radius = 0.f;
    rotation = 0.f;
    color = BLUE;
    outline = false;
    lineThick = 1.f;
}

RayPolygonRegular::RayPolygonRegular(Vector2 _center, int _sides, float _radius, float _rotation, Color _color)
{
    center = _center;
    sides = _sides;
    radius = _radius;
    rotation = _rotation;
    color = _color;
    outline = false;
    lineThick = 1.f;
}

void RayPolygonRegular::draw()
{
    if (outline)
        DrawPolyLinesEx(center, sides, radius, rotation, lineThick, color);
    else
        DrawPoly(center, sides, radius, rotation, color);
}

void RayPolygonRegular::setOutline(bool _outline)
{
    outline = _outline;
}
