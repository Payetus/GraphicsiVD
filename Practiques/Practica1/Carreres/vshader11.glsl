#if __VERSION__<130
#define IN attribute
#define OUT varying
#else
#define IN in
#define OUT out
#endif


IN vec4 vPosition;
IN vec4 vColor;

OUT vec4 color;
//Enviar la matriu a la GPU
//Aixo es fa desde camera
//Es te que afegir la matriu
//uniform mat4 model.view;
void main() 
{
  //Es te que multiplicar  Uniform
  gl_Position = vPosition;
  color = vColor;
} 
