#include <raylib.h>

#include "RayCircle.hpp"

RayCircle::RayCircle()
{
    radius = 0.f;
    center = {0, 0};
    color = BLUE;
    outline = false;
    startAngle = 0.f;
    endAngle = 0.f;
    segments = 0;
}

RayCircle::RayCircle(int _centerX, int _centerY, float _radius, Color _color)
{
    center.x = _centerX;
    center.y = _centerY;
    radius = _radius;
    color = _color;
    outline = false;
    startAngle = 0.f;
    endAngle = 360.f;
    segments = 36;
}

RayCircle::RayCircle(Vector2 _center, float _radius, Color _color)
{
    center = _center;
    radius = _radius;
    color = _color;
    outline = false;
    startAngle = 0.f;
    endAngle = 360.f;
    segments = 36;
}

void RayCircle::draw()
{
    if (outline)
        DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, color);
    else
        DrawCircleSector(center, radius, startAngle, endAngle, segments, color);
}

void RayCircle::setOutline(bool _outline)
{
    outline = _outline;
}
