#include "raylib.h"

int main()
{
    //Window Dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Huw's Window");

    //Circle Set up
    int circle_start_x{200};
    int circle_start_y{200};
    int circle_radius{25};
    int circle_x{circle_start_x};
    int circle_y{circle_start_y};

    //Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //Axe Set Up
    int axe_start_x{400};
    int axe_start_y{0};
    int axe_x{axe_start_x};
    int axe_y{axe_start_y};
    int direction{10};
    int axe_length{50};
    //Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    bool collisionWithAxe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collisionWithAxe)
        {
            DrawText("Game Over!", 400, 200, 50, RED);

            if(IsKeyDown(KEY_R)) //Reset game on R key press
            {
                circle_x = circle_start_x;
                circle_y = circle_start_y;
                axe_x = axe_start_x;
                axe_y = axe_start_y;
                collisionWithAxe = false;
            }
        }
        else
        {
            //Game Logic Begins

            //Update Collider Edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y +  axe_length;

            //Update Collision Detection
            collisionWithAxe = 
                    (b_axe_y >= u_circle_y) && 
                    (u_axe_y <= b_circle_y) && 
                    (l_axe_x <= r_circle_x) && 
                    (r_axe_x >= l_circle_x);
            
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            //Move Axe
            axe_y += direction;

            if(axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && circle_x < width)
            {
                circle_x += 10;
            }

            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && circle_x > 0)
            {
            circle_x -= 10;
            }

            //Game Logic Ends
        }

        EndDrawing();
    }
}