#pragma once
#include "TVector.h"
class Vector3 : public TVector {
	double x;
	double y;
	double z;

	double normalizeAndDot(TVector&);
public:
	Vector3();
	Vector3(int);
	double getElem(int);
	double getLength();
	bool isParalellTo(TVector&);
	bool isPerpendicularTo(TVector&);
	void operator+=(TVector&);
};

