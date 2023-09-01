#include "raylib.h"

int main()
{
    // window dimensions
    int window_width{800};
    int window_height{450};
    InitWindow(window_width, window_height, "Window!!!");

    // circle coordinates
    int circle_x{200};
    int circle_y{300};

    // circle radius
    int circle_radius{25};

    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe dimensions
    int axe_width{50};
    int axe_height{50};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};

    // axe edges
    int l_axe_x{axe_x};
    int u_axe_y{axe_y};
    int r_axe_x{axe_x + axe_width};
    int b_axe_y{axe_y + axe_height};

    // direction of the velocity of the axe
    int direction{10};

    bool collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);

    SetTargetFPS(60);
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe)
        {
            DrawText("Game Over!!!", 400, 200, 25, RED);
        }

        else 
        {

        // Game logic begins
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

        // Updating the edges of circle and axe each frame
        int l_circle_x{circle_x - circle_radius};
        int u_circle_y{circle_y - circle_radius};
        int r_circle_x{circle_x + circle_radius};
        int b_circle_y{circle_y + circle_radius};
        int l_axe_x{axe_x};
        int u_axe_y{axe_y};
        int r_axe_x{axe_x + axe_width};
        int b_axe_y{axe_y + axe_height};

        // Performing collision check each frame
        collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);      

        axe_y += direction;
        if(axe_y < 0 || axe_y > window_height)
        {
            direction = -direction;
        }

        if(IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }

        if(IsKeyDown(KEY_D) && circle_x < window_width)
        {
            circle_x += 10;
        }

        if(IsKeyDown(KEY_W) && circle_y > 0)
        {
            circle_y -= 10;
        }

        if(IsKeyDown(KEY_S) && circle_y < window_height)
        {
            circle_y += 10;
        }

        }

        EndDrawing();

    }
    
}