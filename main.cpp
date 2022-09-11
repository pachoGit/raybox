#include <box2d/b2_body.h>
#include <box2d/b2_common.h>
#include <box2d/b2_math.h>
#include <box2d/b2_world.h>
#include <iostream>
#include <raylib.h>

#include "Convertir.hpp"
#include "RayBoxCircle.hpp"
#include "RayBoxRectangle.hpp"
#include "RayRectangle.hpp"
#include "RayCircle.hpp"
#include "RayLine.hpp"
#include "RayChain.hpp"
#include "RayPolygonRegular.hpp"
#include "RayPolygonIrregular.hpp"

int main(int argc, char *argv[])
{
    InitWindow(Convertir::MetrosEnPixeles(40), Convertir::MetrosEnPixeles(30), "RayBox 1.0");
    SetTargetFPS(60);

    RayRectangle r1({80, 80, 50, 50}, 10.f, BLUE);
    RayCircle c1({150, 150}, 20, RED);
    //c1.setOutline(true);
    c1.startAngle = 10.f;
    c1.endAngle = 260.f;
    RayLine l1({30, 90}, {70, 200}, 1.f, GREEN);
    std::cout << "Longitud: " << l1.getLength() << std::endl;
    std::cout << "Angulo:   " << l1.getAngle() << std::endl;

    Vector2 e1[4] =
        {
        {100, 100},
        {150, 100},
        {150, 150},
        {200, 150}
    };
    RayChain p1(e1, 4, BLACK);

    RayLine e2[4] =
        {
        RayLine({200, 200}, {250, 200}, BLUE),
        RayLine({250, 200}, {250, 250}, GREEN),
        RayLine({250, 250}, {300, 200}, RED),
        RayLine({300, 200}, {400, 300}, YELLOW)
    };

    RayChain p2(e2, 4);

    RayPolygonRegular v1({400, 400}, 7, 40.f, 50.f, BROWN);
    v1.setOutline(true);
    v1.lineThick = 3.f;

    Vector2 e3[5] =
        {
        {-20, -50},
        {-40, 70},
        {70, 60},
        {50, -30},
        {-20, -50}
    };

    RayPolygonIrregular h1(e3, 5, {150, 150}, PURPLE);

    // Fisicas
    b2World physicsWorld(b2Vec2(0, 10));

    RayBoxRectangle prec(new RayRectangle({10.f, 1.f, 2.f, 2.f}, 10.f, RED), &physicsWorld, b2_dynamicBody);
    RayBoxRectangle flat(new RayRectangle({10.f, 20.f, 3.f, 1.f}, 0.f, GREEN), &physicsWorld, b2_staticBody);
    prec.body->GetFixtureList()->SetRestitution(0.3f);

    RayBoxCircle fcircle(new RayCircle({10, 4}, 2.f, BLUE), &physicsWorld, b2_dynamicBody);

    // Me quede el en el dibujar de RayBoxCircle aun falta sincronizar :D

    while (!WindowShouldClose())
    {
        v1.rotation++;
        h1.rotation++;

        physicsWorld.Step(1.f / 60.f, 6, 3);
        prec.syncGraphicsWithPhysics();
        flat.syncGraphicsWithPhysics();

        BeginDrawing();
        ClearBackground(GRAY);

        r1.draw();
        c1.draw();
        l1.draw();
        p1.draw();
        p2.draw();
        v1.draw();
        h1.draw();

        prec.draw();
        flat.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
