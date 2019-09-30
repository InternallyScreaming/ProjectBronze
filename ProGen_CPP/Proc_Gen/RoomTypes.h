#include <vector>
using namespace std;

enum Directions {
	North = 1,
	South,
	East,
	West
};

enum Availability {
	NO = 0,
	YES
};
enum RoomTags {
	NEWS,
	NEW,
	NES,
	NWS,
	NE,
	NW,
	NS,
	N,
	EWS,
	EW,
	ES,
	E,
	WS,
	W,
	S,
};

bool roomTagComp(int roomTag);

class Vec2 {
public:
	int m_X;	//X coordinate
	int m_Y;	//Y coordinate

	~Vec2();	//destructor

	Vec2() {//default constructor
		m_X = 0;
		m_Y = 0;
	};		

	Vec2(int x, int y) {//constructor override
		m_X = x;
		m_Y = y;
	};	

	Vec2 operator=(Vec2 val) { // = operator override
		m_X = val.m_X;
		m_Y = val.m_Y;
		return *this;
	};	

	bool operator==(Vec2 val) { //== operator override
		if (m_X == val.m_X && m_Y == val.m_Y) {
			return true;
		}
		return false;
	};	
};

//Room Base Class
class Room {
protected: //switch to protected if inheritance does not work
	int m_doorNumbers;
	int m_doorsDir;

	bool m_nDoor, m_eDoor, m_sDoor, m_wDoor = NO;

	Vec2 m_spawnCoordinates;
	vector<Vec2> m_surroundingRooms;

	~Room() {};
	Room() {};

	Room(Vec2 coor) {
		Vec2 connections;

		m_spawnCoordinates = coor;

		if (m_nDoor == YES) {
			connections = coor;
			connections.m_Y--;// we decrease Y as the top of the console window is 0 and increases with each line
			m_surroundingRooms.push_back(connections);
		}
		if (m_eDoor == YES) {
			connections = coor;
			connections.m_X--;// we decrease X as the left side of the console window is 0 and increases as the cursor goes right
			m_surroundingRooms.push_back(connections);
		}
		if (m_wDoor == YES) {
			connections = coor;
			connections.m_X++;// we increase X as the left side of the console window is 0 and increases as the cursor goes right
			m_surroundingRooms.push_back(connections);

		}
		if (m_sDoor == YES) {
			connections = coor;
			connections.m_Y++;// we increase Y as the top of the console window is 0 and increases with each line
			m_surroundingRooms.push_back(connections);
		}
	};
};

//One Door Room Base Class
class OneDoor : public Room {
protected:
	~OneDoor(){};
	OneDoor() {
		m_doorNumbers = 1;
	}
	OneDoor(/*int connect, */Vec2 coor) : Room(coor) {
		m_doorNumbers = 1;

		//switch (connect) {
		//case N:
		//	break;
		//case E:
		//	break;
		//case W:
		//	break;
		//case S:
		//	break;
		//}
	}
};
//Specific One Door Rooms
//North
class od_N : public OneDoor {
protected:
	~od_N() {};
	od_N() : OneDoor(){};
	od_N(Vec2 coor) : OneDoor(coor) {
		m_doorsDir = N;
		m_nDoor = YES;
	};
};
//East
class od_E : public OneDoor {
protected:
	~od_E() {};
	od_E() : OneDoor() {};
	od_E(Vec2 coor) : OneDoor(coor) {
		m_doorsDir = E;
		m_eDoor = YES;
	};
};
//West
class od_W : public OneDoor {
protected:
	~od_W() {};
	od_W() : OneDoor() {};
	od_W(Vec2 coor) : OneDoor(coor) {
		m_doorsDir = W;
		m_wDoor = YES;
	};
};
//South
class od_S : public OneDoor {
protected:
	~od_S() {};
	od_S() : OneDoor() {};
	od_S(Vec2 coor) : OneDoor(coor) {
		m_doorsDir = S;
		m_sDoor = YES;
	};
};

