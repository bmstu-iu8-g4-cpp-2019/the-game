#pragma once

#include "Movable.h"

namespace rtf {

class Bullet : public Movable {
 public:
  Bullet(const std::string& filename, sf::Vector2f start_position);
};

}  // namespace rtf