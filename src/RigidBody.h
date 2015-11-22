#pragma once

#include "src/Particle.h"
#include "util/tiny_obj_loader.h"
#include <vector>
#include <string>


using namespace std;

class RigidBody
{
protected:
	glm::ivec3 m_resolution;
	float m_grid_length;

	glm::vec3 m_min;
	glm::vec3 m_max;

	//obj geometry
	vector<tinyobj::shape_t> m_shapes;
	vector<tinyobj::material_t> m_materials;

	// obj init transformation
	// 
	glm::vec3 m_scale;
	glm::vec3 m_translate;
	glm::mat4 m_rotation;

	// obj init velocity
	glm::vec3 m_init_velocity;

	// obj particle mass scale
	float m_mass_scale;

	// obj phase (group id)
	int m_phase;

public:
	//particle
	vector<Particle> m_particles;
	vector<float> m_particle_pos;


	RigidBody();



	//getter methods
	float getGridLength(){ return m_grid_length; }
	glm::mat4 getTransformMatrix();



	//init operations
	bool initObj(const string & filename);

	void initBoundingBox();

	//Call this after Obj is loaded
	void initParticles(int x_res);
	void initParticles(float grid_size);

	
	void setScale(glm::vec3 scale);
	void setTranslate(glm::vec3 translate);
	void setRotation(glm::mat4 rot);
	//void setTransform(glm::mat4 mat);

	void setMassScale(float);

	void setInitVelocity(glm::vec3);

	void setPhase(int);

	
};