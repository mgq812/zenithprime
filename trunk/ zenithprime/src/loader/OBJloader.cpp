#include "OBJloader.h"
#include <vector>
#include "VectorMath.h"
#include "Face.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
	string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

OBJloader::OBJloader(void)
{
}

OBJloader::~OBJloader(void)
{
}
OBJModel* OBJloader::loadModelFromFile(string fileName)
{
	std::ifstream readFile;
	readFile.open(fileName.c_str());

	if(!readFile.is_open()){
		std::cout<<"ERROR: OBJ File Not Found";
		return NULL;
	}

	std::string objData = "";
	while(!readFile.eof()){
		char temp[256];
		readFile.getline(temp, 256);
		
		objData+= temp;
		objData+="\n";
	}

	readFile.close();

	//std::cout<<"File Found:\n";
	//std::cout<<objData;

	return OBJloader::loadModel(objData);
}
OBJModel* OBJloader::loadModel(string objData){
	vector<string> tokenLines;

	OBJModel* currentModel = new OBJModel();
	currentModel->smallestX = 10,000;
	currentModel->smallestY = 10,000;
	currentModel->smallestZ = 10,000;
	currentModel->largestX = -10,000;
	currentModel->largestY = -10,000;
	currentModel->largestZ = -10,000;

	Tokenize(objData, tokenLines, "\n");
	//cout<<tokenLines.size()<<endl;
	USEMTL currentmaterial;
	currentmaterial.startQuad = -1;
	currentmaterial.startTri = -1;
	
	//Look for Verticies
	for(unsigned int line = 0; line< tokenLines.size(); line++)
	{
		vector<string> tokens;
		
		Tokenize(tokenLines[line], tokens);

		if(tokens.size()<1 || tokens[0].compare("#")==0) continue;
		//cout<<"\t"<<tokens[0]<<"=="<<"v ? "<< tokens[0].compare("v") <<endl;
		//Material Library
		if(tokens[0].compare("mtllib")==0)
		{
		  currentModel->mtllib = tokens[1];
		}
		
		//Vertex
		else if(tokens[0].compare("v")==0){
			Vector3 temp;

			temp.x = (float)strtod(tokens[1].c_str(),NULL);
			temp.y = (float)strtod(tokens[2].c_str(),NULL);
			temp.z = (float)strtod(tokens[3].c_str(),NULL);

			if (temp.x < currentModel->smallestX)
				currentModel->smallestX = temp.x;
			if (temp.y < currentModel->smallestY)
				currentModel->smallestY = temp.y;
			if (temp.z < currentModel->smallestZ)
				currentModel->smallestZ = temp.z;

			if (temp.x > currentModel->largestX)
				currentModel->largestX = temp.x;
			if (temp.y > currentModel->largestY)
				currentModel->largestY = temp.y;
			if (temp.z > currentModel->largestZ)
				currentModel->largestZ = temp.z;

			currentModel->vertexXYZ.push_back(temp);
		}
		//Texture
		else if(tokens[0].compare("vt")==0)
		{
			
			Vector2 temp;
			//stringstream ss;
			//ss << tokens[1].c_str();
			temp.x = (float)atof(tokens[1].c_str());
			temp.y = (float)atof(tokens[2].c_str());
			//cout<<"ENTRY: "<<temp.x<<","<<temp.y<<" : "<< tokens[1]<< "," << tokens[2]<<endl;
			currentModel->textureUV.push_back(temp);
		}
		//Normals
		else if(tokens[0].compare("vn")==0)
		{
			Vector3 temp;

			temp.x = (float)strtod(tokens[1].c_str(),NULL);
			temp.y = (float)strtod(tokens[2].c_str(),NULL);
			temp.z = (float)strtod(tokens[3].c_str(),NULL);

			currentModel->normal.push_back(temp);
		}
		
		//Use Material
		else if (tokens[0].compare("usemtl")==0){
		  if(currentmaterial.startQuad != -1 &&  currentmaterial.startTri != -1){
		    currentmaterial.endQuad = currentModel->Quads.size()-1;
		    currentmaterial.endTri = currentModel->Triangles.size()-1;
		    currentModel->Materials.push_back(currentmaterial);
		  }
		  
		  currentmaterial.var = tokens[1];
		  currentmaterial.startQuad = currentModel->Quads.size();
		  currentmaterial.startTri = currentModel->Triangles.size();
		}
		
		//Faces
		else if(tokens[0].compare("f")==0)
		{
			//Get the number of verticies
			int t = tokens.size()-1;
			
			// t = 3, triangls, t=4, Quads
			vector<int3> cords;
			
			//Load each vertex
			for(int i = 0 ; i<t; i++)
			{
				int3 cCord;
			  //Look for first "/"
			      string::size_type pos1 = tokens[i+1].find_first_of("/", 0);
			      
			      // Only vertex info provided
			      if(pos1 == string::npos)
			      {
				      cCord.x = atoi(tokens[i+1].c_str());
				      cCord.z = cCord.y = -1;
					  cords.push_back(cCord);
				      continue;
			      }
			      
			      // Load vertex info
			      cCord.x = atoi(tokens[i+1].substr(0, pos1).c_str());
			      
			      //Look for the next "/" to get vertex/ TEXTURE /normal
			      string::size_type pos2 = tokens[i+1].find_first_of("/", pos1+1);
			      
			      //No texture cordinates "vertex//normal
			      if(pos2 - pos1<2)
					  cCord.y = -1;
			      
			      else{
				      //Load Texture Info
				      cCord.y = atoi(tokens[i+1].substr(pos1+1, pos2 - pos1-1).c_str());
				      
				      //If there wasn't another "/" than there is only vertex and texutre info "vertex/texture"
				      if(pos2 == string::npos){
					      cCord.z = -1;
						  cords.push_back(cCord);
					      continue;
				      }
			      }
			      
			      //Load the normal Info
			      cCord.z = atoi(tokens[i+1].substr(pos2+1, string::npos - pos2-1).c_str());
				  cords.push_back(cCord);
			}
			if(t==1)
			{
				currentModel->Points.push_back(cords[0]);
			}
			else if(t==2)
			{
				Line l;
				l.Start = cords[0];
				l.End = cords[1];

				currentModel->Lines.push_back(l);
			}
			else if(t==3)
			{
			  Tri face;
			  face.T1 = cords[0];
			  face.T2 = cords[1];
			  face.T3 = cords[2];
			  
			  currentModel->Triangles.push_back(face);
			}
			
			else if(t==4)
			{
			  Quad face;
			  face.T1 = cords[0];
			  face.T2 = cords[1];
			  face.T3 = cords[2];
			  face.T4 = cords[3];
			  
			  currentModel->Quads.push_back(face);
			}
			else
			{
				PolygonFace face;
				face.T = cords;
				
				currentModel->Polygons.push_back(face);
			}

		}
	}

	return currentModel;
}

