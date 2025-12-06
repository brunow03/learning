#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <random>

// Helper class for 2D vector math
class Vec2 {
public:
    float x, y;
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}
    Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
    Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }
    Vec2 operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
    Vec2& operator+=(const Vec2& other) { x += other.x; y += other.y; return *this; }
    float length() const { return std::sqrt(x*x + y*y); }
    Vec2 normalized() const { float len = length(); if (len > 0) return *this * (1.0f / len); return *this; }
};

// Boid class representing a single agent in the flock
class Boid {
public:
    Vec2 position;
    Vec2 velocity;
    Boid(float x, float y) : position(x, y) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1, 1);
        velocity = Vec2(dis(gen), dis(gen)).normalized() * 2.0f; // Random initial velocity
    }
    void update(const std::vector<Boid>& allBoids) {
        Vec2 alignment = computeAlignment(allBoids);
        Vec2 cohesion = computeCohesion(allBoids);
        Vec2 separation = computeSeparation(allBoids);
        // Apply weights to steering forces and update velocity
        velocity += alignment * 0.1f;
        velocity += cohesion * 0.01f;
        velocity += separation * 0.2f;
        // Limit speed and update position
        limitSpeed(2.0f);
        position += velocity;
    }
private:
    Vec2 computeAlignment(const std::vector<Boid>& allBoids) {
        Vec2 steer;
        int count = 0;
        for (const Boid& other : allBoids) {
            if (&other != this) {
                float dist = (position - other.position).length();
                if (dist < 100) { // Perception radius
                    steer += other.velocity;
                    count++;
                }
            }
        }
        if (count > 0) return (steer * (1.0f / count)).normalized();
        return steer;
    }
    Vec2 computeCohesion(const std::vector<Boid>& allBoids) {
        Vec2 center;
        int count = 0;
        for (const Boid& other : allBoids) {
            if (&other != this) {
                float dist = (position - other.position).length();
                if (dist < 100) {
                    center += other.position;
                    count++;
                }
            }
        }
        if (count > 0) return (center * (1.0f / count) - position).normalized();
        return center;
    }
    Vec2 computeSeparation(const std::vector<Boid>& allBoids) {
        Vec2 steer;
        for (const Boid& other : allBoids) {
            if (&other != this) {
                Vec2 diff = position - other.position;
                float dist = diff.length();
                if (dist > 0 && dist < 50) { // Separation radius
                    steer += diff.normalized() * (1.0f / dist); // Stronger when closer
                }
            }
        }
        return steer;
    }
    void limitSpeed(float maxSpeed) {
        float speed = velocity.length();
        if (speed > maxSpeed) velocity = velocity.normalized() * maxSpeed;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Boids Simulation");
    std::vector<Boid> boids;
    // Create initial flock
    for (int i = 0; i < 150; ++i) {
        boids.push_back(Boid(rand() % 1200, rand() % 800));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        // Update and draw boids
        window.clear();
        for (Boid& boid : boids) {
            boid.update(boids);
            // Simple triangle representation
            sf::ConvexShape triangle(3);
            triangle.setPoint(0, sf::Vector2f(5, 0));
            triangle.setPoint(1, sf::Vector2f(-5, -3));
            triangle.setPoint(2, sf::Vector2f(-5, 3));
            triangle.setPosition(boid.position.x, boid.position.y);
            // Rotate triangle to face velocity direction
            float angle = std::atan2(boid.velocity.y, boid.velocity.x) * 180 / 3.14159;
            triangle.setRotation(angle);
            triangle.setFillColor(sf::Color::White);
            window.draw(triangle);
        }
        window.display();
        sf::sleep(sf::milliseconds(16)); // ~60 FPS
    }
    return 0;
}