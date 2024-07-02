#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <Box2D/Box2D.h>
#include <Mapa.hpp>
#include <iostream>
#include <Snake.hpp>
#include <Food.hpp>
#include <cstdlib>
#include <ctime>
#include <Walls.hpp>
#include <Sounds.hpp>

double velocidad = 0.1;
int score = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 499), "juegoSnake");

    Snake snake(sf::Vector2f(400, 300), sf::Color::Yellow);
    Mapa mapa(sf::Vector2f(400, 300), sf::Color::Black);
    Food food(sf::Vector2f(400, 300), sf::Color::Black);
    sf::Font font;
    Walls walls;
    Sounds sound;

    // Reloj
    sf::Clock clock;

    if (!font.loadFromFile("./assets/fonts/Minecraft.ttf"))
    {
        std::cerr << "Error al cargar la fuente" << std::endl;
        return -1;
    }

    sf::Text scoreText;
    scoreText.setFont(font);                  // Establecer la fuente
    scoreText.setCharacterSize(30);           // Tamaño del texto
    scoreText.setFillColor(sf::Color::White); // Color del texto
    scoreText.setPosition(25, 50);            // Posición del texto en la ventana
    // Crear paredes utilizando sf::RectangleShape

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Ver tiempo transcurrido
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        // Mover serpiente

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            snake.moveL(velocidad * -1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            snake.moveR(velocidad * 1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            snake.moveU(0, velocidad * -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            snake.moveD(0, velocidad * 1);
        }

        // Detectar colisiones con las paredes

        if (snake.DetectarColision(walls.techo.getGlobalBounds()))
        {
            std::cout << "Colision con techo" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(walls.piso.getGlobalBounds()))
        {
            std::cout << "Colision con piso" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(walls.paredIzquierda.getGlobalBounds()))
        {
            std::cout << "Colision con paredIzquierda" << std::endl;
            window.close();
        }
        if (snake.DetectarColision(walls.paredDerecha.getGlobalBounds()))
        {
            std::cout << "Colision con paredDerecha " << std::endl;
            window.close();
        }

        if (snake.DetectarColision(food.food.getGlobalBounds()))
        {
            std::cout << "Colision con  " << std::endl;
            food.food.setPosition(food.getRandomPosition(window, food.objectSize));
            score= score+10;;
            std::cout << "puntaje: " << score << std::endl;
            sound.sound.play();
            velocidad = velocidad + .1;
        }

        scoreText.setString("Score: " + std::to_string(score));

        // Actualizar mapa

        window.clear();

        snake.Update();
        mapa.draw(window);
        snake.draw(window);
        food.draw(window);
        window.draw(scoreText);

        // Dibujar las paredes

        window.display();
    }

    return 0;
}