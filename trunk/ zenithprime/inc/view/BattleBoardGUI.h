#pragma once
#include <windows.h> // this is required for it to work on visual studio 2010
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <vector>
#include "BBModel.h"
#include "Matrix.h"
#include "Mouse.h"


class BattleBoardView;

class BattleBoardController : public MouseListener{
  public:
      //BattleBoardView* view;
      BBModel* model;

      BattleBoardController(BBModel* model);
   

    void updateCamera();

	void setCamera(float sourceX, float sourceY, float sourceZ,float targetX, float targetY, float targetZ, float up_x , float up_y, float up_z);
	void setCameraTarget(float targetX, float targetY, float targetZ);
	void setCameraSource(float sourceX, float sourceY, float sourceZ);
	void setCameraUp(float up_x , float up_y, float up_z);

	void moveCamera(float deltaX, float deltaY, float deltaZ);
	void zoomCamera(float zoom);
	void rotateCamera(float rotateX, float rotateY);

	void enablePrespective();

	void setMouseEnabled(bool enabled);
	bool isMouseEnabled();

    virtual void mouseMoved(int targetX, int targetY);
	virtual void mouseDragged(int targetX, int targetY, int buttons);
	virtual void mousePressed(int targetX, int targetY, int buttons);
	virtual void mouseReleased(int targetX, int targetY, int buttons);
	virtual void mouseClicked(int targetX, int targetY, int buttons);
	virtual void mouseDoubleClicked(int targetX, int targetY, int buttons);
	virtual void mouseWheel(int targetX, int targetY, int delta);

private:
	
	float X, Y, Z;
	float srcX, srcY, srcZ;
    float rotateX, rotateY;
    float zoom;
	float upX;
	float upY;
	float upZ;

	float MAX_ZOOM;
	float MIN_ZOOM;

	bool mouse_flag;
};

class BattleBoardView
{
	friend class BattleBoardController;
  public:
    
    BattleBoardView(BBModel* model, BattleBoardController* controller);
    ~BattleBoardView();
  
    void Draw();
    void DrawGrid();
    void DrawBoundry();
    void DrawBackground();
    void DrawForeground();
    void DrawShips();
    void DrawMissles();
    void DrawSpecials();
    void DrawParticles();
//    void DrawShip(const ShipPlacement& ship);
//    void DrawWireframeShip(const ShipPlacement& ship, int R, int G, int B);

	void setGridDivision(int x, int y);

  private:
    BBModel* model;
	BattleBoardController* controller;

	bool showGrid;
    bool showBoundry;
    bool showBackground;
    bool showForeground;
    bool showShips;
    bool showMissles;
    bool showSpecials;
    bool showParticles;

	int x_div, y_div;
};
