#include <SFML/System.h>
#include <SFML/Graphics.h>

int main()
{
  //Paramètrage des dimensions de la fenêtre 
    sfVideoMode mode = {1920, 1080, 32};

    sfRenderWindow* window;
    sfEvent event;
    sfTexture* texture;
    sfSprite* sprite;

    // Création de la fenêtre
    window = sfRenderWindow_create(mode, "Petit tuto", sfDefaultStyle, NULL);

    // Chargement de la texture du sprite depuis un fichier
    texture = sfTexture_createFromFile("Sprites_tek2/Pac-Man/Sprites/Background.png", NULL);

    // Création du sprite
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    // Boucle principale
    while (sfRenderWindow_isOpen(window))
    {
        // Gestion des événements
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        // Effacement de la fenêtre
        sfRenderWindow_clear(window, sfBlack);

        // Ajout du sprite sur la fenêtre
        sfRenderWindow_drawSprite(window, sprite, NULL);

        // Affichage de la fenêtre
        sfRenderWindow_display(window);
    }

    // Destruction des ressources
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);

    return 0;
}
