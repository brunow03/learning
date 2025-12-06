#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>   // For rand()
#include <ctime>     // For seeding rand()
#include <cmath>     // For map-like function

// Utility function to mimic p5.js's map()
float mapValue(float value, float start1, float stop1, float start2, float stop2) {
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

float randomRange(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

class Drop {
public:
    float x, y, z, len, yspeed;

    Drop(float width, float height) {
        x = randomRange(0, width);
        y = randomRange(-500, -50);
        z = randomRange(0, 20);
        len = mapValue(z, 0, 20, 10, 20);
        yspeed = mapValue(z, 0, 20, 1, 20);
    }

    void fall(float height) {
        y += yspeed * 0.1f; // 40% of the original speed
        // y += yspeed;
        float grav = mapValue(z, 0, 20, 0, 0.05);  // gentler gravity
        // float grav = mapValue(z, 0, 20, 0, 0.2);
        yspeed += grav;

        if (y > height) {
            y = randomRange(-200, -100);
            yspeed = mapValue(z, 0, 20, 0.5, 7);  // slower initial speed
            // yspeed = mapValue(z, 0, 20, 4, 10);
        }
    }

    void show(sf::RenderWindow& window) {
        float thick = mapValue(z, 0, 20, 1, 3);
        sf::RectangleShape line(sf::Vector2f(thick, len));
        line.setPosition(x, y);
        line.setFillColor(sf::Color(138, 43, 226)); // Purple
        window.draw(line);
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int width = 640;
    const int height = 360;
    sf::RenderWindow window(sf::VideoMode(width, height), "Purple Rain");

    std::vector<Drop> drops;
    drops.reserve(500);
    for (int i = 0; i < 500; ++i) {
        drops.emplace_back(width, height);
    }

    sf::Color background(230, 230, 250); // Light lavender

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(background);

        for (auto& drop : drops) {
            drop.fall(height);
            drop.show(window);
        }

        window.display();
    }

    return 0;
}
