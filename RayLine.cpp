#include <raylib.h>
#include <cmath>

#include "RayLine.hpp"

RayLine::RayLine()
{
    startPos = {0};
    endPos = {0};
    thick = 0.f;
    color = BLUE;
}

RayLine::RayLine(Vector2 _startPos, Vector2 _endPos, Color _color)
{
    startPos = _startPos;
    endPos = _endPos;
    thick = 1.f;
    color = _color;
}

RayLine::RayLine(Vector2 _startPos, Vector2 _endPos, float _thick, Color _color)
{
    startPos = _startPos;
    endPos = _endPos;
    thick = _thick;
    color = _color;
}

void RayLine::draw()
{
    DrawLineEx(startPos, endPos, thick, color);
}

float RayLine::getLength() const
{
    float lx = startPos.x - endPos.x;
    float ly = startPos.y - endPos.y;

    return std::sqrt(lx * lx + ly * ly);
}

float RayLine::getAngle() const
{
    // Usando la formula de tan(a) = y2 - y1 / x2 - x1
    return std::atan((endPos.y - startPos.y/ endPos.x - startPos.x) * DEG2RAD) * RAD2DEG;
}
