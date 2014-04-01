#include "terra.h"

Terra::Terra(float x,float z,float y):Objecte(6){
    vertexs.push_back(point4(x/(-2.0),y,-z/2,1.0));
    vertexs.push_back(point4(x/(2.0),y,-z/2,1.0));
    vertexs.push_back(point4(x/(2.0),y,z/2,1.0));
    vertexs.push_back(point4(x/(-2.0),y,z/2,1.0));
    std::cout<<"arriba creador de Terra"<<endl;
    make();
}
void Terra::quad( int a, int b, int c, int d )
{
    static vec3  base_colors[] = {
        vec3( 0.0, 1.0, 0.0 ),
        vec3( 0.0, 1.0, 0.0 ),
        vec3( 0.0, 1.0, 0.0 ),
        vec3( 1.0, 1.0, 0.0 )
    };
    colors[Index] = base_colors[a]; points[Index] = vertexs[a]; Index++;
    colors[Index] = base_colors[b]; points[Index] = vertexs[b]; Index++;
    colors[Index] = base_colors[c]; points[Index] = vertexs[c]; Index++;
    colors[Index] = base_colors[a]; points[Index] = vertexs[a]; Index++;
    colors[Index] = base_colors[c]; points[Index] = vertexs[c]; Index++;
    colors[Index] = base_colors[d]; points[Index] = vertexs[d]; Index++;
}
void Terra::make(){
    std::cout<<"Estic en el make de Terra\n";
    // generacio de la geometria dels triangles per a visualitzar-lo
    Index = 0;
    quad( 1, 0, 3, 2 );
}
