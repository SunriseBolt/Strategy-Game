
#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include "Button.h"
#include "Vector.h"
#include "Loc.h"
struct pallette
{
	static const long LocCount = 10000;
	IDirect3DTexture9** m_Textures;
	float Rot;
	float Scale;
	Loc Locs[LocCount];
	bool Visable;
	RECT Me;
	Button m_Button[10];
	ID3DXFont* m_Font;

	double DeltaX;
	double DeltaY;

	D3DXMATRIX m_Matrix;
	D3DXMATRIX m_MatrixRot;
	D3DXMATRIX m_MatrixTran;
	D3DXMATRIX m_MatrixTran2;
	D3DXMATRIX m_MatrixScale;

	void lerp(float x, float &xloc, float y, float &yloc, float inter){
		xloc = xloc + inter*(x-xloc);
		yloc = yloc + inter*(y-yloc);
	}

	pallette(){
		float Rot = 0;
		float Scale = 1;
		bool Visable = 1;

		 m_Matrix = D3DXMATRIX();
		 m_MatrixRot = D3DXMATRIX();
		 m_MatrixTran = D3DXMATRIX();
		 m_MatrixTran2 = D3DXMATRIX();
		 m_MatrixScale = D3DXMATRIX();
	}

	bool IsCursorOnMe(long aX, long aY){
		if(aX > Me.left && aX < Me.right && aY > Me.top && aY < Me.bottom){
			return true;
		}
		return false;
	}

	void Draw(ID3DXSprite* m_pD3DSprite,D3DXIMAGE_INFO m_imageInfo,IDirect3DTexture9* a_Textures, float Rot = 0,float Scale = 1){

		static unsigned int i = 0;
		Loc loc = Locs[i];
		lerp(loc.mx+DeltaX,loc.drwmx,loc.my+DeltaY,loc.drwmy,0.005f);
		Locs[i] = loc;
		if(this->IsCursorOnMe(loc.drwmx,loc.drwmy)){
			D3DXMatrixTranslation(&m_MatrixTran2,loc.drwmx ,loc.drwmy ,0);
			D3DXMatrixRotationZ(&m_MatrixRot, Rot);
			D3DXMatrixScaling(&m_MatrixScale, Scale, Scale, 0);
			m_Matrix = (m_MatrixScale*m_MatrixRot*m_MatrixTran2);

			m_pD3DSprite->SetTransform(&m_Matrix);
			m_pD3DSprite->Draw(a_Textures,0,&D3DXVECTOR3(0,0,0),&D3DXVECTOR3(0,0,0),D3DCOLOR(D3DCOLOR_ARGB(255,255,255,255)));
		}
		
		i++;
		if(i >= 10000)
			i = 0;
	}

};