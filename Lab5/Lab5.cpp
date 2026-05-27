#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;

    const int WIDTH = 640;
    const int HEIGHT = 480;

    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    display = al_create_display(WIDTH, HEIGHT);

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

        al_flip_display();
    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}