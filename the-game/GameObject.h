#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace rtf {
class GameObject {
 public:
  enum class Tag {
    Unknown,
    Player,
    Enemy,
    Bullet
  };

 public:
  GameObject(const std::string& textureFile);
  virtual ~GameObject() {}

  GameObject(const GameObject& obj);
  GameObject& operator=(const GameObject& obj);

  void SetPosition(float x, float y);
  void SetPosition(const sf::Vector2f& pos);

  const sf::Sprite& Sprite() const { return sprite_; }

  void LoadNewTexture(const std::string& file);

  virtual void Draw(sf::RenderWindow* window);

  virtual void Update(sf::RenderWindow* window, sf::Time time);
  
  static void OnCollision(GameObject& a, GameObject& b);
  virtual void OnCollision(GameObject& obj);

  void set_tag(Tag tag) { tag_ = tag; }
  bool is(Tag tag) { return tag == tag_; }

 protected:
  static constexpr float SCALE_FACTOR = 0.5;
  Tag tag_ = Tag::Unknown;
  sf::Texture texture_;
  sf::Sprite sprite_;
};
}  // namespace rtf