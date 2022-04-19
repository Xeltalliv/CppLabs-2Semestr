#pragma once
#include "TVector.h"
class Vector2 : public TVector {
	double x;
	double y;

	double normalizeAndDot(TVector&);
public:
	Vector2();
	Vector2(int);
	double getElem(int);
	double getLength();
	bool isParalellTo(TVector&);
	bool isPerpendicularTo(TVector&);
	void operator+=(TVector&);
};

