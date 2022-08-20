#ifndef RAY_CHAIN_H_
#define RAY_CHAIN_H_

#include <raylib.h>

#include "RayLine.hpp"
/*
** Dibujar una serie de lineas (cadena)
** NOTE: Puede usar tanto una serie de puntos como una serie de lineas para realizarla
** NOTE: El que tiene mayor prioridad es la serie de lineas (RayLine)
*/
class RayChain
{
    public:

        // Solo lectura
        Vector2 *points;

        int pointCount;

        Color color;

        // Solo lectura
        RayLine *lines;

        int lineCount;

public:

        RayChain();

        RayChain(Vector2 *_points, int _pointCount, Color _color);

        RayChain(RayLine *_lines, int _lineCount);

        void draw();
};

#endif // RAY_CHAIN_H_
