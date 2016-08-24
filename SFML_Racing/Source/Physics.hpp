#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

//physics works on a local axis
//x is forward of the object
//y is side to side
class Physics
{
public:

	Physics()
	{
		m_pos = sf::Vector2f(0,0);
	}

	void TurnCar(float ang);
	void DriveForce(float force);
	
	sf::Vector2f UpdatePos(float dt);
	float UpdateAng(float dt);

private:
	float ForceTraction();
	float ForceDrive();
	float ForceBraking();
	float ForceDrag();
	float ForceRR();

	//Speed of the car
	float Velocity() { return sqrt(m_vel.x*m_vel.x + m_vel.y*m_vel.y); }
	float Angle() { if (m_vel.x == 0) return PI/2; else return atan(m_vel.y / m_vel.x); }

private:
	sf::Vector2f m_acc;
	sf::Vector2f m_vel;
	sf::Vector2f m_pos;

	float m_steerAngle = 0;

	//Variables for drive force
	float m_engTorque = 450; //N*m
	float m_gearRatio = 2.66;
	float m_diffRatio = 3.42;
	float m_tranEff = 0.7;
	float const M_WHEELR = 0.34; // m
	float const M_WHEELBASE = 2; // m

	//Constants for drag coef
	float const m_mass = 1500; //kg
	float const C_DRAG = 0.30; //u
	float const M_AREA = 2.2; //m^2
	float const RHO_AIR = 1.29; //kg/m^3

	float const C_BRAKE = 20;

	float const PI = 3.1415926535;

	float xAcc = 0;
	float yAcc = 0;
	float xSpd = 0;
	float ySpd = 0;
};
