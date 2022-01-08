#pragma once

#include <SFML/Graphics.hpp>
#include "Particle.h"

#define CHUNK_NB 4 // separating particles in smaller chunks to avoid having HUGE arrays (1 billion particles) : else we might face stack overflow or framerate drops. To understand the code faster, you can think that CHUNK_NB = 1
#define VERTEX_CHUNK 500000 // how much particles are in each chunk

using namespace std;
using namespace sf;

class Param
{
public:
	Param();
	Param(int _nb, vector<Particle>* _particles, float* _dt, bool* _LMB, Vector2f* _mousePos);
	void SetParam(int _nb, vector<Particle>* _particles, float* _dt, bool* _LMB, Vector2f* _mousePos);
	int nb;
	vector<Particle>* particles;
	float* dt;
	bool* LMB;
	Vector2f* mousePos;
};

