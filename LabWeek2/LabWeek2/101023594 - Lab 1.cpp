#include <windows.h> // for XMVerifyCPUSupport
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <ctime>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;
//***************************************************************************
// 101023594 - Lab 1.cpp by Adam Vandyke (C) 2017 All Rights Reserved.
//
// Lab 1 submission.
//
// Description:
// Click run to see the results.
//
//*****************************************************************************

// Overload the  "<<" operators so that we can use cout to 
// output XMVECTOR and XMMATRIX objects.
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y <<
		", " << dest.z << ", " << dest.w << ")";
	return os;
}
ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]);
		os << endl;
	}

	return os;
}

int main()
{
	srand(time(NULL));
	// Check support for SSE2 (Pentium4, AMD K8, and above).
	if (!XMVerifyCPUSupport())
	{
		cout << "directx math not supported" << endl;
		return 0;
	}
	//--------------------
	float r1c1 = rand() % 9;
	float r1c2 = rand() % 9;
	float r1c3 = rand() % 9;
	float r1c4 = rand() % 9;
	//--------------------
	float r2c1 = rand() % 9;
	float r2c2 = rand() % 9;
	float r2c3 = rand() % 9;
	float r2c4 = rand() % 9;
	//--------------------
	float r3c1 = rand() % 9;
	float r3c2 = rand() % 9;
	float r3c3 = rand() % 9;
	float r3c4 = rand() % 9;
	//--------------------
	float r4c1 = rand() % 9;
	float r4c2 = rand() % 9;
	float r4c3 = rand() % 9;
	float r4c4 = rand() % 9;
	//--------------------

	XMMATRIX A(r1c1, r1c2, r1c3, r1c4,
		       r2c1, r2c2, r2c3, r2c4,
		       r3c1, r3c2, r3c3, r3c4,
		       r4c1, r4c2, r4c3, r4c4);

	cout << "Randomized matrix" << endl;
	cout << A << endl;
	XMVECTOR G = XMMatrixDeterminant(A);
	cout << G << endl;
	XMMATRIX B=(XMMatrixInverse(&G,A));
	cout << "Using XMMatrixInverse()" << endl;
	cout << endl;
	cout << B << endl;
	
	float D1 = r2c2*(r3c3*r4c4 - r3c4*r4c3) - r2c3*(r3c2*r4c4 - r3c4*r4c2) + r2c4*(r3c2*r4c3 - r3c3*r4c2);
	float D2 = r2c1*(r3c3*r4c4 - r3c4*r4c3) - r2c3*(r3c1*r4c4 - r3c4*r4c1) + r2c4*(r3c1*r4c3 - r3c3*r4c1);
	float D3 = r2c1*(r3c2*r4c4 - r3c4*r4c2) - r2c2*(r3c1*r4c4 - r3c4*r4c1) + r2c4*(r3c1*r4c2 - r3c2*r4c1);
	float D4 = r2c1*(r3c2*r4c3 - r3c3*r4c2) - r2c2*(r3c1*r4c3 - r3c3*r4c1) + r2c3*(r3c1*r4c2 - r3c2*r4c1);

	float Dm = r1c1*(D1) - r1c2*(D2) + r1c3*(D3) - r1c4*(D4);

	cout << "Without XMMatrixInverse()" << endl;
	cout << endl;

	//Calculating minors
	float b11 = (r2c2*r3c3*r4c4) + (r2c3*r3c4*r4c2) + (r2c4*r3c2*r4c3) - (r2c2*r3c4*r4c3) - (r2c3*r3c2*r4c4) - (r2c4*r3c3*r4c2);
	float b12 = (r1c2*r3c4*r4c3) + (r1c3*r3c2*r4c4) + (r1c4*r3c3*r4c2) - (r1c2*r3c3*r4c4) - (r1c3*r3c4*r4c2) - (r1c4*r3c2*r4c3);
    float b13 = (r1c2*r2c3*r4c4) + (r1c3*r2c4*r4c2) + (r1c4*r2c2*r4c3) - (r1c2*r2c4*r4c3) - (r1c3*r2c2*r4c4) - (r1c4*r2c3*r4c2);
	float b14 = (r1c2*r2c4*r3c3) + (r1c3*r2c2*r3c4) + (r1c4*r2c3*r3c2) - (r1c2*r2c3*r3c4) - (r1c3*r2c4*r3c2) - (r1c4*r2c2*r3c3);
    //*******
	float b21 = (r2c1*r3c4*r4c3) + (r2c3*r3c1*r4c4) + (r2c4*r3c3*r4c1) - (r2c1*r3c3*r4c4) - (r2c3*r3c4*r4c1) - (r2c4*r3c1*r4c3);
	float b22 = (r1c1*r3c3*r4c4) + (r1c3*r3c4*r4c1) + (r1c4*r3c1*r4c3) - (r1c1*r3c4*r4c3) - (r1c3*r3c1*r4c4) - (r1c4*r3c3*r4c1);
	float b23 = (r1c1*r2c4*r4c3) + (r1c3*r2c1*r4c4) + (r1c4*r2c3*r4c1) - (r1c1*r2c3*r4c4) - (r1c3*r2c4*r4c1) - (r1c4*r2c1*r4c3);
	float b24 = (r1c1*r2c3*r3c4) + (r1c3*r2c4*r3c1) + (r1c4*r2c1*r3c3) - (r1c1*r2c4*r3c3) - (r1c3*r2c1*r3c4) - (r1c4*r2c3*r3c1);
	//*******
	float b31 = (r2c1*r3c2*r4c4) + (r2c2*r3c4*r4c1) + (r2c4*r3c1*r4c2) - (r2c1*r3c4*r4c2) - (r2c2*r3c1*r4c4) - (r2c4*r3c2*r4c1);
	float b32 = (r1c1*r3c4*r4c2) + (r1c2*r3c1*r4c4) + (r1c4*r3c2*r4c1) - (r1c1*r3c2*r4c4) - (r1c2*r3c4*r4c1) - (r1c4*r3c1*r4c2);
	float b33 = (r1c1*r2c2*r4c4) + (r1c2*r2c4*r4c1) + (r1c4*r2c1*r4c2) - (r1c1*r2c4*r4c2) - (r1c2*r2c1*r4c4) - (r1c4*r2c2*r4c1);
	float b34 = (r1c1*r2c4*r3c2) + (r1c2*r2c1*r3c4) + (r1c4*r2c2*r3c1) - (r1c1*r2c2*r3c4) - (r1c2*r2c4*r3c1) - (r1c4*r2c1*r3c2);
	//*******
	float b41 = (r2c1*r3c3*r4c2) + (r2c2*r3c1*r4c3) + (r2c3*r3c2*r4c1) - (r2c1*r3c2*r4c3) - (r2c2*r3c3*r4c1) - (r2c3*r3c1*r4c2);
	float b42 = (r1c1*r3c2*r4c3) + (r1c2*r3c3*r4c1) + (r1c3*r3c1*r4c2) - (r1c1*r3c3*r4c2) - (r1c2*r3c1*r4c3) - (r1c3*r3c2*r4c1);
	float b43 = (r1c1*r2c3*r4c2) + (r1c2*r2c1*r4c3) + (r1c3*r2c2*r4c1) - (r1c1*r2c2*r4c3) - (r1c2*r2c3*r4c1) - (r1c3*r2c1*r4c2);
	float b44 = (r1c1*r2c2*r3c3) + (r1c2*r2c3*r3c1) + (r1c3*r2c1*r3c2) - (r1c1*r2c3*r3c2) - (r1c2*r2c1*r3c3) - (r1c3*r2c2*r3c1);

	XMMATRIX DMI((1 / Dm) * b11, (1 / Dm) * b12, (1 / Dm) * b13, (1 / Dm) * b14,
		(1 / Dm) * b21, (1 / Dm) * b22, (1 / Dm) * b23, (1 / Dm) * b24,
		(1 / Dm) * b31, (1 / Dm) * b32, (1 / Dm) * b33, (1 / Dm) * b34,
		(1 / Dm) * b41, (1 / Dm) * b42, (1 / Dm) * b43, (1 / Dm) * b44);

	cout << DMI << endl;
	system("pause");


	return 0;
} 


