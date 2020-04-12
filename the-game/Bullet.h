#pragma once

#include "Moveable.h"

namespace rtf {

class Bullet : public Moveable {
 public:
  Bullet(const std::string& filename, sf::Vector2f start_position);
};

}  // namespace rtf