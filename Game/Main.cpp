#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main(int argc, char argv[]) {

    sf::RenderWindow window(sf::VideoMode(500, 500), "GeneticGame");

    int n1 = 10;
    int n2 = 150;
    float column = 0;
    float row = 0;
    int sizefield = 50;

    std::vector<std::vector<sf::RectangleShape>> Field;
    

    for (int i = 0; i < sizefield; i++)
    {
        std::vector<sf::RectangleShape> vector;

        for (int j = 0; j < sizefield; j++)
        {
            int n = 0;
          
            sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));

            if ((i + j) % 2 == 0)
            {
                n = n1;
            }
            else if ((i + j) % 2 == 1)
            {
                n = n2;
            }

            rectangle.setFillColor(sf::Color(n, 50, 250));

            vector.push_back(rectangle);
        }

        Field.push_back(vector);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < sizefield; i++)
        {
            column = i * 10;

            for (int j = 0; j < sizefield; j++)
            {
                row = j * 10;
               
                Field[i][j].setPosition(column, row);
            }
        }

        window.clear();

        for (int i = 0; i < sizefield; i++)
        {
            for (int j = 0; j < sizefield; j++)
            {
                window.draw(Field[i][j]);
            }
        }

        window.display();
    }

	return EXIT_SUCCESS;
}