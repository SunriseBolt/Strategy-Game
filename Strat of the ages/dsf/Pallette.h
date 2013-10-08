
#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include "Button.h"

struct pallette
{
	IDirect3DTexture9* m_Texture;
	float Rot;
	float Scale;
	float mXloc;
	float mYloc;
	float mX;
	float mY;
	bool Visable;
	float m_FontLocX[10];
	float m_FontLocY[10];
	RECT Me;
	Button m_Button[10];
	ID3DXFont* m_Font;

	D3DXMATRIX m_Matrix;
	D3DXMATRIX m_MatrixRot;
	D3DXMATRIX m_MatrixTran;
	D3DXMATRIX m_MatrixTran2;
	D3DXMATRIX m_MatrixScale;

	void lerp(float x, float &xloc, float y, float &yloc, float inter){
		xloc = xloc + inter*(x-xloc);
		yloc = yloc + inter*(y-yloc);
	}

	void Draw(ID3DXSprite* m_pD3DSprite,D3DXIMAGE_INFO m_imageInfo){
		lerp(mX,mXloc,mY,mYloc,0.005f);


		D3DXMatrixTranslation(&m_MatrixTran2,mXloc ,mYloc ,0);
		D3DXMatrixRotationZ(&m_MatrixRot, Rot);
		D3DXMatrixScaling(&m_MatrixScale, Scale, Scale, 0);
		m_Matrix = (m_MatrixScale*m_MatrixRot*m_MatrixTran2);


		m_pD3DSprite->SetTransform(&m_Matrix);
		

	}

};