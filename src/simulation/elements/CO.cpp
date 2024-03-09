#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CO()
{
	Identifier = "BLUELIST_PT_CO";
	Name = "CO";
	Colour = PIXPACK(0x1A1A1A);
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 2.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.1f;
	Diffusion = 1.0f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 1;

	HeatConduct = 88;
	Description = "Carbon Monoxide, turns into a liquid at -192C.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 192.0f;
	LowTemperatureTransition = PT_LQCO;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;
}
