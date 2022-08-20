#ifndef RAY_CIRCLE_H_
#define RAY_CIRCLE_H_

#include <raylib.h>

class RayCircle
{
    public:

        float radius;

        Vector2 center;

        Color color;

        // Habilitar el dibujado del contorno
        bool outline;

        // Para el dibujar una pieza del circulo
        float startAngle;

        float endAngle;

        int segments;

    public:

        RayCircle();

        RayCircle(int _centerX, int _centerY, float _radius, Color _color);

        RayCircle(Vector2 _center, float _radius, Color _color);

        void draw();

        void setOutline(bool _outline);
};

#endif // RAY_CIRCLE_H_
