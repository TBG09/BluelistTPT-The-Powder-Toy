#include "simulation/ToolCommon.h"
#include "simulation/Air.h"

static int perform(Simulation * sim, Particle * cpart, int x, int y, int brushX, int brushY, float strength);

void SimTool::Tool_INVC()
{
	Identifier = "BLUELIST_PT_INVC";
	Name = "INVC";
	Colour = PIXPACK(0x303030);
	Description = "Vacuum, reduces air pressure by 10x.";
	Perform = &perform;
}

static int perform(Simulation * sim, Particle * cpart, int x, int y, int brushX, int brushY, float strength)
{
	sim->air->pv[y/CELL][x/CELL] -= strength*10.0f;

	if (sim->air->pv[y/CELL][x/CELL] > MAX_PRESSURE)
		sim->air->pv[y/CELL][x/CELL] = MAX_PRESSURE;
	else if (sim->air->pv[y/CELL][x/CELL] < MIN_PRESSURE)
		sim->air->pv[y/CELL][x/CELL] = MIN_PRESSURE;
	return 1;
}
