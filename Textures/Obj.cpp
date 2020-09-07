//
// Created by Amado Garcia on 9/6/20.
//

#include "Obj.h"
#include <iostream>
#include <fstream>
#include <sstream>

Obj::Obj(string filename) {
    this->filename = filename;
}
void Obj::read()
{
    ifstream inFile;
    inFile.open("./" + filename);
    if (!inFile) {
        cerr << "Unable to open file";
        exit(1);   // call system to stop
    }
    string line;
    vector<string> data{};

    while (getline(inFile, line))
    {
        istringstream iss(line);
        data.push_back(line);
    }

    string prefix;
    string values;
    for(auto line : data)
    {
        int point = line.find(" ");
        prefix = line.substr(0, point);
        values = line.substr(point + 1, line.length() - 1);

        if(prefix == "v")
        {
            vector<double> vertex{};
            string value;
            for(auto v: values)
            {
                if(v == ' ')
                {

                    vertex.push_back(stof(value));
                    value = "";
                }
                else
                {
                    value = value + v;
                }
            }
            vertex.push_back(stof(value));
            vertices.push_back(vertex);
        }

        else if(prefix == "vt")
        {
            vector<double> tVertex{};
            string value{""};
            auto lol = values[0];
            for(auto v: values)
            {
                if(v == ' ')
                {
                    if(value == "")
                        continue;
                    tVertex.push_back(stof(value));
                    value = "";
                }
                else
                {
                    value = value + v;
                }
            }
            
            tVertex.push_back(stof(value));
            textureVertexes.push_back(tVertex);
        }

        else if(prefix == "f")
        {
            vector<string> face{};
            string value;
            for(auto  f: values)
            {
                if(f == ' ')
                {
                    face.push_back(value);
                    value = "";
                }
                else
                {
                    value = value + f;
                }

            }
            face.push_back(value);
            vector<int> facePosition1{};
            vector<int> facePosition2{};
            for(auto f : face)
            {
                int delimeter = f.find("/");
                string value = f.substr(0, delimeter);
                string tValue = f.substr(delimeter + 1, f.find("/") + 1);
                if(value !="")
                    facePosition1.push_back(stoi(value));
                if(tValue !="")
                    facePosition2.push_back(stoi(tValue));

            }
            faces.push_back(make_tuple(facePosition1, facePosition2));
        }
    }
}
vector<vector<double>> Obj::getVertices()
{
    return this->vertices;
}

vector<vector<double>> Obj::getTextureVertexes()
{
    return this->textureVertexes;
}
vector<tuple<vector<int>,vector<int>>> Obj::getFaces()
{
    return this->faces;
}






