#pragma once
#define NOMINMAX
#include <windows.h> // this is required for it to work on visual studio 2010
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <vector>
#include "BBModel.h"
#include "Matrix.h"
#include "Mouse.h"
#include "Cursor.h"


class BattleBoardView;
class BattleBoardGUIFacade;

class BattleBoardController : public MouseListener{
	
	friend class BattleBoardView;
  public:
      //BattleBoardView* view;
      BBModel* model;

      BattleBoardController(BBModel* model);
   

    void Update();

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

	void setViewport(int x, int y, int width, int height, float angle);
	void setFacade(BattleBoardGUIFacade* facade);

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

	struct BattleViewport{
	int x;
	int y;
	int width;
	int height;
	float angle;
	};

	BattleViewport BBInfo;

	BattleBoardGUIFacade* facade;

	static const int M_MOVED = 0;
	static const int M_DRAGGED = 1;
	static const int M_PRESSED = 2;
	static const int M_RELEASED = 3;
	static const int M_CLICKED = 4;
	static const int M_DCLICKED = 5;

	void callFacade(int targetX, int targetY, int buttons, int protocal);
	void callPan(int targetX, int targetY);
};

class BattleBoardView
{
	friend class BattleBoardController;
  public:
    
    BattleBoardView(BBModel* model, BattleBoardController* controller);
    ~BattleBoardView();
  
    void Draw();

//    void DrawShip(const ShipPlacement& ship);
//    void DrawWireframeShip(const ShipPlacement& ship, int R, int G, int B);

	void setGridDivision(int x, int y);
	void setViewport(int x, int y, int width, int height, float angle);
	void Update();
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
	bool showSelected;
	bool showCursor;
	bool showGhosts;
	bool showAnchor;

	void DrawGrid();
    void DrawBoundry();
    void DrawBackground();
    void DrawForeground();
    void DrawShips();
    void DrawMissles();
    void DrawSpecials();
    void DrawParticles();
	void DrawSelected();
	void DrawCursor();
	void DrawGhosts();
	void DrawAnchor();

	void DrawShip(BBShipModel* shipModel);
	void DrawWireframeShip(BBShipModel* shipModel);
	void DrawSelectedShip(BBShipModel* shipModel);
	void DrawHighlightedShip(BBShipModel* shipModel);

	void setTransforms(BBShipModel* shipModel);
	void clearTransforms();
	int x_div, y_div;

	int gridCache;
};

class BattleBoardGUIFacade
{
public:
	virtual void mouseMoved(float originX, float originY, float originZ, float directionX, float directionY, float directionZ)=0;
	virtual void mouseDragged(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons)=0;
	virtual void mousePressed(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons)=0;
	virtual void mouseReleased(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int buttons)=0;
	virtual void mouseClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button)=0;
	virtual void mouseDoubleClicked(float originX, float originY, float originZ, float directionX, float directionY, float directionZ, int button)=0;
	virtual void Update()=0;
};

