/****************************************************************************
 *
 * UMMSYStem
 *
 * Copyright (c) Motunabe2
 *
 * Library  : UMMLIB
 * Module   : Generic Game Components
 * File     : UMMGGC.h
 *
 ****************************************************************************/

 /* ëΩèdíËã`ñhé~					*/
 /* Prevention of redefinition	*/
#pragma once


class MonoLisic
{
public:
	virtual int Start();
	virtual int Update();
};

class BoxCollider2D : public MonoLisic
{
public:
	BoxCollider2D() { Start(); }
	int Start();
	int Update();
	bool CheckHit;
	int X, Y;
};

class Transform2D
{
public:
	Transform2D();
	int X, Y;
	int Rotate;
};

class Vector2 : public MonoLisic
{
public:
	int Update();
	int Start();

	float Strength;
	float X;
	float Y;
};

class GameObject : public MonoLisic , Transform2D
{
public:
	GameObject();
};