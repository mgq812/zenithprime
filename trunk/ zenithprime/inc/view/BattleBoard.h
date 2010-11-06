#pragma once
#include <windows.h> // this is required for it to work on visual studio 2010
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <vector>
#include "BBModel.h"
#include "Matrix.h"

class BattleBoardView
{
  public:
    
    BattleBoardView(BBModel* model);
    ~BattleBoardView();
    
    float X, Y;
    float rotateX, rotateY;
    float zoom;
    void updateCamera();
    
    bool showGrid;
    bool showBoundry;
    bool showBackground;
    bool showForeground;
    bool showShips;
    bool showMissles;
    bool showSpecials;
    bool showParticles;
    
    int x_div, y_div;
  
    void Draw();
    void DrawGrid();
    void DrawBoundry();
    void DrawBackground();
    void DrawForeground();
    void DrawShips();
    void DrawMissles();
    void DrawSpecials();
    void DrawParticles();
    
    void DrawWireframeShip(const ShipPlacement& ship, int R, int G, int B);
  private:
    BBModel* model;
    
    float camera[3];
};

class BattleBoardController{
  public:
      BattleBoardView* view;
      BBModel* model;
      ShipPlacement* currentShip;
      
      
};

