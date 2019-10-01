#pragma once
#include <vector>

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


class Room {
protected: //switch to protected if inheritance does not work
	int m_doorNumbers;
	int m_doorPos;


	Vec2 m_spawnCoordinates;
	Vec2 m_N;
	Vec2 m_E;
	Vec2 m_W;
	Vec2 m_S;

	~Room() {};
	Room() {};
	Room(int _doorNumbers, int _doorPos, Vec2 _spawnCoordinates) {
		m_doorNumbers = _doorNumbers;
		m_spawnCoordinates = _spawnCoordinates;
		m_doorPos = _doorPos;
	};
};

class North : public Room {
protected:

	~North() {};
	North() : m_doorNumbers(1), m_doorPos(N) {};
};

////East
//class E : public Room {
//protected:
//	~od_E() {};
//};
////West
//class od_W : public Room {
//protected:
//	~od_W() {};
//};
////South
//class od_S : public Room {
//protected:
//	~od_S() {};
//};