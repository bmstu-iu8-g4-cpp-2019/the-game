#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace rtf {
class GameObject {
 public:
  GameObject(const std::string& textureFile);

  GameObject(const GameObject& obj);
  GameObject& operator=(const GameObject& obj);

  void SetPosition(float x, float y);
  void SetPosition(const sf::Vector2f& pos);

  const sf::Sprite& Sprite() const { return sprite_; }

  void LoadNewTexture(const std::string& file);

  virtual void Draw(sf::RenderWindow* window);

  virtual void Update(sf::RenderWindow* window, sf::Time time);

 protected:
  static constexpr float SCALE_FACTOR = 0.5;

  sf::Texture texture_;
  sf::Sprite sprite_;
};
}  // namespace rtf