#include <array>
#include <cstdlib>
#include <raylib.h>
#include <raymath.h>
#include <tuple>
#include <utility>
#include <algorithm>

#include "RayPolygonIrregular.hpp"

RayPolygonIrregular::RayPolygonIrregular()
{
    points = nullptr;
    pointCount = 0;
    center = {0};
    color = BLUE;
    texture = {0};
    rotation = 0.f;
    positions = nullptr;
    texcoords = nullptr;
}

RayPolygonIrregular::RayPolygonIrregular(Vector2 *_points, int _pointCount, Vector2 _center, Color _color)
{
    points = _points;
    pointCount = _pointCount;
    center = _center;
    color = _color;
    texture = makeTexture();
    rotation = 0.f;

    positions = (Vector2 *) malloc(sizeof(Vector2) * pointCount);
    texcoords = (Vector2 *) malloc(sizeof(Vector2) * pointCount);
    calculateTexcoords();
}

RayPolygonIrregular::~RayPolygonIrregular()
{
    if (positions)
        free(positions);
    if (texcoords)
        free(texcoords);
}

void RayPolygonIrregular::draw()
{
    if (points && positions && texcoords && pointCount > 3)
    {
        // Rotamos el poligono
        for (int i = 0; i < pointCount; ++i)
            positions[i] = Vector2Rotate(points[i], rotation * DEG2RAD);

        DrawTexturePoly(texture, center, positions, texcoords, pointCount, WHITE);
    }
}

Texture2D RayPolygonIrregular::makeTexture()
{
    Texture2D newTexture = {0};
    Image image = GenImageColor(DIM_TEXTURE, DIM_TEXTURE, color);
    newTexture = LoadTextureFromImage(image);
    return newTexture;
}

void RayPolygonIrregular::calculateTexcoords()
{
    // Valores minimos y maximos de las "x" e "y"
    auto getMinMax = [&] () {
        std::array<std::pair<float, float>, 2> minMax;
        minMax.at(0) = {points[0].x, points[0].x}; // Minimo "x", Maximo "x"
        minMax.at(1) = {points[0].y, points[0].y}; // Minimo "y", Maximo "y"

        for (int i = 0; i < pointCount; ++i)
        {
            minMax.at(0).first = std::min(minMax.at(0).first, points[i].x);
            minMax.at(0).second = std::max(minMax.at(0).second, points[i].x);

            minMax.at(1).first = std::min(minMax.at(1).first, points[i].y);
            minMax.at(1).second = std::max(minMax.at(1).second, points[i].y);
        }
        return minMax;
    };

    auto minMax = getMinMax();

    float width = minMax.at(0).second - minMax.at(0).first;
    float height = minMax.at(1).second - minMax.at(1).first;
    TraceLog(LOG_INFO, "MinX: %.2f - MaxX: %.2f <--> MinY: %.2f - MaxY: %.2f", minMax.at(0).first, minMax.at(0).second, minMax.at(1).first, minMax.at(1).second);
    TraceLog(LOG_INFO, "Width: %.2f - Height: %.2f", width, height);

    float scaleX = 1 / width;
    float scaleY = 1 / height;

    TraceLog(LOG_INFO, "ScaleX: %.2f - ScaleY: %.2f", scaleX, scaleY);

    TraceLog(LOG_INFO, "Calculando las texcoords...");
    for (int i = 0; i < pointCount; ++i)
    {
        texcoords[i].x = std::abs(minMax.at(0).first - points[i].x) * scaleX;
        texcoords[i].y = std::abs(minMax.at(1).first - points[i].y) * scaleY;
        TraceLog(LOG_INFO, "X =(%.2f - %.2f) * %.2f = %.2f", minMax.at(0).first, points[i].x, scaleX, texcoords[i].x);
        TraceLog(LOG_INFO, "Y =(%.2f - %.2f) * %.2f = %.2f", minMax.at(1).first, points[i].y, scaleY, texcoords[i].y);
    }
}
