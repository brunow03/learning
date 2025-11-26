#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "DoublePendulum");
    window.setFramerateLimit(60);
    // std::cout << "Running..." << std::endl;

    float g, r1, r2, m1, m2, theta1, theta2, theta1_v, theta2_v, theta1_a, theta2_a, centerX, centerY, x1, y1, x2, y2;
    g = 10.f;
    float dt = 0.1f;    

    // first line
    sf::VertexArray line1(sf::Lines, 2); //or sf::LineStrip
    line1[0].color = sf::Color::White;
    line1[1].color = sf::Color::White;

    // second line
    sf::VertexArray line2(sf::Lines, 2); //or sf::LineStrip
    line2[0].color = sf::Color::White;
    line2[1].color = sf::Color::White;

    // first circle (pendulum pivot)
    sf::CircleShape circle1(10.f); // radius = 10 pixels
    circle1.setFillColor(sf::Color::White);
    
    // second circle
    sf::CircleShape circle2(10.f);
    circle2.setFillColor(sf::Color::White);

    // For tracing path
    sf::CircleShape dot(1.5f);
    dot.setOrigin(1.5f, 1.5f);
    dot.setFillColor(sf::Color(0, 255, 0, 180));
    std::vector<sf::CircleShape> trail;
    
    r1 = 100.0f;
    r2 = 100.0f;

    m1 = 10.0f;
    m2 = 10.0f;

    theta1 = M_PI / 2;
    theta2 = M_PI / 2 + 0.1f; // small offset for motion

    theta1_v = 0.f;
    theta2_v = 0.f;

    theta1_a = 0.f;
    theta2_a = 0.f;

    centerX = 400;
    centerY = 300;

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        theta1_a = (-g*(2*m1+m2)*sin(theta1) - m2*g*sin(theta1-2*theta2) - 2*sin(theta1-theta2)*m2*(theta2_v*theta2_v*r2+theta1_v*theta1_v*r1*cos(theta1-theta2)))/(r1*(2*m1+m2-m2*cos(2*theta1-2*theta2)));
        theta2_a = (2*sin(theta1-theta2)*(theta1_v*theta1_v*r1*(m1+m2)+g*(m1+m2)*cos(theta1)+theta2_v*theta2_v*r2*m2*cos(theta1-theta2)))/(r2*(2*m1+m2-m2*cos(2*theta1-2*theta2)));

        theta1_v += theta1_a * dt;
        theta2_v += theta2_a * dt;
        
        // theta1_v *= 0.999f;
        // theta2_v *= 0.999f;

        theta1 += theta1_v * dt;
        theta2 += theta2_v * dt;

        x1 = centerX + r1 * sin(theta1);
        y1 = centerY + r1 * cos(theta1);

        x2 = x1 + r2 * sin(theta2);
        y2 = y1 + r2 * cos(theta2);

        dot.setPosition(x2, y2);
        trail.push_back(dot);
        if (trail.size() > 2000) trail.erase(trail.begin());

        line1[0].position = sf::Vector2f(centerX, centerY);
        line1[1].position = sf::Vector2f(x1, y1);

        line2[0].position = sf::Vector2f(x1, y1); 
        line2[1].position = sf::Vector2f(x2, y2);

        circle1.setOrigin(10.f, 10.f);          // set origin to center
        circle1.setPosition(x1, y1);            // position at the pendulum end

        circle2.setOrigin(10.f, 10.f);
        circle2.setPosition(x2, y2);

        window.clear(sf::Color::Black);
        window.draw(line1);
        window.draw(line2);
        window.draw(circle1);
        window.draw(circle2);
        for (auto &d : trail) window.draw(d);
        
        window.display();

    }

    return 0;
}

