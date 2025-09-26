#include "../Nativite/Engine/Cluster/cluster.hpp"
#include <iostream>


int main() {
  Brain* brain = new Brain();
  brain->brain.push_back(nullptr);
  brain->brain.push_back(new Cluster());
  brain->brain.push_back(nullptr);
  brain->brain.push_back(nullptr);
  brain->brain.push_back(new Cluster());
  brain->brain.push_back(new Cluster());
  brain->brain.push_back(nullptr);
  std::cout << brain;
  delete brain;
  return 0;
}