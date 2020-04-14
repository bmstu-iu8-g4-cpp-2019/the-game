#include "Bullet.h"

using namespace rtf;

Bullet::Bullet(const std::string& filename, sf::Vector2f start_position)
    : Moveable(filename) {
  set_speed(2.f);
  SetPosition(start_position);

  set_tag(Tag::Bullet);
}