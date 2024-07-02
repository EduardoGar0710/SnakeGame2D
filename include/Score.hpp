#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Contador
{
private:
    int score = 0;

public:
    void Contar()
    {
        score++;
    };
};