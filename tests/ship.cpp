#include "catch.hpp"

#include "utils.h"
#include "Ship.h"
#include "GameValues.h"

TEST_CASE("ships can move and turn", "[ship controls]" ) {
    Ship ship;
    ship.setPosition(sf::Vector2f(GAME_BOUNDS_X/2, GAME_BOUNDS_Y/2));
    auto initialPosition = ship.getPosition();
    auto initialRotation = ship.getRotation();
    SECTION("ship move") {
        auto unitVector = unitVectorFromRadians(degreesToRadians(initialRotation));
        auto velocityVector = unitVector * (float)SHIP_VELOCITY;
        SECTION("move forward") {
            SECTION("start forward") {
                auto newPosition = initialPosition + velocityVector;
                ship.setMoveForward(true);
                ship.update();
                REQUIRE(ship.getVelocity() == SHIP_VELOCITY);
                REQUIRE(ship.getPosition() == newPosition);
            }
            SECTION("stop forward") {
                ship.setMoveForward(false);
                ship.update();
                REQUIRE(ship.getVelocity() == 0);
                REQUIRE(ship.getPosition() == initialPosition);
            }
        }
        SECTION("move backward") {
            SECTION("start backward") {
                auto newPosition = initialPosition - velocityVector;
                ship.setMoveBackward(true);
                ship.update();
                INFO("Ship position is (" << ship.getPosition().x << "," << ship.getPosition().y << ")");
                INFO("Expected position is (" << newPosition.x << "," << newPosition.y << ")");
                REQUIRE(ship.getVelocity() == -SHIP_VELOCITY);
                REQUIRE(ship.getPosition() == newPosition);
            }
            SECTION("stop backward") {
                ship.setMoveBackward(false);
                ship.update();
                REQUIRE(ship.getVelocity() == 0);
                REQUIRE(ship.getPosition() == initialPosition);
            }
        }
    }
    SECTION("turn left") {
        SECTION("start left") {
            ship.setTurnLeft(true);
            ship.update();
            REQUIRE(ship.getRotation() == initialRotation - SHIP_TURN_SPEED);
        }
        SECTION("stop left") {
            ship.setTurnLeft(false);
            ship.update();
            REQUIRE(ship.getRotation() == initialRotation);
        }
    }
    SECTION("turn right") {
        SECTION("start right") {
            ship.setTurnRight(true);
            ship.update();
            REQUIRE(ship.getRotation() == initialRotation + SHIP_TURN_SPEED);
        }
        SECTION("stop right") {
            ship.setTurnRight(false);
            ship.update();
            REQUIRE(ship.getRotation() == initialRotation);
        }
    }
}