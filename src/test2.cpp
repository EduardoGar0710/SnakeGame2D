#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Reproducir Sonido con SFML");

    // Cargar el archivo de sonido
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("./assets/music/musica.ogg"))
    {
        std::cerr << "Error al cargar el archivo de sonido" << std::endl;
        return -1;
    }

    // Crear un objeto de sonido y establecer su buffer
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Reproducir el sonido
    sound.play();

    // Bucle principal
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar elementos del juego aquí

        // Mostrar lo que se ha dibujado en la ventana
        window.display();
    }

    return 0;
}
