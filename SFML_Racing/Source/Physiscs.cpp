#include "Physics.hpp"




sf::Vector2f Physics::UpdatePos(float dt)
{
	//Find the locations of the wheels
	sf::Vector2f frontWheel = m_pos + M_WHEELBASE / 2 * sf::Vector2f(cos(Angle()), sin(Angle()));
	sf::Vector2f reerWheel  = m_pos - M_WHEELBASE / 2 * sf::Vector2f(cos(Angle()), sin(Angle()));

	frontWheel += Velocity() * dt * sf::Vector2f(cos(Angle() + m_steerAngle), sin(Angle() + m_steerAngle));
	reerWheel += m_vel * dt;

	m_pos = (frontWheel + reerWheel) / 2.0f;
	return m_pos;
}
float Physics::UpdateAng(float dt)
{
	return Angle() * 180 / PI;
}

void Physics::TurnCar(float ang)
{
	m_steerAngle = ang;
}
void Physics::DriveForce(float force)
{
	m_acc = ForceDrive() / m_mass * sf::Vector2f(cos(Angle()), sin(Angle()));
}

float Physics::ForceDrive()
{
	return m_engTorque*m_gearRatio*m_diffRatio*m_tranEff / M_WHEELR;
}
float Physics::ForceTraction()
{
	return 1;
}
float Physics::ForceBraking()
{
	if (Velocity() > 0)
	{
		return -C_BRAKE;
	}
	else
	{
		return 0;
	}
}
float Physics::ForceDrag()
{
	//Force equation for drag
	return 0.5*C_DRAG*M_AREA*RHO_AIR*Velocity()*Velocity();
}
float Physics::ForceRR()
{
	return 30 * ForceDrag();
}