void OBJloader::PrintModel(OBJModel& model){
	cout<<"Model "<<model.objectName<<endl;
	cout<<"Vertex["<<model.vertexXYZ.size()<<"]:"<<endl;
	//cout<<model.vertexXYZ.size()<<endl;

	vector<Vector3>::iterator it;

	for(it=model.vertexXYZ.begin(); it != model.vertexXYZ.end(); it++){
		cout<<"v "<<(*it).x<<" "<<(*it).y<<" "<<(*it).z<<endl;
	}
	vector<Vector2>::iterator it2;
	cout<<"Texture["<<model.textureUV.size()<<"]:"<<endl;
	for(it2=model.textureUV.begin(); it2 != model.textureUV.end(); it2++){
		cout<<"vt "<<(*it2).x<<" "<<(*it2).y<<endl;
	}

	vector<Tri>::iterator it3;
	cout<<"Face[Triangles]["<<model.Triangles.size()<<"]:"<<endl;
	for(it3=model.Triangles.begin(); it3 != model.Triangles.end(); it3++){
		cout<<"f ";
		cout<< (*it3).T1.x<<"/"<<(*it3).T1.y<<"/"<<(*it3).T1.z<<" ";
		cout<< (*it3).T2.x<<"/"<<(*it3).T2.y<<"/"<<(*it3).T2.z<<" ";
		cout<< (*it3).T3.x<<"/"<<(*it3).T3.y<<"/"<<(*it3).T3.z<<" ";
		cout<<endl;
	}

	vector<Quad>::iterator it4;
	cout<<"Face[Quads]["<<model.Quads.size()<<"]:"<<endl;
	for(it4=model.Quads.begin(); it4 != model.Quads.end(); it4++){
		cout<<"f ";
		cout<< (*it4).T1.x<<"/"<<(*it4).T1.y<<"/"<<(*it4).T1.z<<" ";
		cout<< (*it4).T2.x<<"/"<<(*it4).T2.y<<"/"<<(*it4).T2.z<<" ";
		cout<< (*it4).T3.x<<"/"<<(*it4).T3.y<<"/"<<(*it4).T3.z<<" ";
		cout<< (*it4).T4.x<<"/"<<(*it4).T4.y<<"/"<<(*it4).T4.z<<" ";
		cout<<endl;
	}

	
}


