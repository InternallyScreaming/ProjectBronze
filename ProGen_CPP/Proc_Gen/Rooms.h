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


	Vec2 m_spawnCoordinates;
	Vec2 m_N;
	Vec2 m_E;
	Vec2 m_W;
	Vec2 m_S;

	~Room() {};
	Room() {};

	Room(int doorAmount, int connect, Vec2 coor) {
		m_doorNumbers = doorAmount;
		m_spawnCoordinates = coor;
		m_doorsDir = connect;

		if (connect == NEWS || connect == NEW || connect == NES || connect == NWS || connect == NE || connect == NW || connect == NS || connect == N) {
			m_N = m_spawnCoordinates;
			m_N.m_Y--; //subtract since the top left corner is 0,0
		}
		if (connect == NEWS || connect == NEW || connect == NES || connect == NE || connect == EWS || connect == EW || connect == ES || connect == E) {
			m_E = m_spawnCoordinates;
			m_E.m_X--;
		}
		if (connect == NEWS || connect == NEW || connect == NWS || connect == NW || connect == EWS || connect == EW || connect == WS || connect == W) {
			m_W = m_spawnCoordinates;
			m_E.m_X++;
		}
		if (connect == NEWS || connect == NES || connect == NWS || connect == NS || connect == EWS || connect == ES || connect == WS || connect == S) {
			m_S = m_spawnCoordinates;
			m_N.m_Y++;
		}
		

	};
};



//Specific One Door Rooms
//North
class od_N : public Room {
protected:
	~od_N(){};
	od_N(int doorAmount, int connect, Vec2 coor) : Room(doorAmount, connect, coor) {};
};

//East
class od_E : public Room {
protected:
	~od_E() {};
	od_E(int doorAmount, int connect, Vec2 coor) : Room(doorAmount, connect, coor) {};
};
//West
class od_W : public Room {
protected:
	~od_W() {};
	od_W(int doorAmount, int connect, Vec2 coor) : Room(doorAmount, connect, coor) {};
};
//South
class od_S : public Room {
protected:
	~od_S() {};
	od_S(int doorAmount, int connect, Vec2 coor) : Room(doorAmount, connect, coor) {};
};

////HALLWAYS
////North South
//class hall_NS : public TwoDoor {
//protected:
//	~hall_NS() {};
//	hall_NS() : TwoDoor() {};
//	hall_NS(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = NS;
//	};
//};
//
////East West
//class hall_EW : public TwoDoor {
//protected:
//	~hall_EW() {};
//	hall_EW() : TwoDoor() {};
//	hall_EW(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = EW;
//	};
//};
//
////CORNERS
////North East
//class corn_NE : public TwoDoor {
//protected:
//	~corn_NE() {};
//	corn_NE() : TwoDoor() {};
//	corn_NE(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = NE;
//	};
//};
//
////North West
//class corn_NW : public TwoDoor {
//protected:
//	~corn_NW() {};
//	corn_NW() : TwoDoor() {};
//	corn_NW(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = NW;
//	};
//};
//
////East South
//class corn_ES : public TwoDoor {
//protected:
//	~corn_ES() {};
//	corn_ES() : TwoDoor() {};
//	corn_ES(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = ES;
//	};
//};
////West South
//class corn_WS : public TwoDoor {
//protected:
//	~corn_WS() {};
//	corn_WS() : TwoDoor() {};
//	corn_WS(Vec2 coor) : TwoDoor(coor) {
//		m_doorsDir = WS;
//	};
//};
//
//
//
////Three Door Room Base Class
//class ThreeDoor : public Room {
//protected:
//	~ThreeDoor() {};
//	ThreeDoor() {
//		m_doorNumbers = 3;
//	}
//	ThreeDoor(Vec2 coor) : Room(coor) {
//		m_doorNumbers = 3;
//	}
//};
//
//
////North East West
//class con_NEW : public ThreeDoor {
//protected:
//	~con_NEW() {};
//	con_NEW() : ThreeDoor() {};
//	con_NEW(Vec2 coor) : ThreeDoor(coor) {
//		m_doorsDir = NEW;
//	};
//};
//
////North East South
//class con_NES : public ThreeDoor {
//protected:
//	~con_NES() {};
//	con_NES() : ThreeDoor() {};
//	con_NES(Vec2 coor) : ThreeDoor(coor) {
//		m_doorsDir = NES;
//	};
//};
//
////North West South
//class con_NWS : public ThreeDoor {
//protected:
//	~con_NWS() {};
//	con_NWS() : ThreeDoor() {};
//	con_NWS(Vec2 coor) : ThreeDoor(coor) {
//		m_doorsDir = NWS;
//	};
//};
//
//
////East West South
//class con_EWS : public ThreeDoor {
//protected:
//	~con_EWS() {};
//	con_EWS() : ThreeDoor() {};
//	con_EWS(Vec2 coor) : ThreeDoor(coor) {
//		m_doorsDir = EWS;
//	};
//};
//
////Four Door Room Base Class
//class FourDoor : public Room {
//protected:
//	~FourDoor() {};
//	FourDoor() {
//		m_doorNumbers = 4;
//	}
//	FourDoor(Vec2 coor) : Room(coor) {
//		m_doorNumbers = 4;
//		m_doorsDir = NEWS;
//	}
//};
//
//
//bool roomTagComp(int roomTag) {
//
//}
