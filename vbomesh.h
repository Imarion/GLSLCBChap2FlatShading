#ifndef VBOMESH_H
#define VBOMESH_H


#include <vector>
using std::vector;

#include <string>
using std::string;

#include <QVector2D>
#include <QVector3D>
#include <QVector4D>

class VBOMesh
{
private:   
    // Vertices
    vector <QVector3D> points;

    // Normals
    vector <QVector3D> normals;

    // Tex coords
    vector <QVector2D> texCoords;

    // Elements
    vector <unsigned int> faces;
    unsigned int nFaces;

    bool reCenterMesh, loadTex, genTang;

    void trimString( string & str );
    void storeVBO( const vector<QVector3D> & points,
                            const vector<QVector3D> & normals,
                            const vector<QVector2D> &texCoords,
                            const vector<QVector4D> &tangents,
                            const vector<unsigned int> &elements );
    void generateAveragedNormals(
            const vector<QVector3D> & points,
            vector<QVector3D> & normals,
            const vector<unsigned int> & faces );
    void generateTangents(
            const vector<QVector3D> & points,
            const vector<QVector3D> & normals,
            const vector<unsigned int> & faces,
            const vector<QVector2D> & texCoords,
            vector<QVector4D> & tangents);
    void center(vector<QVector3D> &);

public:
    VBOMesh( const char * fileName, bool reCenterMesh = false, bool loadTc = false, bool genTangents = false );

    void render() const;

    void loadOBJ( const char * fileName );

    QVector3D *getv();
    int    getnVerts();
    QVector3D *getn();
    QVector2D *gettc();
    unsigned int *getfaces();
    unsigned int    getnFaces();
};

#endif // VBOMESH_H
