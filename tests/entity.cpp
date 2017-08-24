#include "catch.hpp"

#include "Entity.h"
#include "GameValues.h"
#include "utils.h"

TEST_CASE("entities move", "[entity move]") {
    const float velocity = 5.0f;
    Entity entity;
    entity.setPosition(sf::Vector2f(GAME_BOUNDS_X / 2, GAME_BOUNDS_Y / 2));
    entity.setVelocity(velocity);
    auto initialPosition = entity.getPosition();
    auto initialRotation = entity.getRotation();
    auto unitVector = unitVectorFromRadians(degreesToRadians(initialRotation));
    auto velocityVector = unitVector * velocity;
    auto newPosition = initialPosition + velocityVector;
    entity.update();
    REQUIRE(entity.getPosition() == newPosition);
}