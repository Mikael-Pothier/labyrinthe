#pragma once
enum Orientation
{
	Nord, Sud, Est, Ouest, NB_DIRECTIONS;
};
Orientation PivoterGauche(const Orientation);
Orientation PivoterDroite(const Orientation);