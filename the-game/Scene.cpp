#include "Scene.h"

using namespace rtf;

Scene::Scene(int w, int h)
    : window_(sf::VideoMode(w, h), "SFML works!") {

  auto player = std::make_unique<Player>("res/wizard/wizard/idle_1.png");
  player->SetPosition(1000.f, 500.f);
  player_ = player.get();

  auto enemy = std::make_unique<Enemy>("res/knight/black_knight/idle_1.png");
  enemy->set_speed(0.7f);
  enemy->SetPosition(100.f, 100.f);
  enemy->set_target(player.get());

  
  auto enemy2 = std::make_unique<Enemy>("res/knight/bronze_knight/idle_3.png");
  enemy2->set_speed(0.7f);
  enemy2->SetPosition(1000.f, 100.f);
  enemy2->set_target(player.get());

  
  auto enemy3 = std::make_unique<Enemy>("res/knight/silver_knight/idle_2.png");
  enemy3->set_speed(0.7f);
  enemy3->SetPosition(1500.f, 1500.f);
  enemy3->set_target(player.get());
  
  AddObject(std::move(enemy));
  AddObject(std::move(enemy2));
  AddObject(std::move(enemy3));
  AddObject(std::move(player));
}

void Scene::Run() {
  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      // Window closed or escape key pressed: exit
      if ((event.type == sf::Event::Closed) ||
          ((event.type == sf::Event::KeyPressed) &&
           (event.key.code == sf::Keyboard::Escape))) {
        window_.close();
        break;
      }
      if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code)
        default:
          break;
      }
    }

    sf::Time elapsed = clock_.restart();

    player_->Controls(*this);

    for (auto it = objects_.begin(); it != objects_.end(); ++it) {
      for (auto it2 = std::next(it); it2 != objects_.end(); ++it2) {
        const bool isCollision = (*it)->Sprite().getGlobalBounds().intersects(
                (*it2)->Sprite().getGlobalBounds());
        if (isCollision) {
          GameObject::OnCollision(*(*it), *(*it2));
        }
      }
    }
    
    window_.clear();

    for (auto& obj : objects_) {
      obj->Update(&window_, elapsed);
    }

    window_.display();
  }
}

void Scene::AddObject(std::unique_ptr<GameObject> obj) { 
  objects_.push_back(std::move(obj));
}