//Two Door Room Base Class
class TwoDoor : public Room {
protected:
	~TwoDoor() {};
	TwoDoor() {
		m_doorNumbers = 2;
	}
	TwoDoor(Vec2 coor) : Room(coor) {
		m_doorNumbers = 2;
	}
};

//HALLWAYS
//North South
class hall_NS : public TwoDoor {
protected:
	~hall_NS() {};
	hall_NS() : TwoDoor() {};
	hall_NS(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = NS;
		m_nDoor = YES;
		m_sDoor = YES;
	};
};

//East West
class hall_EW : public TwoDoor {
protected:
	~hall_EW() {};
	hall_EW() : TwoDoor() {};
	hall_EW(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = EW;
		m_eDoor = YES;
		m_wDoor = YES;
	};
};

//CORNERS
//North East
class corn_NE : public TwoDoor {
protected:
	~corn_NE() {};
	corn_NE() : TwoDoor() {};
	corn_NE(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = NE;
		m_nDoor = YES;
		m_eDoor = YES;
	};
};

//North West
class corn_NW : public TwoDoor {
protected:
	~corn_NW() {};
	corn_NW() : TwoDoor() {};
	corn_NW(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = NW;
		m_nDoor = YES;
		m_wDoor = YES;
	};
};

//East South
class corn_ES : public TwoDoor {
protected:
	~corn_ES() {};
	corn_ES() : TwoDoor() {};
	corn_ES(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = ES;
		m_eDoor = YES;
		m_sDoor = YES;
	};
};
//West South
class corn_WS : public TwoDoor {
protected:
	~corn_WS() {};
	corn_WS() : TwoDoor() {};
	corn_WS(Vec2 coor) : TwoDoor(coor) {
		m_doorsDir = WS;
		m_wDoor = YES;
		m_sDoor = YES;
	};
};



//Three Door Room Base Class
class ThreeDoor : public Room {
protected:
	~ThreeDoor() {};
	ThreeDoor() {
		m_doorNumbers = 3;
	}
	ThreeDoor(Vec2 coor) : Room(coor) {
		m_doorNumbers = 3;
	}
};


//North East West
class con_NEW : public ThreeDoor {
protected:
	~con_NEW() {};
	con_NEW() : ThreeDoor() {};
	con_NEW(Vec2 coor) : ThreeDoor(coor) {
		m_doorsDir = NEW;
		m_nDoor = YES;
		m_eDoor = YES;
		m_wDoor = YES;
	};
};

//North East South
class con_NES : public ThreeDoor {
protected:
	~con_NES() {};
	con_NES() : ThreeDoor() {};
	con_NES(Vec2 coor) : ThreeDoor(coor) {
		m_doorsDir = NES;
		m_nDoor = YES;
		m_eDoor = YES;
		m_sDoor = YES;
	};
};

//North West South
class con_NWS: public ThreeDoor {
protected:
	~con_NWS() {};
	con_NWS() : ThreeDoor() {};
	con_NWS(Vec2 coor) : ThreeDoor(coor) {
		m_doorsDir = NWS;
		m_nDoor = YES;
		m_wDoor = YES;
		m_sDoor = YES;
	};
};


//East West South
class con_EWS : public ThreeDoor {
protected:
	~con_EWS() {};
	con_EWS() : ThreeDoor() {};
	con_EWS(Vec2 coor) : ThreeDoor(coor) {
		m_doorsDir = EWS;
		m_eDoor = YES;
		m_wDoor = YES;
		m_sDoor = YES;
	};
};

//Four Door Room Base Class
class FourDoor : public Room {
protected:
	~FourDoor() {};
	FourDoor() {
		m_doorNumbers = 4;
	}
	FourDoor(Vec2 coor) : Room(coor) {
		m_doorNumbers = 4;
		m_doorsDir = NEWS;
		m_nDoor, m_eDoor, m_wDoor, m_sDoor = YES;
	}
};


bool roomTagComp(int roomTag) {

}