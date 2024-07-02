#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Texto con SFML");

    // Cargar la fuente
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/Ring.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;
        return -1;
    }

    // Crear un objeto de texto
    sf::Text text;
    text.setFont(font); // Establecer la fuente
    text.setString("Hola SFML"); // Establecer el texto
    text.setCharacterSize(50); // Tamaño del texto
    text.setFillColor(sf::Color::White); // Color del texto
    text.setPosition(100, 100); // Posición del texto en la ventana

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

        // Dibujar el texto
        window.draw(text);

        // Mostrar lo que se ha dibujado en la ventana
        window.display();
    }

    return 0;
}
