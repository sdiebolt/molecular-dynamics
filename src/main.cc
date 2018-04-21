// Copyright 2018 <Samuel Diebolt>

#include <iostream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "main.h"
#include "particle.h"
#include "collisionSystem.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Please enter the number of particles to simulate.\n");
    return 1;
  }

  std::istringstream ss {argv[1]};
  int n {0};
  if (!(ss >> n)) {
    std::cerr << "Invalid number " << argv[1] << '\n';
    return 1;
  }

  // Initialization of the particles collection
  std::vector<Particle>* particles = new std::vector<Particle>();
  for (auto i {1}; i < n + 1; i++) {
    particles->push_back(Particle(i * 0.01, i * 0.05, 0.005, 0.005, 0.01, 0.5, sf::Color::Black));
    (*particles)[i].Print();
  }

  // Initialization of the collision system
  const int limit {1000};
  CollisionSystem* system = new CollisionSystem {particles, limit};

  // Initialization of the simulation
  system->Simulate(limit);

  delete particles;
  delete system;

  return 0;
}
