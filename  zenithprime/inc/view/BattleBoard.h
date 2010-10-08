//#pgram once
#include <vector>

#define ShipID int*
#define MissleID int*
#define SpecialID int*
#define ParticleID int*

struct ShipPlacement
{
  float x;
  float y;
  ShipID ship;
};

struct MisslePlacement
{
  float x;
  float y;
  float z;
  MissleID missle;
};

struct SpecialPlacement
{
  float x;
  float y;
  float z;
  SpecialID special;
};

struct ParticlePlacement
{
  float x;
  float y;
  float z;
  ParticleID particle;
}

class BattleBoardModel
{
  public:
    std::vector<ShipPlacement> ships;
    std::vector<MisslePlacement> missles;
    std::vector<SpecialPlacement> special;
    std::vector<ParticlePlacement> particles;
    
    float width;
    float hieght;
};

class BattleBoardView
{
  public:
    
    BattleBoardView(BattleBoardModel* model);
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
    BattleBoardModel* model;
    
    float camera[3];
}

class BattleBoardController{
  public:
      BattleBoardView* view;
      BattleBoardModel* model;
      ShipPlacement* currentShip;
      
      
}

