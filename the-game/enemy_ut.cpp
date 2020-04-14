#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"

#include <gtest/gtest.h>

TEST(Enemy, Collision) {

  rtf::Enemy e("");
  rtf::Enemy e2("");
  rtf::Bullet b("", {});
  rtf::Player p("");

  rtf::GameObject::OnCollision(e, e2);
  EXPECT_TRUE(e.is_alive());
  EXPECT_TRUE(e2.is_alive());

  rtf::GameObject::OnCollision(e, p);
  EXPECT_TRUE(e.is_alive());
  
  rtf::GameObject::OnCollision(e, b);
  EXPECT_FALSE(e.is_alive());
}