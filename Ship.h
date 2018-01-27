#include <math.h>
#include <string>
#include "Crewman.h"

using std::string;

#ifndef SHIP_H
#define SHIP_H
enum Maneuverability {
	CLUMSY,
	POOR,
	AVERAGE,
	GOOD,
	PERFECT
};

enum Modifier : int	// list of indices for the Modifiers table on each ship 
{

};

enum Orientation : int
{
    EAST,
    SOUTHEAST,
    SOUTHWEST,
    WEST,
    NORTHWEST,
    NORTHEAST
};

enum Station : int
{
	Captain,
	Pilot,
	Gunner,
	Science,
	Engineering
};


class Ship
{
private:
	// Non-changing fields
	string name;				// 
	float tier;					// 
	int size;					// 
	int speed;					// 
	Maneuverability maneuv;		// 
	float driftRating;			// 
	int armourClass;			// 
	int targetLock;				// 
	int damageThreshold;		// 
	int criticalThreshold;		// 
	string* systems;			// 
	string* expansionBays;		// 

	int minCrew;				// 
	int maxCrew;				// 

	int modifiers[10];			// modifiers active on ship


	// Fields with current/max values
	int hullPointsMax;			// 
	int hullPointsCur;			// 

	int shieldTot[4];			// 
	int shieldCur[4];			// 

	int powerCoreTot;			// 
	int powerCoreAvl;			// 

	// fields with single value that may change

	Crewman* crewmen[5];		// 
	string* specialAbilities;	// 
	int cost;

    // Graphics
    int x_pos;
    int y_pos;

    Orientation orientation;

public:

	int getCost();								// 
	void setCost(int);							// 
	int calculateCost(float);					// 

	int getMinCrew();							// 
	void setMinCrew(int);						// 
		
	int getMaxCrew();							// 
	void setMaxCrew(int);						// 

	int setModifier(Modifier, bool);			// 
	bool getModifierIsActive(Modifier);			// 
	int* getModifiers();						// 

	int getHullPointsMax();						// 
	void setHullPointsMax(int);					// 
		
	int getPowerCoreTotal();					// 
	void setPowerCoreTotal(int);				// 

	Crewman* getCrewman(Station);				// 
	void assignCrewman(Crewman*, Station);		// 

	string getName();							// 
	void setName(string);						// 
	
	float getTier();							// 
	void setTier(float);						// 
	
	int getSize();								// 
	void setSize(int);							// 
	
	int getSpeed();								// 
	void setSpeed(int);							// 
	
	Maneuverability getManeuverability();		// 
	void setManeuverability(Maneuverability);	// 
	
	float getDriftRating();						// 
	void setDriftRating(float);					// 
	
	int getArmourClass();						// 
	void setArmourClass(int);					// 
	
	int getTargetLock();						// 
	void setTargetLock(int);					// 

	int getDamageThreshold();					// 
	void setDamageThreshold(int);				// 

	string getSystems();						// 
	void addSystem(string);						// 

	string getExpansionBays();					// 
	void addExpansionBay(string);				// 

    int getXpos();
    void setXpos(int);

    int getYpos();
    void setYpos(int);

    Orientation getOrientation();
    void setOrientation(Orientation);
};

#endif