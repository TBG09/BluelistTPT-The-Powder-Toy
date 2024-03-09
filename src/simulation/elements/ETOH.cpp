#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_ETOH()
{
    Identifier = "BLUELIST_PT_ETOH";
    Name = "ETOH";
    Colour = PIXPACK(0xCDE1ED);
    MenuVisible = 1;
    MenuSection = SC_LIQUID;
    Enabled = 1;

    Advection = 0.6f;
    AirDrag = 0.01f * CFDS;
    AirLoss = 0.98f;
    Loss = 0.95f;
    Collision = 0.0f;
    Gravity = 0.1f;
    Diffusion = 0.00f;
    HotAir = 0.000f * CFDS;
    Falldown = 2;

    Flammable = 12;
    Explosive = 0;
    Meltable = 0;
    Hardness = 20;

    Weight = 30;

    DefaultProperties.temp = R_TEMP - 2.0f + 40.0f;
    HeatConduct = 4;
    Description = "sticky flammable element that burns slow and hot.";

    Properties = TYPE_LIQUID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_NEUTPASS;

    LowPressure = IPL;
    LowPressureTransition = NT;
    HighPressure = IPH;
    HighPressureTransition = NT;
    LowTemperature = 5.0f;
    LowTemperatureTransition = PT_ICEI;
    HighTemperature = 78.0f;
    HighTemperatureTransition = PT_FIRE;

    Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, rt;  // Declare 'rt' here
    for (rx = -1; rx < 2; rx++)
    {
        for (ry = -1; ry < 2; ry++)
        {
            if (BOUNDS_CHECK && (rx || ry))
            {
                r = pmap[y + ry][x + rx];
                if (!r)
                    continue;

                // Stickiness
                float dx = x - (x + rx);
                float dy = y - (y + ry);

                if ((dx * dx + dy * dy) > 1.5)
                {
                    float per, nd;
                    nd = dx * dx + dy * dy - 0.5;
                    per = 5.0f * (1.0f - parts[i].tmp / 100.0f) * (nd / (dx * dx + dy * dy + nd) - 0.5);
                    dx *= per;
                    dy *= per;
                    parts[i].vx += dx;
                    parts[i].vy += dy;

                    rt = TYP(r);  // Assign 'rt' the value of TYP(r)

                    // Check if 'rt' is a valid element type before accessing its properties
                    if (rt > 0 && rt < PT_NUM)
                    {
                        if ((sim->elements[rt].Properties & TYPE_PART) || rt == PT_GOO)
                        {
                            parts[ID(r)].vx -= dx;
                            parts[ID(r)].vy -= dy;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
