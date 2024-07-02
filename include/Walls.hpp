#pragma once
#include <SFML/Graphics.hpp>


class Walls
{
public:

 sf::RectangleShape piso;
 sf::RectangleShape techo;
 sf::RectangleShape paredIzquierda;
 sf::RectangleShape paredDerecha;

public:


Walls(sf::Vector2f position, sf::Color color)
    {
       techo.setFillColor(sf::Color::Black);
       techo.setPosition(0.0f, 25.0f); 
    }
    // Crear paredes utilizando sf::RectangleShape
    
    // Pared superior
    Walls(){
    
    this-> techo= sf::RectangleShape (sf::Vector2f(640.0f, 10.0f));
    techo.setFillColor(sf::Color::Black);
    techo.setPosition(0.0f, 25.0f);
    
    // Pared inferior
    this-> piso = sf::RectangleShape (sf::Vector2f(800.0f, 10.0f));
    piso.setFillColor(sf::Color::Black);
    piso.setPosition(0.0f, 488.0f);

    // Pared izquierda
    this-> paredIzquierda =  sf::RectangleShape (sf::Vector2f(10.0f, 600.0f));
    paredIzquierda.setFillColor(sf::Color::Black);
    paredIzquierda.setPosition(5.0f, 25.0f);

    // Pared derecha
    this-> paredDerecha = sf::RectangleShape (sf::Vector2f(10.0f, 600.0f));
    paredDerecha.setFillColor(sf::Color::Black);
    paredDerecha.setPosition(627.0f, 25.0f);

    }
    
    void draw(sf::RenderWindow &window){
    window.draw(this ->techo);
    window.draw(this ->piso);
    window.draw(this ->paredDerecha);
    window.draw(this ->paredIzquierda);
    }
   
   
};


