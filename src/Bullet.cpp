#include "Bullet.h"

using namespace rtf;

Bullet::Bullet(const std::string& filename, sf::Vector2f start_position)
    : Movable(filename) {
  set_speed(2.f);
  SetPosition(start_position);
}