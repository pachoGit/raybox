#ifndef RAY_POLYGON_IRREGULAR_H_
#define RAY_POLYGON_IRREGULAR_H_

#include <raylib.h>

#define DIM_TEXTURE 5

class RayPolygonIrregular
{
    public:

        // Solo lectura
        Vector2 *points;

        int pointCount;

        // La posicion del poligono
        Vector2 center;

        Color color;

        Texture2D texture;

        float rotation;

    private:

        Vector2 *positions;

        Vector2 *texcoords;


    public:

        RayPolygonIrregular();

        ~RayPolygonIrregular();

        RayPolygonIrregular(Vector2 *_points, int _pointCount, Vector2 _center, Color _color);

        void draw();

    private:

        Texture2D makeTexture();

        void calculateTexcoords();
};



#endif // RAY_POLYGON_IRREGULAR_H_
