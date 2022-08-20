#include <raylib.h>

#include "RayChain.hpp"

RayChain::RayChain()
{
    points = nullptr;
    pointCount = 0;
    color = BLUE;
    lines = nullptr;
    lineCount = 0;
}

RayChain::RayChain(Vector2 *_points, int _pointCount, Color _color)
{
    points = _points;
    pointCount = _pointCount;
    color = _color;
    lines = nullptr;
    lineCount = 0;
}

RayChain::RayChain(RayLine *_lines, int _lineCount)
{
    lines = _lines;
    lineCount = _lineCount;

    points = nullptr;
    pointCount = 0;
    color = BLUE;
}

void RayChain::draw()
{
    if (lines)
    {
        for (int i = 0; i < lineCount; ++i)
            lines[i].draw();
        return;
    }

    if (points)
        DrawLineStrip(points, pointCount, color);
}
