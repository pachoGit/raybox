#include "RayRectangle.hpp"

RayRectangle::RayRectangle()
{
    rec = {0};
    rotation = 0.f;
    origin = {0.f, 0.f};
    color = BLUE;
}

RayRectangle::RayRectangle(int _posX, int _posY, int _width, int _height, float _rotation, Color _color)
{
    rec.x = _posX;
    rec.y = _posY;
    rec.width = _width;
    rec.height = _height;
    rotation = _rotation;
    origin = getHalfDimension();
    color = _color;
}

RayRectangle::RayRectangle(Rectangle _rec, float _rotation, Color _color)
{
    rec.x = _rec.x;
    rec.y = _rec.y;
    rec.width = _rec.width;
    rec.height = _rec.height;
    rotation = _rotation;
    origin = getHalfDimension();
    color = _color;
}

void RayRectangle::draw()
{
    DrawRectanglePro(rec, origin, rotation, color);
}

Vector2 RayRectangle::getHalfDimension() const
{
    return {rec.width * 0.5f, rec.height * 0.5f};
}

Vector2 RayRectangle::getPosition() const
{
    return {rec.x, rec.y};
}

Vector2 RayRectangle::getDimension() const
{
    return {rec.width, rec.height};
}
