#ifndef CONVERTIR_HPP
#define CONVERTIR_HPP

#include <raylib.h>
#include <box2d/box2d.h>

// Cada 20 pixeles equivale a 1 metro :D
#define PIXELES_POR_METRO 20

class Convertir
{
  public:

    static float GradosEnRadianes(float grados)
    {
        return grados * DEG2RAD;
    }

    static float RadianesEnGrados(float radianes)
    {
        return radianes * RAD2DEG;
    }

    static b2Vec2 VectorRaylibEnBox2d(Vector2 vector)
    {
        return b2Vec2(vector.x, vector.y);
    }
    
    static Vector2 VectorBox2dEnRaylib(b2Vec2 vector)
    {
        return (Vector2) {vector.x, vector.y};
    }

    static float PixelesEnMetros(float pixeles)
    {
        return pixeles / PIXELES_POR_METRO;
    }

    static float MetrosEnPixeles(float metros)
    {
        return metros * PIXELES_POR_METRO;
    }

    static Vector2 PixelesEnMetros(const Vector2 &pixeles)
    {
        return {
            PixelesEnMetros(pixeles.x),
            PixelesEnMetros(pixeles.y)
        };
    }
    
    static Vector2 MetrosEnPixeles(const Vector2 &metros)
    {
        return {
            MetrosEnPixeles(metros.x),
            MetrosEnPixeles(metros.y)
        };
    }

    static Rectangle PixelesEnMetros(const Rectangle &pixeles)
    {
        return {
            PixelesEnMetros(pixeles.x),
            PixelesEnMetros(pixeles.y),
            PixelesEnMetros(pixeles.width),
            PixelesEnMetros(pixeles.height),
        };
    }

    static Rectangle MetrosEnPixeles(const Rectangle &metros)
    {
        return {
            MetrosEnPixeles(metros.x),
            MetrosEnPixeles(metros.y),
            MetrosEnPixeles(metros.width),
            MetrosEnPixeles(metros.height)
        };
    }

};

#endif /* CONVERTIR_HPP */
