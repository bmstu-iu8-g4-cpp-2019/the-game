#include "GameObject.h"

using namespace rtf;

GameObject::GameObject(const std::string& textureFile) {
  texture_.loadFromFile(textureFile);
  sprite_.setTexture(texture_);
  sprite_.setScale(SCALE_FACTOR, SCALE_FACTOR);
}

GameObject::GameObject(const GameObject& obj) {
  texture_ = obj.texture_;
  sprite_.setTexture(texture_);
  sprite_.setScale(obj.SCALE_FACTOR, obj.SCALE_FACTOR);
  SetPosition(obj.sprite_.getPosition());
  tag_ = obj.tag_;
}

GameObject& GameObject::operator=(const GameObject& obj) {
  if (&obj != this) {
    texture_ = obj.texture_;
    SetPosition(obj.sprite_.getPosition());
    sprite_.setTexture(texture_);
    sprite_.setScale(obj.SCALE_FACTOR, obj.SCALE_FACTOR);
    SetPosition(obj.sprite_.getPosition());
    tag_ = obj.tag_;
  }
  return *this;
}

void GameObject::SetPosition(float x, float y) { sprite_.setPosition(x, y); }

void GameObject::SetPosition(const sf::Vector2f& pos) {
  sprite_.setPosition(pos);
}

void GameObject::LoadNewTexture(const std::string& file) {
  texture_.loadFromFile(file);
}

void GameObject::Draw(sf::RenderWindow* window) { window->draw(sprite_); }

void GameObject::Update(sf::RenderWindow* window, sf::Time time) {
  Draw(window);
}

void rtf::GameObject::OnCollision(GameObject& a, GameObject& b) {
  a.OnCollision(b);
  b.OnCollision(a);
}

void rtf::GameObject::OnCollision(GameObject& obj) {}
