#pragma once

#include <cmath>

inline float randf(float min = 0.0f, float max = 1.0f)
{
    return min + (float)(rand())/((float)(RAND_MAX/(max-min)));
};

inline float randi(int min = 0, int max = 0)
{
    return min + rand()/(RAND_MAX/(max-min));
};

inline float distance(sf::Vector2f p1, sf::Vector2f p2)
{
    return sqrt(pow(fabs(p1.x-p2.x),2)+pow(fabs(p1.y-p2.y),2));
};

inline float degreesToRadians(float degrees)
{
    return degrees * M_PI / 180.0f;
};

inline sf::Vector2f unitVectorFromRadians(float radians)
{
    return sf::Vector2f(cos(radians), sin(radians));
};