GLuint OBJloader::CacheOBJModel(OBJModel& model){
	GLuint cacheModel = glGenLists(1);

	glNewList(cacheModel,GL_COMPILE);
	glColor3f(1,1,1);
	float diffReflection[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, diffReflection);
	float specReflection[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);
	//GLfloat mShininess[] = {4}; //set the shininess of the material
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
	glBegin(GL_TRIANGLES);
	for(unsigned int i = 0; i< model.Triangles.size(); i++)
	{

		Vector3 tempNorm = model.normal[model.Triangles[i].T1.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		Vector2 tempUV = model.textureUV[model.Triangles[i].T1.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		Vector3 tempVert = model.vertexXYZ[model.Triangles[i].T1.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		tempNorm = model.normal[model.Triangles[i].T2.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		tempUV = model.textureUV[model.Triangles[i].T2.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		tempVert = model.vertexXYZ[model.Triangles[i].T2.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		tempNorm = model.normal[model.Triangles[i].T3.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		tempUV = model.textureUV[model.Triangles[i].T3.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		tempVert = model.vertexXYZ[model.Triangles[i].T3.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		
	}
	glEnd();

	//Draw Quads
	glBegin(GL_QUADS);
	for(unsigned int i = 0; i< model.Quads.size(); i++)
	{
		Vector3 tempNorm = model.normal[model.Quads[i].T1.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		Vector2 tempUV = model.textureUV[model.Quads[i].T1.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		Vector3 tempVert = model.vertexXYZ[model.Quads[i].T1.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		tempNorm = model.normal[model.Quads[i].T2.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		tempUV = model.textureUV[model.Quads[i].T2.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		tempVert = model.vertexXYZ[model.Quads[i].T2.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		tempNorm = model.normal[model.Quads[i].T3.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		tempUV = model.textureUV[model.Quads[i].T3.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		tempVert = model.vertexXYZ[model.Quads[i].T3.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);

		tempNorm = model.normal[model.Quads[i].T4.z -1];
		glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
		tempUV = model.textureUV[model.Quads[i].T4.y -1];
		glTexCoord2f(tempUV.x, tempUV.y);
		tempVert = model.vertexXYZ[model.Quads[i].T4.x-1];
		glVertex3f( tempVert.x, tempVert.y, tempVert.z);
	}
	glEnd();

	for(unsigned int i = 0 ; i < model.Polygons.size(); i++)
	{
		PolygonFace face = model.Polygons[i];	
		glBegin(GL_POLYGON);
		for(unsigned int j = 0; j < face.T.size(); j++)
		{
			Vector3 tempNorm = model.normal[face.T[j].z -1];
			glNormal3f(tempNorm.x, tempNorm.y, tempNorm.z);
			Vector2 tempUV = model.textureUV[face.T[j].y -1];
			glTexCoord2f(tempUV.x, tempUV.y);
			Vector3 tempVert = model.vertexXYZ[face.T[j].x-1];
			glVertex3f( tempVert.x, tempVert.y, tempVert.z);
		}
		glEnd();
	}

	glEndList();

	return cacheModel;
}