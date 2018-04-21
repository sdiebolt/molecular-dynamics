// Copyright 2018 <Samuel Diebolt>

#pragma once

#include "particle.h"

class Event {
public:
  // Initializes a new event to occur at time t, involving particles a and b
  Event(double t, Particle* a, Particle* b);

  // > operator for the piority queue
  bool operator>(const Event& rhs) const;

  // Has any collision occurred between when event was created and now?
  bool IsValid();

  // Returns the time that event is scheduled to occur
  double GetTime() const;

  // Returns particle A
  Particle* GetParticleA() const;

  // Returns particle B
  Particle* GetParticleB() const;

private:
  // Time that event is scheduled to occur
  double time_;

  // Pointers to particles involved in event, possibly null
  Particle *a_, *b_;

  // Collision counts at event creation
  int collisions_count_a_, collisions_count_b_;
};
