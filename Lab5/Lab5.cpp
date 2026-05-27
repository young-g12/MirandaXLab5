#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

void create_bitmap(ALLEGRO_BITMAP* bmp[], ALLEGRO_DISPLAY* display);

int main()
{
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;

    const int WIDTH = 640;
    const int HEIGHT = 480;

    ALLEGRO_BITMAP* bmp[4] = { NULL,NULL,NULL,NULL };

    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    display = al_create_display(WIDTH, HEIGHT);

    create_bitmap(bmp, display);

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;

    while (!done)
    {
        ALLEGRO_EVENT ev;

        al_wait_for_event(queue, &ev);

        if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_bitmap(bmp[0], 50, 50, 0);
        al_draw_bitmap(bmp[1], 200, 50, 0);
        al_draw_bitmap(bmp[2], 350, 50, 0);
        al_draw_bitmap(bmp[3], 500, 50, 0);

        al_flip_display();
    }

    for (int i = 0; i < 4; i++)
    {
        al_destroy_bitmap(bmp[i]);
}

    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}

void create_bitmap(ALLEGRO_BITMAP* bmp[], ALLEGRO_DISPLAY* display)
{
    for (int i = 0; i < 4; i++)
    {
        bmp[i] = al_create_bitmap(64, 64);
        al_set_target_bitmap(bmp[i]);

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_filled_ellipse(
            32, 40,
            20, 10,
            al_map_rgb(255, 0, 255));

        al_draw_filled_circle(
            32, 28,
            10,
            al_map_rgb(0, 255, 255));

        al_draw_filled_rectangle(
            28, 5,
            36, 20,
            al_map_rgb(150, 150, 150));

        al_draw_line(
            32, 5,
            32, 0,
            al_map_rgb(255, 255, 255),
            2);

        al_draw_filled_triangle(
            28, 5,
            36, 5,
            32, 0,
            al_map_rgb(255, 0, 0));
    }

    al_set_target_backbuffer(display);

}