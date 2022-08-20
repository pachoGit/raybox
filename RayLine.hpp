#ifndef RAY_LINE_H_
#define RAY_LINE_H_

#include <raylib.h>

class RayLine
{
    public:

        Vector2 startPos;

        Vector2 endPos;

        float thick;

        Color color;

    public:

        RayLine();

        RayLine(Vector2 _startPos, Vector2 _endPos, Color _color);

        RayLine(Vector2 _startPos, Vector2 _endPos, float _thick, Color _color);

        void draw();

        // Obtener la longitud de la linea
        float getLength() const;

        // Obtener el angulo de inclinacion de la linea en grados
        float getAngle() const;
};

#endif // RAY_LINE_H_
