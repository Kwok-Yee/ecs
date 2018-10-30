#pragma once
#include <vector>
#include <string>
#include "Component.h"

using namespace std;

class Entity
{
	int id;
public:
	Entity(string n) { name = n; };
	void addComponent(Component c) { components.push_back(c); };
	void removeComponent(Component c) { };
	vector<Component> getComponents() { return components; };
	string getName() { return name; };
private:
	vector<Component> components;
	string name;
};