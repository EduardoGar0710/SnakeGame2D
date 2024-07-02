#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Sounds
{
public:
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    Sounds()
    {
        if (!buffer.loadFromFile("./assets/music/eat.ogg"))
        {
            std::cerr << "Error al cargar el archivo de sonido" << std::endl;
        }

        sound.setBuffer(buffer);
    };
};
