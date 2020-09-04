//
// Created by Amado Garcia on 9/1/20.
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
            vector<float> vertex{};
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
            for(auto f : face)
            {
                int delimeter = f.find("/");
                string value = f.substr(0, delimeter);
                facePosition1.push_back(stoi(value));
            }
            faces.push_back(facePosition1);
        }
    }
    for(auto row: vertices)
    {
        for(auto column: row)
        {
            cout<<column<<" ";
        }
        cout<<"\n";
    }

    for(auto row: faces)
    {
        for(auto column: row)
        {
            cout<<column<<" ";
        }
        cout<<"\n";
    }
}
vector<vector<float>> Obj::getVertices()
{
    return this->vertices;
}
vector<vector<int>> Obj::getFaces()
{
    return this->faces;
}